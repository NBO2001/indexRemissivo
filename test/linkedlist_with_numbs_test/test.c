#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeLinkedList/linked_list.h"

int cmp(void* a,void*b){
    int * aa = a;
    int * bb = b;
    return (*aa)-(*bb);
}

int main(int argc, char * argv[]){

  
    typeList * list = newLinkedList(&cmp,sizeof(int));

    int tmp;
    int n = 10;

    for(int i=0; i < n; i++){

        scanf("%d", &tmp);
        insert_with_value(list,&tmp);

    }

    int * rt = remove_start(list);

    while (rt)
    {
        printf("V; %d\n", *rt);
        rt = remove_start(list);
    }
    

  

}