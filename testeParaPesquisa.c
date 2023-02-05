#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libs/typeIndex/typeIndex.h"
#include "libs/typeStopWords/typeStopWords.h"

int main(int argc, char * argv[]){
    //make run st=data/stopwords_br.txt fl=data/Paralelismo.base


    typeStopWord * stWord = newTypeStopWord("data/stopwords_br.txt");

    typeIndex * indiceRemissivoAventura = newTypeIndex("data/Aventuras.base",stWord);
    typeIndex * indiceRemissivoGurani = newTypeIndex("data/Guarani.base",stWord);
    typeIndex * indiceRemissivoPalelismo = newTypeIndex("data/Paralelismo.base",stWord);

    char * key = malloc(sizeof(char)*150);
    
    while (scanf("%s", key) == 1){
        printf("Aventura:\n");
        seeSearch(indiceRemissivoAventura, key);
        printf("Guarani:\n");
        seeSearch(indiceRemissivoGurani, key);
        printf("Paralelismo:\n");
        seeSearch(indiceRemissivoPalelismo, key);
    }
    

    createMarkDownIndex(indiceRemissivoAventura, "aventura.md", "Aventura Indice");
    createMarkDownIndex(indiceRemissivoGurani, "guarani.md", "Guarani Indice");
    createMarkDownIndex(indiceRemissivoPalelismo, "paralelismo.md", "Paralelismo Indice");

    analiseDataStopWord(stWord);


}
