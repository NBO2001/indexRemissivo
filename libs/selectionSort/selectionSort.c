#include "selectionSort.h"
#include <string.h>
#include <stdlib.h>
#include "../../libs/tipoPalavra/tipoPalavra.h"

void selectSort(void * elemts, int tam,unsigned int sizeElement, comparator cmp){

    typePage * elem = elemts;
    
    int i, j, min_idx;
    
    void* tmp = (void*) malloc(sizeElement);

    // One by one move boundary of unsorted subarray
    for (i = 0; i < tam-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for(j = i+1; j < tam; j++){
            if(cmp(elemts+(j*sizeElement), elemts+(min_idx*sizeElement)) > 0 ){
                min_idx = j;
            }
        }
     
     
 
        // Swap the found minimum element with the first element
        if(min_idx != i){

            memcpy(tmp, elemts+(i*sizeElement), sizeElement);
            memcpy(elemts+(i*sizeElement), elemts+(min_idx*sizeElement), sizeElement);
            memcpy(elemts+(min_idx*sizeElement), tmp, sizeElement);
            
        }
            
    }

}