#include <stdlib.h>
#include "../../libs/typeDynamicDictionary/typeDynamicDictionary.h"
#include "../../libs/typeTableHash/typeTableHash.h"

struct typeDynamicDictionary{

    typeTableHash * table;
    unsigned int len;

};

typeDynamicDictionary * newDynamicDictionary(unsigned int len){
    

    typeDynamicDictionary * dictionary = malloc(sizeof(typeDynamicDictionary));

    dictionary->table = createTableHash(len);
    dictionary->len = len;

    return dictionary;

}
void insertDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize, void * value, unsigned int sizeValue){

    insertTable(dictionary->table,key, keySize,value,sizeValue);

}
void * searchDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize){
    return seachTable(dictionary->table,key, keySize);
}
void removeDynamicDictionary(typeDynamicDictionary * dictionary, void * key,unsigned int keySize){
    void * tmp = removeTable(dictionary->table,key, keySize);
    free(tmp);
}