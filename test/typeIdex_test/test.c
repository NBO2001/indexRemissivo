#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeIndex/typeIndex.h"
#include "../../libs/typeStopWords/typeStopWords.h"


int main(int argc, char * argv[]){

    typeStopWord * stWord = newTypeStopWord(argv[1]);
    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);

    char tmp[150];

    while(scanf("%s", tmp) == 1){

        typeElementIndex * elem = consultWord(indiceRemissivo,tmp);

        if(elem == NULL) printf("Nao Existe\n");
        else{
            printf("{palavra: %s; totalPaginas: %d}\n",elem->word, elem->lenPages);
            for(int i=0; i < elem->lenPages; i++){
                printf("\tPage %d; Pontuation: %lf\n", elem->pages[i].page, elem->pages[i].pontuation);
            }
        }

    }
    

}
