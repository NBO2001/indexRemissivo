#ifndef T_TABLE
#define T_TABLE

typedef struct typeTableHash typeTableHash;

typeTableHash* createTableHash(unsigned int len);

void insertTable(typeTableHash * thash, void * key,unsigned int sizeKey, void * value,unsigned int sizeValue);
void* seachTable(typeTableHash * thash, void * key,unsigned int sizeKey);
void* removeTable(typeTableHash * thash, void * key,unsigned int sizeKey);

#endif