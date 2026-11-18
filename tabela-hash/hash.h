#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 11

/*=============================================
         DANIEL - STRUCTS E CABEÇALHOS
==============================================*/

typedef struct {
    int matricula;
    char nome[100];
    int idade;
} Aluno;

typedef struct No {
    Aluno aluno;
    struct No* prox;
} No;

void inicializar_tabela(No* tabela[]);

int calcular_hash(int matricula);

int inserir_aluno(No* tabela[], int matricula, const char* nome, int idade);

int remover_aluno(No* tabela[], int matricula);

void liberar_tabela(No* tabela[]);

#endif
