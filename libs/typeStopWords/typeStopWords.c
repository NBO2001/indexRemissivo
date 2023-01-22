#include "typeStopWords.h"
#include "../../libs/typeDynamicDictionary/typeDynamicDictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct typeStopWord{

    typeDynamicDictionary * dictionary;

};

static int compare(void * a, void * b){

    char * aa = a;
    char * bb = b;

    return strcmp(a,b);

}

typeStopWord * newTypeStopWord(char * fileName){

    typeStopWord * stopWords = malloc(sizeof(typeStopWord));

    stopWords->dictionary = newDynamicDictionary(400);

    FILE * wordsFile = fopen(fileName, "r");

    char * word = malloc(sizeof(char)*25);

    while (fscanf(wordsFile,"%s", word) == 1){

        insertDynamicDictionary(stopWords->dictionary, word, strlen(word), word, strlen(word));
        word = malloc(sizeof(char)*25);

    }
    
    fclose(wordsFile);

    return stopWords;
}

short isStopWord(typeStopWord * stopWords, char * word){

    if (searchDynamicDictionary(stopWords->dictionary, word,strlen(word))) return 1;
    else return 0;

}