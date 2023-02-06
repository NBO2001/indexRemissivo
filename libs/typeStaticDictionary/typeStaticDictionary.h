#ifndef STATIC_DIC
#define STATIC_DIC
#include "../../libs/analyticalData/analyticalData.h"

typedef struct inDic{

    int tam;
    int chargeFactor;
    short fixedChargeFactor;

}inDic;

#define createStaticDic(...) _createStaticDic((inDic){.tam=2,.fixedChargeFactor=0,.chargeFactor=1,__VA_ARGS__})

typedef struct typeStaticDictionary typeStaticDictionary;

typeStaticDictionary* _createStaticDic(inDic in);
void chargeStaticDic(typeStaticDictionary* staticDic, void* value, unsigned int sizeValue);
void* searchStaticDic(typeStaticDictionary* staticDic, void* key, unsigned int sizeKey);

analyticalData getAnalicalDataStactDic(typeStaticDictionary* staticDic);

#endif