#include <stdio.h>
#include "../../typeTuple/typeTuple.h"

int main(int argc, char * argv[]){

    typeTuple * tuples[5];

    for(int i=0; i < 5; i++){

        int tmpInt;
        char name[25];

        scanf("%d%*c", &tmpInt);
        scanf("%[^\n]%*c", name);

        typeTuple * tmp = create(sizeof(int),&tmpInt,sizeof(char)*25, name);
        tuples[i] = tmp;

    }

    int seach;

    scanf("%d", &seach);

    while (seach >= 0){

        for(int i=0; i < 5; i++){
            
            int* t = fist(tuples[i]);

            if( *t == seach){
                char * res = secund(tuples[i]);
                printf("%s\n", res);
            }
        }

        scanf("%d", &seach);
    }
    

}