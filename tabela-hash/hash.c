#include "hash.h"

void inicializar_tabela(No* tabela[]) {
  for(int i = 0; i < TAMANHO_TABELA; i++){
    tabela[i] = NULL;
  };
};