#ifndef TYPEDYNAMICDICTIONARY_H
#define TYPEDYNAMICDICTIONARY_H

typedef struct typeDynamicDictionary typeDynamicDictionary; 

typedef struct{
    unsigned int tam;
} initialValuesDict;

#define newDynamicDictionary(...) _newDynamicDictionary((initialValuesDict){.tam = 2, __VA_ARGS__})

typeDynamicDictionary * _newDynamicDictionary(initialValuesDict in);

void insertDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize, void * value, unsigned int sizeValue);
void * searchDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);
void removeDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);

#endif