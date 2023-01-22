#ifndef TYPEDYNAMICDICTIONARY_H
#define TYPEDYNAMICDICTIONARY_H

typedef struct typeDynamicDictionary typeDynamicDictionary; 

typeDynamicDictionary * newDynamicDictionary(unsigned int len);
void insertDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize, void * value, unsigned int sizeValue);
void * searchDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);
void removeDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize);

#endif