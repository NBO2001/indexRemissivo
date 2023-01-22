#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/tipoPalavra/tipoPalavra.h"
#include "../../libs/utils/utils.h"


int main(int argc, char * argv[]){

    tipoPalavra** palavras = calloc(sizeof(tipoPalavra*),14000);

    assert(palavras != NULL);

    char tmpWord[150];

    int i = 0;

    FILE * fp = fopen(argv[1],"r");

    

    while (fscanf(fp,"%s", tmpWord)==1){
        
        palavras[i] = criarPalavra();

        setPalavra(palavras[i], tmpWord);
        
        i++;
    }

    fclose(fp);
    
    for(int j=0; j < i; j++){
        
        printf("%s\n", getPalavra(palavras[j]));

    }
    
   


}
