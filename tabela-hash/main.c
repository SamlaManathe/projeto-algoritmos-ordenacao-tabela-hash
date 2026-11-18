
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/*===============================================
PAULO - FUNÇÕES AUXILIARES PARA LEITURA DE DADOS
      (ALUNO) INSERIR, BUSCAR E REMOVER
================================================*/

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
    printf("\n==========================================================================\n");
    printf("                      MENU PRINCIPAL - TABELA HASH   ");
    printf("\n==========================================================================\n\n");
    printf("1 - Inserir novo Aluno\n");
    printf("2 - Buscar Aluno\n");
    printf("3 - Remover Aluno\n");
    printf("4 - Exibir Tabela Hash\n");
    printf("5 - Encerrar Sistema\n");
}

// Insere um aluno
void acao_inserir(No* tabela[]) {
    int matricula, idade;
    char nome[100];

    if (!ler_inteiro("\nDigite a matricula: ", &matricula) || matricula < 0) {
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
        printf("\nAluno cadastrado com sucesso!\n");
    } else {
        printf("\nErro: matricula ja cadastrada ou dados invalidos!\n");
    }
}

// Busca um aluno
void acao_buscar(No* tabela[]) {
    int matricula;

    if (!ler_inteiro("\nDigite a matricula: ", &matricula) || matricula < 0) {
        printf("\nMatricula invalida!\n");
        return;
    }

    int indice = calcular_hash(matricula);
    No* atual = tabela[indice];

    while (atual != NULL) {
        if (atual->aluno.matricula == matricula) {
            printf("\nAluno encontrado!\n");
            printf("\nMatricula: %d\n", atual->aluno.matricula);
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

    if (!ler_inteiro("\nDigite a matricula: ", &matricula) || matricula < 0) {
        printf("\nMatricula invalida!\n");
        return;
    }

    if (remover_aluno(tabela, matricula)) {
        printf("\nAluno removido com sucesso!\n");
    } else {
        printf("\nAluno nao encontrado!\n");
    }
}

/*=============================================
                PAULO - MENU
==============================================*/

// Funcao principal
int main() {
    No* tabela[TAMANHO_TABELA];
    int opcao = 0;

    inicializar_tabela(tabela);

    do {
        exibir_menu();

        if (!ler_inteiro("\nEscolha uma opcao: ", &opcao)) {
            printf("Entrada invalida!\n");
            opcao = 0;
            continue;
        }

        if(opcao != 5){
            printf("\n==========================================================================\n");
            getchar();
            system("clear");
        }

        switch (opcao) {
            case 1:
                printf("\n==========================================================================\n");
                printf("                      INSERIR ALUNO - TABELA HASH   ");
                printf("\n==========================================================================\n");
                acao_inserir(tabela);
                printf("\n==========================================================================\n");
                getchar();
                system("clear");
                break;

            case 2:
                printf("\n==========================================================================\n");
                printf("                      BUSCAR ALUNO - TABELA HASH   ");
                printf("\n==========================================================================\n");
                acao_buscar(tabela);
                printf("\n==========================================================================\n");
                getchar();
                system("clear");
                break;

            case 3:
                printf("\n==========================================================================\n");
                printf("                      REMOVER ALUNO - TABELA HASH   ");
                printf("\n==========================================================================\n");
                acao_remover(tabela);
                printf("\n==========================================================================\n");
                getchar();
                system("clear");
                break;

            case 4:
                printf("\n==========================================================================\n");
                printf("                             EXIBIR TABELA HASH   ");
                printf("\n==========================================================================\n\n");
                exibir_tabela(tabela);
                printf("\n==========================================================================\n");
                getchar();
                system("clear");
                break;

            case 5:
                printf("\n==========================================================================\n");
                printf("                             SISTEMA ENCERRADO");
                printf("\n==========================================================================\n");
                liberar_tabela(tabela);
                getchar();
                system("clear");
                break;

            default:
                printf("\nOpção inválida! Escolha de 1 a 5.\n");
        }

    } while (opcao != 5);

    return 0;
}
