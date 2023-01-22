#ifndef MERGESORT_H
#define MERGESORT_H

typedef int (*compare)(void*, void*);

void merge(void* *els, int tam, compare cmp);

#endif