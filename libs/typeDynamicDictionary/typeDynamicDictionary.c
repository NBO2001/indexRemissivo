#include <stdlib.h>
#include <math.h>
#include "../../libs/typeDynamicDictionary/typeDynamicDictionary.h"
#include "../../libs/typeTableHash/typeTableHash.h"

struct typeDynamicDictionary{

    typeTableHash * table;
    unsigned int len;

};

typeDynamicDictionary * _newDynamicDictionary(initialValuesDict in){
    

    typeDynamicDictionary * dictionary = malloc(sizeof(typeDynamicDictionary));

    dictionary->len = in.tam;
    unsigned int log = (unsigned int) log2(dictionary->len);

    dictionary->table = createTableHash(.tam=dictionary->len,.factorCharge=log);

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

analyticalData getAnalicalDataDynanDic(typeDynamicDictionary* dictionary){ return getAnalicalData(dictionary->table); }