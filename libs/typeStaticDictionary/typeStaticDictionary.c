#include "stdio.h"
#include "stdlib.h"
#include "typeStaticDictionary.h"
#include "../../libs/typeTableHash/typeTableHash.h"

struct typeStaticDictionary{
    
    typeTableHash * table;
    unsigned int tam;
};

typeStaticDictionary* createStaticDic(int tam){

    typeStaticDictionary * dictionary = malloc(sizeof(typeStaticDictionary));

    dictionary->table = createTableHash(.tam=tam);
    dictionary->tam = tam;

    return dictionary;
}

void chargeStaticDic(typeStaticDictionary* staticDic, void* value, unsigned int sizeValue){
    insertTable(staticDic->table,value, sizeValue,value,sizeValue);
}

void* searchStaticDic(typeStaticDictionary* staticDic, void* key, unsigned int sizeKey){
   return seachTable(staticDic->table,key, sizeKey);
}

analyticalData getAnalicalDataStactDic(typeStaticDictionary* staticDic){ return getAnalicalData(staticDic->table); }
