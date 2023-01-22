#ifndef T_LISTA
#define T_LISTA

typedef struct typeList typeList;
typedef struct typeNode typeNode;
typedef int (*typeCompare)(void*, void*);

typeList* createList();
void insertList();
void removeList();
void* searchList();


#endif