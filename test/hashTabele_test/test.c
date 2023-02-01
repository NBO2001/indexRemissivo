#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeTableHash/typeTableHash.h"

int main(int argc, char * argv[]){

   
    
    char * * strings = malloc(sizeof(char*)*20000);
    int index = 0;
    
    typeTableHash * table = createTableHash();

    assert(table != NULL);
    

    FILE * fp = fopen("./data/Aventuras.base","r");

    assert(fp != NULL);

    char * tmpCaracte = malloc(sizeof(char)*50);

    while (fscanf(fp,"%s", tmpCaracte) == 1){
      if(seachTable(table,tmpCaracte,strlen(tmpCaracte)) == NULL ){

        insertTable(table,tmpCaracte,strlen(tmpCaracte),tmpCaracte,strlen(tmpCaracte));
        
        strings[index]=tmpCaracte;
        index++;
        tmpCaracte = malloc(sizeof(char)*50);
      
      }
    }
    
    fclose(fp);

    char * tmpRetorno;

    for(int i = 0; i < index; i++){
      tmpRetorno = seachTable(table,strings[i],strlen(strings[i]));
      assert(tmpRetorno != NULL);
    }

    analyticalData data = getAnalicalData(table);
    printf("Tam Table: %d, chargeFactor: %d, totalElements: %d, reHashingRealized: %u, biggerL: %u\n ", 
    data.tam, data.factorCharge, data.totalElements, data.reHashingRealizade, data.biggerLinkedList);

    printf("Total de s: %d, CMPS: %lf, Media: %lf\n ", 
    data.seachTotal, data.totalCmp, (double) data.totalCmp/data.seachTotal);
}