#ifndef T_TABLE
#define T_TABLE
#include "../../libs/analyticalData/analyticalData.h"

typedef struct {
    unsigned int tam;
    unsigned int factorCharge;
}elementTableHash;

#define createTableHash(...) _createTableHash((elementTableHash){.tam=2,.factorCharge=1,__VA_ARGS__})
typedef struct typeTableHash typeTableHash;

typeTableHash* _createTableHash(elementTableHash in);

void insertTable(typeTableHash * thash, void * key,unsigned int sizeKey, void * value,unsigned int sizeValue);
void* seachTable(typeTableHash * thash, void * key,unsigned int sizeKey);
void* removeTable(typeTableHash * thash, void * key,unsigned int sizeKey);

analyticalData getAnalicalData(typeTableHash * thash);

#endif