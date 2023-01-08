#include <stdio.h>
#include "../../utils/utils.h"
#include "../../typeDocument/typeDocument.h"

int main(int argc, char * argv[]){

    FILE * fp = fopen(argv[1], "r");

    typeDocument* *docs =  mappingPages(fp);

    for(int i=0; docs[i] != NULL; i++){

        printf("{page: %d, in: %ld, end: %ld ,totWords: %ld}\n", getNumPage(docs[i]), getStartP(docs[i]), getEndP(docs[i]), getLenWords(docs[i]));
        

    }

}