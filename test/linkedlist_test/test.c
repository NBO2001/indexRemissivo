#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeLinkedList/linked_list.h"

int cmp(void* a,void*b){
    return memcmp(a,b,sizeof(char)*150);
}

int main(int argc, char * argv[]){

    typeList * list = newLinkedList(&cmp,150);

    assert(list != NULL);

    char* tmp = malloc(150);

    scanf("%s", tmp);

    insert_start(list,tmp);

    assert(seach_in_list(list, tmp) != NULL);

    scanf("%s", tmp);

    insert_start(list,tmp);

    assert(seach_in_list(list, tmp) != NULL);

    scanf("%s", tmp);

    insert_start(list,tmp);

    assert(seach_in_list(list, tmp) != NULL);

}