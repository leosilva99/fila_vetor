/* Programa principal */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "fila.h"

int testa_novo_a(){
    int matricula;
    char nome[50],curso[30];
    printf("testa_novo_a\n");
    printf("Digite os dados de um aluno(matricula, nome, curso):\n");
    scanf("%d", &matricula);
    scanf("%s", nome);
    scanf("%s", curso);
    printf("\n");
    Aluno *aluno = novo_a(matricula, nome, curso);
    if(aluno != NULL){
        printf("Deu certo!\n");
        return 1;
    } 
    else{
        return 0;
    }  
}

int testa_acessa_a(){
    int matricula;
    char nome[50],curso[30];
    printf("testa_acessa_a\n");
    printf("Digite os dados de um aluno(matricula, nome, curso):\n");
    scanf("%d", &matricula);
    scanf("%s", nome);
    scanf("%s", curso);
    printf("\n");
    Aluno *aluno = novo_a(matricula, nome, curso);
    int matricula2;
    char nome2[50],curso2[30];
	acessa_a(aluno, &matricula2, nome2, curso2);
	if(matricula == matricula2 && strcmp(nome,nome2) == 0 && strcmp(curso,curso2) == 0){
        printf("Deu certo!\n");
	    return 1;
	}
    else{
        return 0;
	}  
}

int testa_atribui_a(){
    int matricula;
    char nome[50],curso[30];
    printf("testa_atribui_a\n");
    printf("Digite os dados de um aluno(matricula, nome, curso):\n");
    scanf("%d", &matricula);
    scanf("%s", nome);
    scanf("%s", curso);
    printf("\n");
    Aluno *aluno = novo_a(1, "Nome", "Curso");
    atribui_a(aluno, matricula, nome, curso);
    int matricula2;
    char nome2[50],curso2[30];
	acessa_a(aluno, &matricula2, nome2, curso2);
	if(matricula == matricula2 && strcmp(nome,nome2) == 0 && strcmp(curso,curso2) == 0){
	    printf("Deu certo!\n");
        return 1;
	}
    else{
		return 0;
	}  
}

int testa_nova_f(){
    int tamanho;
    printf("testa_nova_f\n");
    printf("Digite um tamanho para a nova fila:\n");
    scanf("%d", &tamanho);
    printf("\n");
	Fila *fila = nova_f(tamanho);
	if(fila != NULL){
	    printf("Deu certo!\n");
        return 1;
	}
    else{
		return 0;
	}
}

int testa_adiciona_f() {
    Fila *fila = nova_f(3);
    int matricula1,matricula2,matricula3;
    char nome1[50],nome2[50],nome3[50];
    char curso1[30],curso2[30],curso3[30];
	if(fila != NULL){
        printf("testa_adiciona_f\n");
        printf("Digite os dados de um aluno(matricula, nome, curso):\n");
	    scanf("%d", &matricula1);
        scanf("%s", nome1);
        scanf("%s", curso1);
        printf("\n");
		Aluno *aluno1 = novo_a(matricula1, nome1, curso1);
		if(adiciona_f(fila, aluno1)){
            printf("Digite os dados de um aluno(matricula, nome, curso):\n");
		    scanf("%d", &matricula2);
            scanf("%s", nome2);
            scanf("%s", curso2);
            printf("\n");
			Aluno *aluno2 = novo_a(matricula2, nome2, curso2);
			if(adiciona_f(fila, aluno2)){
                printf("Digite os dados de um aluno(matricula, nome, curso):\n");
			    scanf("%d", &matricula3);
                scanf("%s", nome3);
                scanf("%s", curso3);
                printf("\n");
				Aluno *aluno3 = novo_a(matricula3, nome3, curso3);
				if(adiciona_f(fila, aluno3)){
                    printf("Deu certo!\n");
                    return 1;
				}	
			}		
		}
	}
	return 0;
}

int testa_retira_f(){
    Fila *fila = nova_f(3);
    int matricula1,matricula2,matricula3;
    char nome1[50],nome2[50],nome3[50];
    char curso1[30],curso2[30],curso3[30];
	if(fila != NULL){
        printf("testa_retira_f\n");
        printf("Digite os dados de um aluno(matricula, nome, curso):\n");
	    scanf("%d", &matricula1);
        scanf("%s", nome1);
        scanf("%s", curso1);
        printf("\n");
		Aluno *aluno1 = novo_a(matricula1, nome1, curso1);
		adiciona_f(fila, aluno1);
        printf("Digite os dados de um aluno(matricula, nome, curso):\n");
	    scanf("%d", &matricula2);
        scanf("%s", nome2);
        scanf("%s", curso2);
        printf("\n");
		Aluno *aluno2 = novo_a(matricula2, nome2, curso2);
		adiciona_f(fila, aluno2);
        printf("Digite os dados de um aluno(matricula, nome, curso):\n");
	    scanf("%d", &matricula3);
        scanf("%s", nome3);
        scanf("%s", curso3);
        printf("\n");
		Aluno *aluno3 = novo_a(matricula3, nome3, curso3);
		adiciona_f(fila, aluno3);
		if(retira_f(fila)){
			if(retira_f(fila)){
				if (retira_f(fila)){
					if(!retira_f(fila)){
                        printf("Deu certo!\n");
                        return 1;
					}
				}
			}
		}
	}
	return 0;
}

int testa_cheia_f(){
	Fila *fila = nova_f(3);
	if(fila != NULL && !cheia_f(fila)){
        printf("testa_cheia_f\n");
		Aluno *abraao = novo_a(1, "Abraão", "Computação");
		adiciona_f(fila, abraao);
		Aluno *jaco = novo_a(2, "Jaco", "Computação");
		adiciona_f(fila, jaco);
		if (!cheia_f(fila)){
			Aluno *jose = novo_a(3, "Jose", "Computação");
			adiciona_f(fila, jose);
			if(cheia_f(fila)){
                printf("Deu certo!\n");
                return 1;
			}
		}
	}
	return 0;
}

int main(void){
    int op;
    int matricula;
    char nome[50],curso[30];
    printf("Digite o número de uma operação(1-7): ");
    scanf("%d", &op);
    printf("\n");
    switch(op){
        case 1: printf("%d", testa_novo_a());
            break;
        
        case 2: printf("%d", testa_acessa_a());
            break;
                
        case 3: printf("%d", testa_atribui_a());
            break;
        
        case 4: printf("%d", testa_nova_f());
            break;

        case 5: printf("%d", testa_adiciona_f());
            break;
        
        case 6: printf("%d", testa_retira_f());
            break;
        
        case 7: printf("%d", testa_cheia_f());
            break;
    }
    printf("\n");
	return 0;
}