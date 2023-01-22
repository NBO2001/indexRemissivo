#include "typeList.h"
#include "stdio.h"
#include "stdlib.h"

struct typeNode{
    struct typeNode* prox;
    void* info;
};

struct typeList{
    typeNode* prim;
    typeCompare compare;
};

typeList* createList(typeCompare compare){
    typeList* list = malloc(sizeof(typeList));
    list->prim = NULL;
    list->compare = compare;
    return list;
}

void insertList(typeList* list, void* elem){
    typeNode* aux = malloc(sizeof(typeNode));
    aux->info = elem;
    aux->prox = list->prim;
    list->prim = aux;
}

void removeList(typeList* list, void* info){
    typeNode* aux = list->prim;
    typeNode* tmp = aux;
    while(aux!=NULL && (list->compare(info, aux->info)!=0)){    
        tmp = aux;
        aux=aux->prox;
    }
    if(aux==tmp){
        list->prim = aux ->prox;
        free(tmp);
    }else{
        tmp->prox = aux->prox;
    }
    free(aux);

}

void* searchList(typeList* list, void* info){
    typeNode* aux = list->prim;
    while(aux!=NULL && (list->compare(info, aux->info)!=0)){
        aux=aux->prox;
    }
    

}