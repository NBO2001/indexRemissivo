#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeLinkedList/linked_list.h"

int cmp(void* a,void*b){
    return memcmp(a,b,sizeof(char)*150);
}

int main(int argc, char * argv[]){

    char * * strings = malloc(sizeof(char*)*20000);
    int index = 0;
    
    typeList * list = newLinkedList(&cmp,sizeof(char*));

    assert(list != NULL);
    

    FILE * fp = fopen("./data/Aventuras.base","r");

    assert(fp != NULL);

    char * tmpCaracte = malloc(sizeof(char)*50);

    while (fscanf(fp,"%s", tmpCaracte) == 1){
    
        insert(list,tmpCaracte,strlen(tmpCaracte),tmpCaracte,strlen(tmpCaracte));
        
        strings[index]=tmpCaracte;
        index++;
        tmpCaracte = malloc(sizeof(char)*50);
      
    }
    
    fclose(fp);

}