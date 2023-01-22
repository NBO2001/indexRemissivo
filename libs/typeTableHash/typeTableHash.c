#include "typeTableHash.h"
#include "stdio.h"
#include "stdlib.h"



struct typeTableHash{
    typeList* *lists;
};




typeTableHash* createTableHash(){
    typeTableHash* thash = malloc(sizeof(typeTableHash));

    thash->lists = malloc(sizeof(typeList*)*100);
    

}
