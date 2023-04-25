#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "libs/typeIndex/typeIndex.h"
#include "libs/typeStopWords/typeStopWords.h"
#include "libs/WordCloud/WordCloud.h"
#include "libs/typeLinkedList/linked_list.h"

int main(int argc, char * argv[]){
    //make run st=data/stopwords_br.txt fl=data/Paralelismo.base
    assert(argc == 3);
    srand(time(NULL));   // Initialization, should only be called once.
    double r;

    typeStopWord * stWord = newTypeStopWord(argv[1]);

    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);

    typeList* allWords = getWordsSeach(indiceRemissivo);

    WordCloud* wordCloud = wordCloudCreate();



    char* wd = remove_start(allWords);
    int i = 0;
    int sort = 0;

    while ( wd != NULL ){
        
        r = (rand()%10)*1.0;
        
        sort =  (rand()%2);
        
        if(sort){

            insertWordInQueue(wordCloud, wd, r);

        }
        wd = remove_start(allWords);
        i++;
        
    }
    

    

    //showIndex(indiceRemissivo);
    // createMarkDownIndex(indiceRemissivo, "padrao.md", "Padrao Indice");

    // analiseDataStopWord(stWord);


    fileCreate(wordCloud, 50, "indice.html");

}
