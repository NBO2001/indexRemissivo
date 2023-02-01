#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/utils/utils.h"
#include "../../libs/typeLinkedList/linked_list.h"

int cmp(void* a,void*b){
    return memcmp(a,b,strlen( (char*) a));
}

int main(int argc, char * argv[]){

    char * * strings = malloc(sizeof(char*)*100000);
    int index = 0;
    
    typeList * list = newLinkedList(&cmp,sizeof(char)*150);

    assert(list != NULL);
    

    FILE * fp = fopen("./data/V2.base","r");

    assert(fp != NULL);

    char * tmpCaracte = malloc(sizeof(char)*150);

    while (fscanf(fp,"%s", tmpCaracte) == 1){
        
        cleaningWord(tmpCaracte);
        lowerCase(tmpCaracte);
        if(strlen(tmpCaracte) > 0){

            printf("Inserindo: %s\n", tmpCaracte);
            insert_with_value(list,tmpCaracte);
            
            strings[index]=tmpCaracte;
            index++;
            tmpCaracte = malloc(sizeof(char)*150);
        
        }
      
    }
    
    fclose(fp);

    char * tmpRetorno = remove_start(list);

    while (tmpRetorno){
        printf("%s\n", tmpRetorno);
        tmpRetorno = remove_start(list);
    }
    

}