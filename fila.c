#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct aluno{
    int matricula;
    char nome[50];
    char curso[30];
};

struct fila{
    int tamanho;
    Aluno** aluno;  /* Vetor de ponteiros para o tipo Aluno */
};

int ini, fim;  /* Variáveis globais que indicam os índices de início e fim atuais da fila */ 

Fila *nova_f(int tamanho){  /* O(1): operação constante */
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->aluno = (Aluno**) malloc(tamanho*sizeof(Aluno*));
    if(f == NULL || tamanho <= 0 || f->aluno == NULL){
        return NULL;
    }
    f->tamanho = tamanho;
    ini = -1;
    fim = -1;  /* O vetor da fila é inicializado vazio */
    return f;
}

void destroi_f(Fila *fila){  /* O(1): operação constante */
    free(fila);
    fila = NULL;
}

int adiciona_f(Fila *fila, Aluno *aluno){  /* O(1): operação constante */
    int prox = fim + 1;  /* Índice da posição que reberá o novo aluno */
    if(prox == fila->tamanho){  /* Caso em que o vetor ainda tenha posição vazia no início dele */
        prox = 0;
    }
    if(prox == ini){  /* Indica fila cheia */
        return 0;
    }
    fila->aluno[prox] = novo_a(aluno->matricula, aluno->nome, aluno->curso);
    fim = prox;
    if(ini == -1){  /* Se a fila for vazia antes dessa inclusão */
        ini = 0;
    }
    if(fila->aluno[prox] != NULL){  /* Testando se a inclusão foi bem sucedida */
        return 1;
    }
    return 0;
}

int retira_f(Fila *fila){  /* O(1): operação constante */
    if(fila->aluno[ini] == NULL){  /* Caso em que a fila já está vazia */
        return 0;
    }
    fila->aluno[ini] = NULL;
    if(ini == fim){ /* Se a fila possuía um único aluno antes dessa remoção */
        ini = -1;
        fim = -1;
        fila->aluno[ini] = NULL; /* Atribuindo um valor que possa ser indentificado com um índice fora do intervalo */
    }
    else{
        ini = ini + 1;
        if(ini == fila->tamanho){
            ini = 0;
        }
    }
    return 1;
}

Aluno *busca_f(Fila *fila, int matricula){  /* O(n): operação baseada no número de elementos */
                                            /* Pode-se fazer melhor a custo de O(n/2) */
    for(int i=0; fila->aluno[i] != NULL || i < fila->tamanho; i++){
        if(fila->aluno[i]->matricula == matricula){
            return fila->aluno[i];
        }
    }
    return NULL;
}

int cheia_f(Fila *fila){  /* O(n): operação baseada no número de elementos */
    int cont=0;
    for(int i=0; fila->aluno[i] != NULL || i < fila->tamanho; i++){
        cont ++;  /* Vai contar quantos elementos existem na fila */
    }
    if(cont == fila->tamanho){
        return 1;
    }
    return 0;
}