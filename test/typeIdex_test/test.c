#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeIndex/typeIndex.h"
#include "../../libs/typeStopWords/typeStopWords.h"
#include "../../libs/utils/utils.h"

const int cmpStr(const void * a, const void * b){

    const char * aa = a;
    const char * bb = b;

    return strcmp(bb,aa);
}

int main(int argc, char * argv[]){

    assert(argc == 3);

    typeStopWord * stWord = newTypeStopWord(argv[1]);
    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);

    char tmp[150];

    char** wordsV = getWordsSeach(indiceRemissivo);

    unsigned int n = getTamWordsSeach(indiceRemissivo);

    unsigned int i = 0;

    while (i < n){

        typeElementIndex * elem = consultWord(indiceRemissivo,wordsV[i]);

        assert(elem != NULL);

        printf("{ %s; ",elem->word);

        for(int i=0; i < elem->lenPages; i++) printf("%d, ", elem->pages[i].page);

        printf("}\n");

        i++;
    }
    

}
