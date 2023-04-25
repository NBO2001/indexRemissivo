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

// Return linked list
void* getWordsSeach(typeIndex * index);

void showIndex(typeIndex * index);

void createMarkDownIndex(typeIndex * index, char * fileName, char * title);

void seeSearch(typeIndex * index, char * key);

#endif