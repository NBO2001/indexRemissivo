#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeIndex/typeIndex.h"
#include "../../libs/typeStopWords/typeStopWords.h"


int main(int argc, char * argv[]){

    typeStopWord * stWord = newTypeStopWord(argv[1]);
    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);
    

}
