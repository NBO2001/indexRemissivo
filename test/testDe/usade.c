#include "stdio.h"
#include "stdlib.h"
#include "destatico.h"

typedef struct aluno{
    int id;
    float mf;
}TAluno;

TAluno* criar_aluno(int id, float mf){
    TAluno* aluno = malloc(sizeof(TAluno));
    aluno->id = id;
    aluno->mf = mf;
    return aluno;
}

void mostrar_aluno(TAluno* aluno){
    printf("%d\n", aluno->id);
    printf("%f\n", aluno->mf);
}


int main(){
    TDestatico* de = criar_destatico(100);
    // TAluno* aluno = criar_aluno(1, 8.5);
    // //mostrar_aluno(aluno);
    // TEntrada entrada  = criar_entrada(404176, aluno);
    // inserir_destatico(de, entrada);
    // aluno = buscar_destatico(de, 404176);
    // mostrar_aluno(aluno);
    // printf("deu certo!\n");
    int id;
    float mf;

    for(int i=1; i<=3;i++){
        scanf("%d %f", &id, &mf);
        TAluno* aluno = criar_aluno(id, mf);
        TEntrada entrada  = criar_entrada(404177+i, aluno);
        inserir_destatico(de, entrada);
    }
    for(int i=1; i<=1000; i++){
        TAluno* aluno = buscar_destatico(de, 404177+i);
        if(aluno){
            mostrar_aluno(aluno);
        }
        
    }
    

}