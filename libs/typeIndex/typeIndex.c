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
#include "../typeLinkedList/linked_list.h"

#define TITLE "TypeIndex Dictionary Generic"

struct typeIndex{
    typeDynamicDictionary *words;

    typeList *wordsForSeach;
    unsigned int totalPages;
};

int cmpLinkedList(void* a,void*b){
    return memcmp(a,b,strlen( (char*) a));
}

typeIndex * newTypeIndex(char * documentName, void * stopWordsData){

    typeStopWord * stopWords = stopWordsData;
    typeIndex * index = malloc(sizeof(typeIndex));
    int tamDocuments = 40;
    unsigned int indexDoc = 0;

    index->wordsForSeach = newLinkedList(&cmpLinkedList,sizeof(char)*150);

    typeDocument* *documents = malloc(sizeof(typeDocument *)*tamDocuments);

    FILE * fp = fopen(documentName,"r");
    
    char tmp[150];

    // index->words = newDynamicDictionary(.fixedChargeFactor=1,.factorCharge=5);
    index->words = newDynamicDictionary();

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

            cleaningWord((unsigned char*) tmp);
            lowerCase((unsigned char*) tmp);
            
            if((!isStopWord(stopWords,tmp)) && (lenStr((unsigned char*)tmp) > 1)){
                
                removeSpecialCharacters((unsigned char*) tmp);

                if(strlen(tmp)==0) continue;
                
                setLenWords(documents[indexDoc-1],getLenWords(documents[indexDoc-1])+1);

                tipoPalavra* word = searchDynamicDictionary(index->words,tmp,strlen(tmp));
                
                if(!word){

                    word = criarPalavra();
                    setPalavra(word,tmp);

                    insert_with_value(index->wordsForSeach,tmp);

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

    analyticalData data = getAnalicalDataDynanDic(index->words);    
    fileAnalyticalData(.data=data,.title=TITLE,.outputName="DIC5201.md");

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

    cleaningWord((unsigned char*)key);

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

void* getWordsSeach(typeIndex * index){ return index->wordsForSeach; }

void _addPoint(int n){ for(int i=0; i < n; i++) printf("."); }
void _faddPoint(FILE * fp,int n){ for(int i=0; i < n; i++) fprintf(fp,"."); }

void showIndex(typeIndex * index){


    char * tmp = remove_start(index->wordsForSeach);

    while (tmp){

        typeElementIndex * elem = consultWord(index,tmp);
        
        assert(elem != NULL);

        printf("%s",elem->word);
        _addPoint(50 - strlen(elem->word));
        
        int i;
        
        for(i=0; i < elem->lenPages-1; i++) printf("%d, ", elem->pages[i].page+1);
        printf("%d\n", elem->pages[i].page+1);
        
        tmp = remove_start(index->wordsForSeach);
    }

    analyticalData data = getAnalicalDataDynanDic(index->words);    
    fileAnalyticalData(.data=data,.title=TITLE,.outputName="DIC5201.md",.createNewFile=0);
    


}

void createMarkDownIndex(typeIndex * index, char * fileName, char * title){


    FILE * fp = fp = fopen(fileName,"w");
    fprintf(fp,"# %s\n\n", title);

    char * tmp = remove_start(index->wordsForSeach);
    unsigned char letter = 0;

    while (tmp){
        
        if(tmp[0] != letter){
            fprintf(fp,"## %c\n\n", tmp[0]-32);
            letter = tmp[0];
        }

        typeElementIndex * elem = consultWord(index,tmp);
        
        assert(elem != NULL);

        fprintf(fp,"%s",elem->word);
        _faddPoint(fp,50 - strlen(elem->word));
        
        int i;
        
        for(i=0; i < elem->lenPages-1; i++) fprintf(fp,"%d, ", elem->pages[i].page+1);
        fprintf(fp,"%d\n\n", elem->pages[i].page+1);
        
        tmp = remove_start(index->wordsForSeach);
    }

    fclose(fp);

    analyticalData data = getAnalicalDataDynanDic(index->words);    
    fileAnalyticalData(.data=data,.title=TITLE,.outputName="DIC5201.md",.createNewFile=0);
    


}