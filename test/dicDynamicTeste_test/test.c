#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../libs/typeDynamicDictionary/typeDynamicDictionary.h"
#include "../../libs/utils/utils.h"

int main(int argc, char * argv[]){

   
    
    char * * strings = malloc(sizeof(char*)*100000);
    int index = 0;
    
    typeDynamicDictionary * dictionary = newDynamicDictionary();

    assert(dictionary != NULL);
    

    //FILE * fp = fopen("./data/Aventuras.base","r");
    //FILE * fp = fopen("./data/Guarani.base","r");
    FILE * fp = fopen("./data/Paralelismo.base","r");
    assert(fp != NULL);

    char * tmpCaracte = malloc(sizeof(char)*150);

    while (fscanf(fp,"%s", tmpCaracte) == 1){
      if(searchDynamicDictionary(dictionary,tmpCaracte,strlen(tmpCaracte)) == NULL ){

        insertDynamicDictionary(dictionary,tmpCaracte,strlen(tmpCaracte),tmpCaracte,strlen(tmpCaracte));
        
          strings[index]=tmpCaracte;
          index++;
          tmpCaracte = malloc(sizeof(char)*150);
        
      }
    }
    
    fclose(fp);


    analyticalData data = getAnalicalDataDynanDic(dictionary);    
    fileAnalyticalData(.data=data);

    char * tmpRetorno;

    for(int i = 0; i < index; i++){
      tmpRetorno = searchDynamicDictionary(dictionary,strings[i],strlen(strings[i]));
      assert(tmpRetorno != NULL);
    }


    data = getAnalicalDataDynanDic(dictionary);
    fileAnalyticalData(.data=data, .createNewFile=0);

}