#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "utils.h"
#include <string.h>

char isLetter(unsigned char letter){
    return !( 
        ( 0 <= letter &&  letter <=  57) 
    || ( 58 <= letter &&  letter <= 63) 
    || ( 91 <= letter &&  letter <= 96) 
    || ( 123 <= letter &&  letter <= 128)
    || ( 226 <= letter &&  letter <= 226)
    || ( 152 <= letter &&  letter <= 157)  
    || ( 8200 <= letter &&  letter <= 8230) 
    );
}

int lenStr(unsigned char *string){

    int cont = 0;

    int i = 0;

    while (string[i])
    {
        cont++;
        i++;
    }

    return cont;
    

}

void removeSpecialCharacters(unsigned char * string){

    int tamStr = strlen((char *)string);
    int indexCopia = 0 ;

    int i = 0 ;
    
    while(i < tamStr){
        
        if(string[i] == 195){

            if((string[i+1] >= 160 && string[i+1] <= 165) || (string[i+1] >= 128 && string[i+1] <= 133) ) string[indexCopia] = 97;
            else if((string[i+1] >= 168 && string[i+1] <= 171) || (string[i+1] >= 136 && string[i+1] <= 139) ) string[indexCopia] = 101;
            else if( (string[i+1] >= 172 && string[i+1] <= 174) || (string[i+1] >= 140 && string[i+1] <= 143)   ) string[indexCopia] = 105;
            else if( (string[i+1] >= 178 && string[i+1] <= 181) || (string[i+1] >= 146 && string[i+1] <= 150)   ) string[indexCopia] = 111;
            else if( (string[i+1] >= 185 && string[i+1] <= 188) || (string[i+1] >= 153 && string[i+1] <= 156)   ) string[indexCopia] = 117;
            else if( (string[i+1] == 167 || string[i+1] == 135)    ) string[indexCopia] = 99;

            indexCopia++;
            i = i + 2;

        }else if(string[i] == 194) i = i + 2;

        else{
            string[indexCopia] = string[i];
            indexCopia++;
            i++;
        }
    }

    string[indexCopia] = '\0';


}

void cleaningWord(unsigned char * word){
    
    int tam = lenStr(word);

    int ctI = 0;
    int ctJ = tam-1;

    while (!isLetter(word[ctI])){ ctI++; }
    
    while (!isLetter(word[ctJ])){ ctJ--; }

    int i; 

    for(i = ctI; i <= ctJ; i++ ){ word[i-ctI] = word[i]; }

    word[i-ctI] = 0;

}

double tf(int wordOccurrences, int docWord){ return wordOccurrences/(double) docWord; }

double idf(int docsWords, int docs){ 

    docsWords = docsWords > 0 ? docsWords: 1;
    double div = docs / (double) docsWords;

    return log10(div);

}

double tfidf(int palavra, int doc, int qntWords, int docs){ return ( tf(palavra, doc) * idf(qntWords, docs)); }

void lowerCase(unsigned char string[]){
    int size = lenStr(string);
    for (int i = 0; i < size; i++){
        if (string[i] >= 65 && string[i] <= 90){
            string[i] += 32;
        }else if(string[i] >= 128 && string[i] <= 159){
            string[i] += 32;
        }else if(string[i] == 226){
            i = i + 3;
        }
    }
    
}

void _fileAnalyticalData(fileG in){

    FILE * fp = fp = fopen(in.outputName,"a");

    analyticalData data = in.data;
    double taxaOcupationVector = ((double) data.positionsNoEmpty*100)/data.tam;
    if(in.createNewFile){
        fprintf(fp,"# %s\n\n",in.title);
        
        fprintf(fp,"## 1. Analise do vetor\n\n");
        fprintf(fp,"| Total de elementos | Tamanho vetor final      | Total de posicoes ocupadas | Ocupacao do vetor (%%) |\n");
        fprintf(fp,"| ----------- | ----------- | ----------- | ----------- |\n");
        fprintf(fp,"| %u    | %u    | %u | %.2lf%% |\n", \
        data.totalElements,data.tam, data.positionsNoEmpty, taxaOcupationVector);
        
        fprintf(fp,"## 2. Analise de espalhamento\n\n");
        fprintf(fp,"| Fator de carga | Maior Lista Encadeada | Listas > Fator Carga | Re-hashing Realizados | Media de no por lista |\n");
        fprintf(fp,"| ----------- | ----------- | ----------- | ----------- | ----------- |\n");
        fprintf(fp,"| %u    | %u | %u | %u | %lf |\n\n", \
        data.factorCharge, data.biggerLinkedList, data.exceededFactorCharge, data.reHashingRealizade,data.averageListSize);

        fprintf(fp,"## 3. Buscas e comparacoes\n\n");
        fprintf(fp,"| Total de buscas      | Total de comparacoes | Media comparacoes/busca |\n");
        fprintf(fp,"| ----------- | ----------- | ----------- |\n");
    }
    
    fprintf(fp,"| %u    | %u | %.2lf |\n", data.seachTotal,  data.totalCmp, data.avarageComparator);

    fclose(fp);
}