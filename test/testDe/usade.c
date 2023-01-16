#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../../destatico/staticDic.h"


int compare(void* c1, void* c2){
    char* s1 = c1;
    char* s2 = c2;
    // printf("%s %s %d\n", s1, s2, strcmp(s1, s2));
    return strcmp(s1, s2);
}

int main(){
    typeStaticDic* de = createStaticDic(3, &compare);
    char* palavra;
    char* buscada;
    for(int i=1; i<=3;i++){
        palavra = malloc(sizeof(char)*20);
        scanf("%[^\n]%*c", palavra);
        chargeStaticDic(de, palavra);
    }
    palavra = malloc(sizeof(char)*20);
    printf("digite palavra que quer:\n");
    scanf("%[^\n]%*c", palavra);

    buscada  = searchStaticDic(de, palavra);
    if(buscada!=NULL){
        printf("%s\n", buscada);
    }else{
        printf("nao encontrei!\n");
    }
    
}