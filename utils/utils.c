#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "utils.h"

char isLetter(char letter){
    return !( 
        ( 0 <= letter &&  letter <=  47) 
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

void insertElDocs(
    typeDocument* *docs, 
    int *tamDocuments, 
    int *indexDoc,
    long int *startPage,
    long int *previus,
    long int *contWords,
    FILE * fp){

    typeDocument * tm = tpDocument();

    assert(tm != NULL);
    
    docs[(*indexDoc)] = tm;
    setNumPage(docs[(*indexDoc)], (*indexDoc));
    setStartP(docs[(*indexDoc)], (*startPage));
    setEndP(docs[(*indexDoc)], (*previus));
    setLenWords(docs[(*indexDoc)], (*contWords));

    (*indexDoc)++;

    (*startPage) = ftell(fp);
    (*contWords) = 0;

}

typeDocument* * mappingPages(FILE * fp){

    int tamDocuments = 2;
    int indexDoc = 0;
    long int startPage = 0;
    long int previus = 0;
    long int contWords = 0;
    typeDocument* *documents = malloc(sizeof(typeDocument *)*tamDocuments);
    
    char tmp[150];

    while(fscanf(fp,"%s", tmp) == 1){
        
        previus = ftell(fp) - strlen(tmp);

        if(strcmp(tmp,"PA") == 0){


            if(indexDoc >= (tamDocuments-2)){
                tamDocuments *= 2;
                documents = realloc(documents, sizeof(typeDocument *)*tamDocuments);
                assert(documents != NULL);
            }

            if(previus != 0){

                insertElDocs(documents,&tamDocuments,&indexDoc,&startPage, &previus, &contWords,fp);

            }

        }else{
            //if(!isStorpWord(tmp)){
            contWords++;
            //}
        }
        
    }

    insertElDocs(documents,&tamDocuments,&indexDoc,&startPage, &previus, &contWords,fp);

    for(int i=indexDoc; i < tamDocuments; i++){
        documents[i] = NULL;
    }


    return documents;
    
}