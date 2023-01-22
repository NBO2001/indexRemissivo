#include "quick_sort.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>

void qSort(void* vet, int start, int end, int sizeEl, comparator cmp){

    int i,j;
    void * tmp;
    int harf;
    void * pivot;

    if(start < end){


        
        i = start;
        j = end;

        tmp = (void*) malloc(sizeEl);
        pivot = (void*) malloc(sizeEl);

        harf = (i+j)/2;
        
        memcpy(pivot, vet + (harf*sizeEl) , sizeEl);

        while(i < j){
            
            while(cmp(vet+(i*sizeEl), pivot) > 0){ i++; }
            while(cmp(vet+(j*sizeEl), pivot) < 0){ j--; }
                
            
            if(i <= j){
                
                memcpy(tmp, vet+(i*sizeEl), sizeEl);
                memcpy(vet+(i*sizeEl), vet+(j*sizeEl), sizeEl);
                memcpy(vet+(j*sizeEl), tmp, sizeEl);

                i++;
                j--;
            }

        }

        free(pivot);
        free(tmp);

        qSort(vet, start, j,sizeEl, cmp);
        qSort(vet, i, end,sizeEl, cmp);

        
    }
    


}

void sort(void* vet, int n, int sizeEl,comparator cmp ){

    
    qSort(vet, 0, n-1, sizeEl, cmp);

}