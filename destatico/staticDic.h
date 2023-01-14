#ifndef STATIC_DIC
#define STATIC_DIC

typedef struct typeStaticDic typeStaticDic;

typedef int (*typeCompare)(void*, void*);

typeStaticDic* createStaticDic(int tam, typeCompare compare);
void chargeStaticDic(typeStaticDic* staticDic, void* value);
void* searchStaticDic(typeStaticDic* staticDic, void* key);



#endif