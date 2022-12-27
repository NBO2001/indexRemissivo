#ifndef TYPETUPLE_H
#define TYPETUPLE_H

typedef struct typeTuple typeTuple;

typeTuple * create(int sizeF, void * fist, int sizeS, void * secund);
void * fist(typeTuple * tp);
void * secund(typeTuple * tp);

#endif