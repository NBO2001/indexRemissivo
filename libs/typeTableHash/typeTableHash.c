#include "typeTableHash.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <math.h>
#include "../../libs/typeLinkedList/linked_list.h"
#define SEED    0x392


struct typeTableHash{
    typeList* *lists;
    unsigned int totalElements;
    unsigned int len;
    unsigned int chargeFactor;
    unsigned int biggerList;

    // Statistical parameters
    unsigned int totalReHashingRealized;
    unsigned int seachTotal;
    double totalCmp;
};

typedef struct typeCharge typeCharge;
short _analyzeLoadFactor(typeTableHash * thash);

struct typeCharge{
    void * key;
    void * value;
    unsigned int sizeKey;
    unsigned int sizeValue;
};

int cmp(void* a,void*b){
    
    typeCharge* aa = a;
    typeCharge* bb = b;

    return memcmp(aa->key,bb->key,aa->sizeKey);
}

static unsigned int primo_proximo(int num){
  short encontrou = 0;
  while(!encontrou){
    int i=2;
    while( (i<num) && ( (num%i) != 0) ){
      i++;
    }
    if (i==num){
      encontrou=1;
    }else{
      num+=1;
    }
  }
  return num;
}

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{   
    
    // Fonte: https://sites.google.com/site/murmurhash/
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array
    
	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
} 

static unsigned int hashing(typeTableHash* thash,unsigned int keySize ,void* key){
  return (MurmurHash2(key,keySize,SEED) % thash->len);
}

void _executeReHashing(typeTableHash* thash){

  unsigned int newTam = primo_proximo(thash->totalElements + ( 0.5 * thash->totalElements ));
  unsigned int newChargeFactor = (unsigned int) log2(thash->totalElements);

  newChargeFactor = newChargeFactor > 2? newChargeFactor - 1: newChargeFactor;

  typeTableHash * newTable = createTableHash(.factorCharge=newChargeFactor,.tam=newTam);

  typeCharge * tmpCharge;

  newTable->totalElements = thash->totalElements;
  newTable->totalReHashingRealized = thash->totalReHashingRealized+1;
  newTable->totalCmp = thash->totalCmp;
  newTable->seachTotal = thash->seachTotal;

  unsigned int indexToList;
  int tamList;

  for(int i=0; i < thash->len; i++){

    tmpCharge = remove_start(thash->lists[i]);
    
    while (tmpCharge){
      
      indexToList = hashing(newTable,tmpCharge->sizeKey,tmpCharge->key);

      insert_start(newTable->lists[indexToList], tmpCharge);

      tamList = getTamList(newTable->lists[indexToList]);

      if(tamList > newTable->biggerList) newTable->biggerList = tamList;

      tmpCharge = remove_start(thash->lists[i]);

    }

    deleteList(thash->lists[i]);

  }

  *thash = *newTable;

}

typeTableHash* _createTableHash(elementTableHash in){

    typeTableHash* thash = malloc(sizeof(typeTableHash));

    thash->len = in.tam;
    thash->totalElements = 0;
    thash->chargeFactor = in.factorCharge;
    thash->biggerList = 0;
    thash->totalReHashingRealized = 0;
    thash->seachTotal = 0;
    thash->totalCmp = 0;

    thash->lists = malloc(sizeof(typeList*)*thash->len);

    for(int i=0; i <  thash->len; i++) thash->lists[i] = newLinkedList(cmp,sizeof(typeCharge));
    
    return thash;

}

short _analyzeLoadFactor(typeTableHash * thash){

  int s_x=0, x;

  for(int i=0; i < thash->len; i++){

    x = getTamList(thash->lists[i]);
    s_x += x*x;

  }
  
  double C = (double)s_x/(double)thash->totalElements - thash->chargeFactor;

  if (C > 1.0){
    return 1;
  }else{
    return 0;
  }

}


void insertTable(typeTableHash * thash, void * key,unsigned int sizeKey, void * value,unsigned int sizeValue){

    typeCharge* charge = malloc(sizeof(typeCharge));

    charge->key = malloc(sizeKey);
    charge->value = malloc(sizeValue);
    charge->sizeKey = sizeKey;
    charge->sizeValue = sizeValue;

    memcpy(charge->key, key, sizeKey);
    memcpy(charge->value, value, sizeValue);

    unsigned int indexToList = hashing(thash,sizeKey,key);

    insert_start(thash->lists[indexToList], charge);

    thash->totalElements++;

    int tamList = getTamList(thash->lists[indexToList]);

    if(tamList > thash->biggerList) thash->biggerList = tamList;
   
    if(( (thash->biggerList > thash->chargeFactor ) ) || _analyzeLoadFactor(thash)) _executeReHashing(thash);
    
}

void* seachTable(typeTableHash * thash, void * key,unsigned int sizeKey){

    typeCharge* charge = calloc(sizeof(typeCharge),1);
    charge->key = key;
    charge->sizeKey = sizeKey;
    
    unsigned int index = hashing(thash,sizeKey,key);

    typeCharge* aux = seach_in_list(thash->lists[index],charge);

    thash->totalCmp += getTotalComparations(thash->lists[index]);
    thash->seachTotal++;

    free(charge);

    if(aux) return aux->value;
    else return NULL;

}

void* removeTable(typeTableHash * thash, void * key,unsigned int sizeKey){

    typeCharge * charge = remove_with_key(thash->lists[hashing(thash,sizeKey,key)],key);

    void * value = malloc(charge->sizeValue);
    memcpy(value,charge->value, charge->sizeValue);
    
    free(charge->key);
    free(charge->value);
    free(charge);

    return value;
}

analyticalData getAnalicalData(typeTableHash * thash){

  return (analyticalData){.tam=thash->len,
  .factorCharge=thash->chargeFactor,
  .reHashingRealizade = thash->totalReHashingRealized,
  .totalElements=thash->totalElements,
  .biggerLinkedList=thash->biggerList,
  .seachTotal=thash->seachTotal,
  .totalCmp=thash->totalCmp};
}