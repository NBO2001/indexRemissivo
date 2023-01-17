#ifndef STATIC_DIC
#define STATIC_DIC

typedef struct typeStaticDictionary typeStaticDictionary;

typedef int (*typeCompare)(void*, void*);

typeStaticDictionary* createStaticDic(int tam, typeCompare compare);
void chargeStaticDic(typeStaticDictionary* staticDic, void* value);
void* searchStaticDic(typeStaticDictionary* staticDic, void* key);



#endif