#ifndef TYPEDYNAMICDICTIONARY_H
#define TYPEDYNAMICDICTIONARY_H
#include "../../libs/analyticalData/analyticalData.h"

typedef struct typeDynamicDictionary typeDynamicDictionary; 

typedef struct{
    unsigned int tam;
    unsigned int factorCharge;
    short fixedChargeFactor;
} initialValuesDict;

#define newDynamicDictionary(...) _newDynamicDictionary((initialValuesDict){.tam = 2,.fixedChargeFactor=0, __VA_ARGS__})

typeDynamicDictionary * _newDynamicDictionary(initialValuesDict in);

void insertDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize, void * value, unsigned int sizeValue);
void * searchDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);
void removeDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);
void deleteDictionary(typeDynamicDictionary * dictionary);

analyticalData getAnalicalDataDynanDic(typeDynamicDictionary* dictionary);

#endif