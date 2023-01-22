#ifndef TYPEINDEXR_H
#define TYPEINDEXR_H


typedef struct typeIndex typeIndex;
typedef struct typeElementIndex typeElementIndex;
typedef struct typePagination typePagination;

struct typePagination{

    int page;
    double pontuation;

};

struct typeElementIndex{

    char * word;
    int lenPages;
    typePagination * pages;

};

typeIndex * newTypeIndex(char * documentName, void * stopWordsData);

typeElementIndex* consultWord(typeIndex * index, char * key);


#endif