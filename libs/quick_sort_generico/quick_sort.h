#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

typedef int (*comparator)(void*, void*);


void sort(void* vet, int n, int sizeEl, comparator cmp);


#endif