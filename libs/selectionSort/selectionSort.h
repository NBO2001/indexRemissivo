#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

typedef int (*comparator)(void*,void*);

void selectSort(void * elemts, int tam,unsigned int sizeElement, comparator cmp);

#endif