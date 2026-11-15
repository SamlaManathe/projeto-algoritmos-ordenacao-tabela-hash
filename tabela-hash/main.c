#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main() {
    No* tabela[TAMANHO_TABELA];

    inicializar_tabela(tabela);

    printf("Tabela Hash inicializada com sucesso!\n");

    printf("%d\n",calcular_hash(123));

    printf("Índice calculado com sucesso!\n");

    liberar_tabela(tabela);

    printf("Tabela Hash inicializada com sucesso!\n");

    getchar();
    
    return 0;
}
