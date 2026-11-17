
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// Declaracao da funcao existente em hash.c
void exibir_tabela(No* tabela[]);

// Leitura de numeros inteiros
int ler_inteiro(const char* mensagem, int* valor) {
    char entrada[100];
    char* fim;

    printf("%s", mensagem);

    if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        return 0;

    long numero = strtol(entrada, &fim, 10);

    if (fim == entrada || (*fim != '\n' && *fim != '\0'))
        return 0;

    *valor = (int) numero;
    return 1;
}

// Exibe o menu
void exibir_menu() {
    printf("\n========== MENU TABELA HASH ==========\n");
    printf("1 - Inserir novo Aluno\n");
    printf("2 - Buscar Aluno\n");
    printf("3 - Remover Aluno\n");
    printf("4 - Exibir Tabela Hash\n");
    printf("5 - Encerrar Sistema\n");
    printf("======================================\n");
}

// Insere um aluno
void acao_inserir(No* tabela[]) {
    int matricula, idade;
    char nome[100];

    if (!ler_inteiro("Digite a matricula: ", &matricula) || matricula < 0) {
        printf("Matricula invalida!\n");
        return;
    }

    printf("Digite o nome: ");

    if (fgets(nome, sizeof(nome), stdin) == NULL)
        return;

    nome[strcspn(nome, "\n")] = '\0';

    if (nome[0] == '\0') {
        printf("Nome invalido!\n");
        return;
    }

    if (!ler_inteiro("Digite a idade: ", &idade) || idade < 0) {
        printf("Idade invalida!\n");
        return;
    }

    if (inserir_aluno(tabela, matricula, nome, idade)) {
        printf("Aluno cadastrado com sucesso!\n");
    } else {
        printf("Erro: matricula ja cadastrada ou dados invalidos!\n");
    }
}

// Busca um aluno
void acao_buscar(No* tabela[]) {
    int matricula;

    if (!ler_inteiro("Digite a matricula: ", &matricula) || matricula < 0) {
        printf("Matricula invalida!\n");
        return;
    }

    int indice = calcular_hash(matricula);
    No* atual = tabela[indice];

    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            printf("\nAluno encontrado!\n");
            printf("Matricula: %d\n", atual->aluno.matricula);
            printf("Nome: %s\n", atual->aluno.nome);
            printf("Idade: %d\n", atual->aluno.idade);
            return;
        }

        atual = atual->prox;
    }

    printf("Aluno nao encontrado!\n");
}

// Remove um aluno
void acao_remover(No* tabela[]) {
    int matricula;

    if (!ler_inteiro("Digite a matricula: ", &matricula) || matricula < 0) {
        printf("Matricula invalida!\n");
        return;
    }

    if (remover_aluno(tabela, matricula)) {
        printf("Aluno removido com sucesso!\n");
    } else {
        printf("Aluno nao encontrado!\n");
    }
}

// Funcao principal
int main() {
    No* tabela[TAMANHO_TABELA];
    int opcao = 0;

    inicializar_tabela(tabela);

    do {
        exibir_menu();

        if (!ler_inteiro("Escolha uma opcao: ", &opcao)) {
            printf("Entrada invalida!\n");
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1:
                acao_inserir(tabela);
                break;

            case 2:
                acao_buscar(tabela);
                break;

            case 3:
                acao_remover(tabela);
                break;

            case 4:
                exibir_tabela(tabela);
                break;

            case 5:
                liberar_tabela(tabela);
                printf("Sistema encerrado!\n");
                break;

            default:
                printf("Opcao invalida! Escolha de 1 a 5.\n");
        }

    } while (opcao != 5);

    return 0;
}
