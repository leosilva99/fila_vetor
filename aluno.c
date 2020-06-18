#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    int matricula;
    char nome[50];
    char curso[30];
};

Aluno *novo_a(int matricula, char *nome, char *curso){
    Aluno *a = (Aluno*) malloc(sizeof(Aluno));
    if(a != NULL && matricula > 0 && strlen(nome) > 0 && strlen(nome) <= 49
       && strlen(curso) > 0 && strlen(curso) <= 29){
        a->matricula = matricula;
        strcpy(a->nome, nome);
        strcpy(a->curso, curso); 
        return a;
    }
    return NULL;
}

void libera_a(Aluno *aluno){
    free(aluno);
    aluno = NULL;
}

void acessa_a(Aluno *aluno, int *matricula, char *nome, char *curso){
    if(aluno != NULL){
        *matricula = aluno->matricula;
        strcpy(nome, aluno->nome);
        strcpy(curso, aluno->curso);
    }
}

void atribui_a(Aluno *aluno, int matricula, char *nome, char *curso){
    if(aluno != NULL && matricula > 0 && strlen(nome) > 0 && strlen(nome) <= 49
       && strlen(curso) > 0 && strlen(curso) <= 29){
        aluno->matricula = matricula;
        strcpy(aluno->nome, nome);
        strcpy(aluno->curso, curso);
    }
}

int tamanho_a(){
    int tam = sizeof(Aluno);
    return tam;
}