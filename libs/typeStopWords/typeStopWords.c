#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typeStopWords.h"
#include "../../libs/typeStaticDictionary/typeStaticDictionary.h"
#include "../utils/utils.h"

struct typeStopWord{

    typeStaticDictionary * dictionary;

};


typeStopWord * newTypeStopWord(char * fileName){

    typeStopWord * stopWords = malloc(sizeof(typeStopWord));

    stopWords->dictionary = createStaticDic(.tam=331,.chargeFactor=6,.fixedChargeFactor=1);

    FILE * wordsFile = fopen(fileName, "r");

    char * word = calloc(25,sizeof(char));

    while (fscanf(wordsFile,"%s", word) == 1) chargeStaticDic(stopWords->dictionary, word, strlen(word));
     
    fclose(wordsFile);

    analyticalData data = getAnalicalDataStactDic(stopWords->dictionary);    
    fileAnalyticalData(.data=data,.title="TypeStopWord Dictionary",.outputName="STOPWORD587.md");

    return stopWords;
}

short isStopWord(typeStopWord * stopWords, char * word){

    if (searchStaticDic(stopWords->dictionary, word,strlen(word))) return 1;
    else return 0;

}

void analiseDataStopWord(typeStopWord * stopWords){

    analyticalData data = getAnalicalDataStactDic(stopWords->dictionary);    
    fileAnalyticalData(.data=data,.title="TypeStopWord Dictionary",.outputName="STOPWORD587.md",.createNewFile=0);

}