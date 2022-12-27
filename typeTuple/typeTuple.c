#include <string.h>
#include "typeTuple.h"
#include "stdlib.h"

struct typeTuple
{
    int sizeF;
    int sizeS;
    void * elementF;
    void * elementS;
};


typeTuple *  create(int sizeF, void * fist, int sizeS, void * secund){

    typeTuple * te = malloc(sizeof(typeTuple));

    te->sizeF = sizeF;
    te->sizeS = sizeS;

    te->elementF = malloc(te->sizeF);
    te->elementS = malloc(te->sizeS);

    memcpy(te->elementF, fist, te->sizeF);
    memcpy(te->elementS, secund, te->sizeS);

    return te;

}
void * fist(typeTuple * tp){

    void * tmp = malloc(tp->sizeF);
    memcpy(tmp, tp->elementF, tp->sizeF);
    return tmp;

}
void * secund(typeTuple * tp){

    void * tmp = malloc(tp->sizeS);
    memcpy(tmp, tp->elementS, tp->sizeS);
    return tmp;


}