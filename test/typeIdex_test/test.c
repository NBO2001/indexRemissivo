#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeIndex/typeIndex.h"
#include "../../libs/typeStopWords/typeStopWords.h"
#include "../../libs/utils/utils.h"
#include "../../libs/typeLinkedList/linked_list.h"

int main(int argc, char * argv[]){

    assert(argc == 3);

    typeStopWord * stWord = newTypeStopWord(argv[1]);
    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);

    typeList* wordsV = getWordsSeach(indiceRemissivo);

    unsigned int i = 0;

    char * tmp = remove_start(wordsV);

    while (tmp){

        typeElementIndex * elem = consultWord(indiceRemissivo,tmp);

        assert(elem != NULL);

        printf("{ %s; ",elem->word);

        for(int i=0; i < elem->lenPages; i++) printf("%d, ", elem->pages[i].page);

        printf("}\n");
        
        tmp = remove_start(wordsV);
    }
    

}
