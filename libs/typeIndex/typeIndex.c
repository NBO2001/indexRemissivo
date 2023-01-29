#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "stdlib.h"
#include "typeIndex.h"
#include "../typeDynamicDictionary/typeDynamicDictionary.h"
#include "../utils/utils.h"
#include "../typeDocument/typeDocument.h"
#include "../typeStopWords/typeStopWords.h"
#include "../tipoPalavra/tipoPalavra.h"

struct typeIndex{
    typeDynamicDictionary *words;
    char* *wordsForSeach;
    unsigned int totalWordsForSeach;
    unsigned int totalPages;
};



typeIndex * newTypeIndex(char * documentName, void * stopWordsData){

    typeStopWord * stopWords = stopWordsData;
    typeIndex * index = malloc(sizeof(typeIndex));
    int tamDocuments = 40;
    int indexDoc = 0;
    long int contWords = 0;

    unsigned int indexWordsFSeach = 0;
    index->totalWordsForSeach = 2;
    index->wordsForSeach = calloc(sizeof(char*),index->totalWordsForSeach);

    typeDocument* *documents = malloc(sizeof(typeDocument *)*tamDocuments);

    FILE * fp = fopen(documentName,"r");
    
    char tmp[150];

    index->words = newDynamicDictionary(14000);

    while(fscanf(fp,"%s", tmp) == 1){

        if(strcmp(tmp,"PA") == 0){
            
            if(indexDoc >= (tamDocuments-2)){
                tamDocuments *= 2;
                documents = realloc(documents, sizeof(typeDocument *)*tamDocuments);
                assert(documents != NULL);
            }
            
            documents[indexDoc] = tpDocument();
            setNumPage(documents[indexDoc],indexDoc);
            setLenWords(documents[indexDoc],0);
            indexDoc++;
            

        }else{

            cleaningWord(tmp);
            lowerCase(tmp);
            
            if((!isStopWord(stopWords,tmp)) && (lenStr(tmp) > 0)){

                setLenWords(documents[indexDoc-1],getLenWords(documents[indexDoc-1])+1);

                tipoPalavra* word = searchDynamicDictionary(index->words,tmp,strlen(tmp));
                
                if(!word){

                    if(indexWordsFSeach >= index->totalWordsForSeach){
                        index->totalWordsForSeach *= 2;
                        index->wordsForSeach = realloc(index->wordsForSeach,sizeof(char*)*index->totalWordsForSeach);
                    }
                    
                    word = criarPalavra();
                    setPalavra(word,tmp);
                    
                    index->wordsForSeach[indexWordsFSeach] = malloc(sizeof(char*)*strlen(tmp));
                    memcpy(index->wordsForSeach[indexWordsFSeach],tmp,sizeof(char*)*strlen(tmp));
                    indexWordsFSeach++;

                    setPage(word,documents[indexDoc-1],&indexDoc);
                    
                    insertDynamicDictionary(index->words,tmp,strlen(tmp),word,sizeWord());
                    
                }else{
                    setPage(word,documents[indexDoc-1],&indexDoc);
                }
                
            }
        }

    }

    fclose(fp);
    
    index->totalPages = indexDoc;
    index->totalWordsForSeach = indexWordsFSeach;

    return index;

}

void calculatorPontuations(typeIndex * index, tipoPalavra * palavra, int tam){

    int i = 0;
    typeDocument * doc;
    
    while (i < tam){
        doc = getDocument(palavra,i);
        int recorrencias = getRecorreces(palavra,i);
        int totWords = getLenWords(doc);
        unsigned int totDoc = index->totalPages;
        
        double pontuation = tfidf(recorrencias,totWords,tam,totDoc);
        
        setPontuation(palavra,i,pontuation);
        
        i++;

    }
    sortingPages(palavra);

}

typeElementIndex* consultWord(typeIndex * index, char * key){

    cleaningWord(key);

    tipoPalavra* word = searchDynamicDictionary(index->words,key,strlen(key));
   
   
    if(!word) return NULL;

    int tam = getLenPages(word);
    calculatorPontuations(index,word,tam);

    typeElementIndex* element = calloc(sizeof(typeElementIndex),1);
    element->pages = calloc(sizeof(typePagination), 5);

    element->word = calloc(sizeof(char), 150);

    strcpy(element->word,getPalavra(word));

    typePagination tmp;
    
    int i=0;

    typeDocument * doc;

    while(i < 5 && i < tam){
        
        doc = getDocument(word,i);
        tmp.page = getNumPage(doc);
        tmp.pontuation = getPontuation(word, i);

        element->pages[i] = tmp;

        element->lenPages++;
        i++;
    }

    return element;

}

char* *getWordsSeach(typeIndex * index){ return index->wordsForSeach; }
unsigned int getTamWordsSeach(typeIndex * index){ return index->totalWordsForSeach; }