#include "typeTableHash.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../../libs/typeLinkedList/linked_list.h"
#define SEED    0x392


struct typeTableHash{
    typeList* *lists;
    unsigned int len;
};

typedef struct typeCharge typeCharge;

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

typeTableHash* createTableHash(unsigned int len){

    typeTableHash* thash = malloc(sizeof(typeTableHash));

    thash->len = len;
    thash->lists = malloc(sizeof(typeList*)*thash->len);

    for(int i=0; i <  thash->len; i++){
        thash->lists[i] = newLinkedList(cmp,sizeof(typeCharge));
    }
    
    return thash;

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

unsigned int funchash ( const void * key, int len, unsigned int seed ){

    unsigned int acumulador = 0;

    const char * keys = key;
    int i = 0;
    while (keys[i])
    {
        acumulador += (keys[i]);
        i++;
    }

    return acumulador;
}

static unsigned int hashing(typeTableHash* thash,unsigned int keySize ,void* key){
  return (MurmurHash2(key,keySize,SEED) % thash->len);
}

void insertTable(typeTableHash * thash, void * key,unsigned int sizeKey, void * value,unsigned int sizeValue){

    typeCharge* charge = malloc(sizeof(typeCharge));
    charge->key = malloc(sizeKey);
    charge->value = malloc(sizeValue);
    charge->sizeKey = sizeKey;
    charge->sizeValue = sizeValue;

    memcpy(charge->key, key, sizeKey);
    memcpy(charge->value, value, sizeValue);

    insert_start(thash->lists[hashing(thash,sizeKey,key)], charge);

}

void* seachTable(typeTableHash * thash, void * key,unsigned int sizeKey){

    typeCharge* charge = calloc(sizeof(typeCharge),1);
    charge->key = key;
    charge->sizeKey = sizeKey;

    typeCharge* aux = seach_in_list(thash->lists[hashing(thash,sizeKey,key)],charge);
    
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