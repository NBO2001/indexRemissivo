#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "utils.h"

char isLetter(char letter){
    return !( 
        ( 0 <= letter &&  letter <=  57) 
    || ( 58 <= letter &&  letter <= 63) 
    || ( 91 <= letter &&  letter <= 96) 
    || ( 123 <= letter &&  letter <= 126) 
    || ( 8200 <= letter &&  letter <= 8230) 
    );
}

int lenStr(char string[]){

    int cont = 0;

    int i = 0;

    while (string[i])
    {
        cont++;
        i++;
    }

    return cont;
    

}

char * cleaningWord(char * word){

    int tam = lenStr(word);

    int ctI = 0;
    int ctJ = tam-1;

    while (!isLetter(word[ctI])){ ctI++; }
    
    while (!isLetter(word[ctJ])){ ctJ--; }

    int i; 

    for(i = ctI; i <= ctJ; i++ ){ word[i-ctI] = word[i]; }

    word[i-ctI] = 0;
    
    return word;

}

double tf(int wordOccurrences, int docWord){ return wordOccurrences/(double) docWord; }

double idf(int docsWords, int docs){ 

    docsWords = docsWords > 0? docsWords: 1;
    double div = docs/ (double) docsWords;

    return log10(div);

}

double tfidf(int palavra, int doc, int qntWords, int docs){ return ( tf(palavra, doc) * idf(qntWords, docs)); }

const char * lowerCase(char string[]){
    int size = lenStr(string);
    for (int i = 0; i < size; i++){
        if (string[i] >= 65 && string[i] <= 90 && string[i]){
            string[i] += 32;
        }
    }
    return string;
}