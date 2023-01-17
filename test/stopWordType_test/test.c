#include <stdio.h>
#include "../../libs/typeStopWords/typeStopWords.h"

int main(int argc, char * argv[]){


    typeStopWord * stopword = newTypeStopWord(argv[1]);

    for(int i=0; i < 10; i++){

        char seach[25];
        scanf("%s",seach);

        if(isStopWord(stopword,seach)) printf("Eh stop word\n");
        else printf("N eh estop word\n"); 


    }


}