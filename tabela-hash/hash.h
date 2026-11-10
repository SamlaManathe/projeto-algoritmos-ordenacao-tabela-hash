#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 11

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

#endif