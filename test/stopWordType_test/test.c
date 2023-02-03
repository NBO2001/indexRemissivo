#include <stdio.h>
#include "../../libs/typeStopWords/typeStopWords.h"
#include "../../libs/utils/utils.h"

int main(int argc, char * argv[]){


    typeStopWord * stopword = newTypeStopWord(argv[1]);

    FILE * fp = fopen(argv[1], "r");

    char search[25];
    while (fscanf(fp,"%s", search)==1){
        cleaningWord((unsigned char *)search);
        if(!isStopWord(stopword,search)) printf("N eh estop word: %s\n", search); 
    }
    
    printf("Fim\n");

    


}