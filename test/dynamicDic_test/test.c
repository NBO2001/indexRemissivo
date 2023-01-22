#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeDynamicDictionary/typeDynamicDictionary.h"

int main(int argc, char * argv[]){

    typeDynamicDictionary * dictionary = newDynamicDictionary(14000);
    assert(dictionary != NULL);

    char * key = malloc(sizeof(char)*150);

    scanf("%s",key);

    insertDynamicDictionary(dictionary,key, 150, key, 150);

    char * ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);

    printf("%s\n", ret);

      scanf("%s",key);

    insertDynamicDictionary(dictionary,key, 150, key, 150);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


    scanf("%s",key);

    insertDynamicDictionary(dictionary,key, 150, key, 150);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    scanf("%s",key);

    insertDynamicDictionary(dictionary,key, 150, key, 150);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    printf(" *- *- *- *- \n");

    scanf("%s",key);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);

    scanf("%s",key);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


    scanf("%s",key);

    ret = searchDynamicDictionary(dictionary,key,150);

    assert(ret != NULL);
    
    printf("%s\n", ret);


}