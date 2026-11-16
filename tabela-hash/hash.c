#include "hash.h"
#include <stdlib.h>

void inicializar_tabela(No* tabela[]) {
    int i;

    for(i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}

int calcular_hash(int matricula) {
    return matricula % TAMANHO_TABELA;
}

No* buscar_aluno(No* tabela[], int matricula) {
    int indice = calcular_hash(matricula);

    No* atual = tabela[indice];

    while(atual != NULL) {
        if(atual->aluno.matricula == matricula) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

void liberar_tabela(No* tabela[]) {
    int i;
    No* atual;
    No* proximo;

    for(i = 0; i < TAMANHO_TABELA; i++) {
        atual = tabela[i];

        while(atual != NULL) {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }

        tabela[i] = NULL;
    }
}
