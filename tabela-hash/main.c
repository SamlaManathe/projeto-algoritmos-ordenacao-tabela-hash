#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main() {
    No* tabela[TAMANHO_TABELA];

    inicializar_tabela(tabela);

    printf("Tabela Hash inicializada com sucesso!\n");
    
    return 0;
}
