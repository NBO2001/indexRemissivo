#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"


// Funcao que intercala os valores
void intercalary(void* *als, int inicio, int meio, int fim, void* * aux, compare cmp){

    int i, j,k=inicio;

    i = inicio;
    j = meio + 1;

    while( (i <= meio) && (j <= fim)){

        if(cmp(als[i],als[j])){
            aux[k] = als[i];
            i++;
        }else{
            aux[k] = als[j];
            j++;
        }

        k++;
    }

    while( i <= meio){
        aux[k] = als[i];
        i++;
        k++;
    }
    while( j <= fim){
        aux[k] = als[j];
        j++;
        k++;
    }

    for(i=inicio; i < k; i++){ als[i] = aux[i];  }

}

void mergeR(void* *v, int inicio, int fim, void* *aux, compare cmp){

    int meio; 
    
    if (inicio < fim){
        meio = (inicio+fim)/2;

        mergeR(v, inicio, meio, aux, cmp);
        mergeR(v, meio+1, fim, aux, cmp);
        intercalary(v,inicio,meio,fim,aux, cmp);

    }

}

void merge(void* *els, int tam, compare cmp){

    void* *aux  =  malloc(sizeof(void*)*(tam+2));

    mergeR(els,0,tam-1,aux, cmp);

    free(aux);

}
