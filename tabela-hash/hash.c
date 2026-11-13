#include <stdio.h>
#include "hash.h" 

void exibir_tabela(Node* tabela[]) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        
        printf("[%02d]: ", i);
        
        
        Node* atual = tabela[i];
        
        
        while (atual != NULL) {
            printf("[Matrícula: %d | Nome: %s | Idade: %d] -> ", atual->matricula, atual->nome, atual->idade);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

