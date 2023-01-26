#ifndef STATIC_DIC
#define STATIC_DIC

typedef struct typeStaticDictionary typeStaticDictionary;



typeStaticDictionary* createStaticDic(int tam);
void chargeStaticDic(typeStaticDictionary* staticDic, void* value, unsigned int sizeValue);
void* searchStaticDic(typeStaticDictionary* staticDic, void* key, unsigned int sizeKey);



#endif