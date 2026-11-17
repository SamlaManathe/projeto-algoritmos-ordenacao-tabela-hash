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

void inicializar_tabela(No* tabela[]) {
    int i;

    for (i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}

int calcular_hash(int matricula) {
    return matricula % TAMANHO_TABELA;
}

int inserir_aluno(No* tabela[], int matricula, const char* nome, int idade) {

    if (nome == NULL || matricula < 0 || strlen(nome) >= 100) {
        return 0;
    }

    int indice = calcular_hash(matricula);

    No* atual = tabela[indice];

    // Verifica se a matrícula já existe
    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            return 0;
        }

        atual = atual->prox;
    }

    // Aloca memória para o novo nó
    No* novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    // Preenche os dados do aluno
    novo->aluno.matricula = matricula;
    strcpy(novo->aluno.nome, nome);
    novo->aluno.idade = idade;
    novo->prox = NULL;

    // Insere se a posição estiver vazia
    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        // Percorre até o último nó
        atual = tabela[indice];

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    return 1;
}

void liberar_tabela(No* tabela[]) {
    int i;

    for (i = 0; i < TAMANHO_TABELA; i++) {
        No* atual = tabela[i];

        while (atual != NULL) {
            No* proximo = atual->prox;

            free(atual);

            atual = proximo;
        }

        tabela[i] = NULL;
    }
}
