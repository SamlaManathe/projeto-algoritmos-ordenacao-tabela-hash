#include "hash.h"
#include <stdlib.h>

void inicializar_tabela(No* tabela[]) {
  int i;
  for(i = 0; i < TAMANHO_TABELA; i++){
    tabela[i] = NULL;
  }
}

int calcular_hash(int matricula) {
  return matricula % TAMANHO_TABELA;
}

void liberar_tabela(No* tabela[]) {
  int i;
  for(i = 0; i < TAMANHO_TABELA; i++) {
    free(tabela[i]);
  }
}

