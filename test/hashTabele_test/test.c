#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeTableHash/typeTableHash.h"

int main(int argc, char * argv[]){

    typeTableHash * table = createTableHash(14000);
    assert(table != NULL);

    char * key = malloc(sizeof(char)*150);

    scanf("%s",key);

    insertTable(table,key, 150, key, 150);

    char * ret = seachTable(table,key,150);

    assert(ret != NULL);

    printf("%s\n", ret);

      scanf("%s",key);

    insertTable(table,key, 150, key, 150);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


    scanf("%s",key);

    insertTable(table,key, 150, key, 150);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    scanf("%s",key);

    insertTable(table,key, 150, key, 150);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    printf(" *- *- *- *- \n");

    scanf("%s",key);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    scanf("%s",key);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


    scanf("%s",key);

    ret = seachTable(table,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


}