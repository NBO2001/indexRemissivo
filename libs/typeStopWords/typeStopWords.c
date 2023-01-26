#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeStopWords.h"
#include "../../libs/typeStaticDictionary/typeStaticDictionary.h"


struct typeStopWord{

    typeStaticDictionary * dictionary;

};


typeStopWord * newTypeStopWord(char * fileName){

    typeStopWord * stopWords = malloc(sizeof(typeStopWord));

    stopWords->dictionary = createStaticDic(400);

    FILE * wordsFile = fopen(fileName, "r");

    char * word = malloc(sizeof(char)*25);

    while (fscanf(wordsFile,"%s", word) == 1) chargeStaticDic(stopWords->dictionary, word, strlen(word));
    
    fclose(wordsFile);

    return stopWords;
}

short isStopWord(typeStopWord * stopWords, char * word){

    if (searchStaticDic(stopWords->dictionary, word,strlen(word))) return 1;
    else return 0;

}