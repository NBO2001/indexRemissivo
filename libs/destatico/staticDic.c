#include "stdio.h"
#include "stdlib.h"
#include "staticDic.h"

struct typeStaticDic{
    int tam;
    int occupation;
    typeCompare compare;
    void* *values;
};

typeStaticDic* createStaticDic(int tam, typeCompare compare){
    typeStaticDic* staticDic = malloc(sizeof(typeStaticDic));
    staticDic->tam = tam;
    staticDic->occupation=0;
    staticDic->compare = compare;
    staticDic->values = calloc(tam, sizeof(void*));

    return staticDic;
}

void chargeStaticDic(typeStaticDic* staticDic, void* value){
    staticDic->values[staticDic->occupation]=value;
    staticDic->occupation++;
}

void* searchStaticDic(typeStaticDic* staticDic, void* key){
    int inicio=0, fim=staticDic->occupation-1, meio, status=0;
    void* value;
    while((!status) && (inicio<=fim)){
        meio=(inicio+fim)/2;
        
        if(staticDic->compare(staticDic->values[meio],key)>0){
            fim = meio-1;
        }
        else if(staticDic->compare(staticDic->values[meio],key)<0){            
            inicio=meio+1;
        }
        else{
            status = 1;
            return staticDic->values[meio];
        }

    }
    return NULL;
}

