#include "typeStopWords.h"
#include "../../libs/typeStaticDictionary/typeStaticDictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct typeStopWord{

    typeStaticDictionary * dictionary;

};

static int compare(void * a, void * b){

    char * aa = a;
    char * bb = b;

    return strcmp(a,b);

}

typeStopWord * newTypeStopWord(char * fileName){

    typeStopWord * stopWords = malloc(sizeof(typeStopWord));

    stopWords->dictionary = createStaticDic(392,&compare);

    FILE * wordsFile = fopen(fileName, "r");

    char * word = malloc(sizeof(char)*25);

    while (fscanf(wordsFile,"%s", word) == 1){

        chargeStaticDic(stopWords->dictionary, word);
        word = malloc(sizeof(char)*25);

    }
    

    fclose(wordsFile);

    return stopWords;
}

short isStopWord(typeStopWord * stopWords, char * word){

    if(searchStaticDic(stopWords->dictionary,word)) return 1;
    else return 0;

}