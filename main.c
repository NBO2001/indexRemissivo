#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "libs/typeIndex/typeIndex.h"
#include "libs/typeStopWords/typeStopWords.h"

int main(int argc, char * argv[]){

    assert(argc == 3);

    typeStopWord * stWord = newTypeStopWord(argv[1]);

    typeIndex * indiceRemissivo = newTypeIndex(argv[2],stWord);


    showIndex(indiceRemissivo);

    analiseDataStopWord(stWord);


}
