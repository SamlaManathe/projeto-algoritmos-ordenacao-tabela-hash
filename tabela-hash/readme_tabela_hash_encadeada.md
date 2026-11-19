# Sistema de Cadastro de Alunos com Tabela Hash Encadeada

> Implementação manual (sem bibliotecas prontas) de uma **Tabela Hash com Encadeamento Exterior** para gerenciamento de registros universitários, utilizando função de dispersão modular com tamanho primo ($M = 11$).

---

## Sumário

1. [Visão Geral e Regras do Projeto](#1-visão-geral-e-regras-do-projeto)
2. [Como a Tabela Hash Funciona (Analogia Visual)](#2-como-a-tabela-hash-funciona-analogia-visual)
3. [Arquitetura e Estrutura de Dados](#3-arquitetura-e-estrutura-de-dados)
4. [Passo a Passo: Função Hash e Tratamento de Colisões](#4-passo-a-passo-função-hash-e-tratamento-de-colisões)
5. [Exemplos Visuais de Entrada e Saída (Console)](#5-exemplos-visuais-de-entrada-e-saída-console)
6. [Análise de Complexidade das Operações](#6-análise-de-complexidade-das-operações)
7. [Equipe](#7-equipe)

---

## 1. Visão Geral e Regras do Projeto

Este módulo implementa do zero uma **Tabela Hash Encadeada** para armazenar, buscar e remover dados de alunos de uma universidade.

### Especificações Técnicas Atendidas

| Requisito                      | Definição no Projeto                                                                                |
| :----------------------------- | :-------------------------------------------------------------------------------------------------- |
| **Entidade Armazenada**        | **Aluno** (`matrícula`, `nome`, `idade`)                                                            |
| **Chave de Busca ($k$)**       | `matrícula` (número inteiro único; não permite duplicatas)                                          |
| **Tamanho da Tabela ($M$)**    | $M = 11$ posições (índices de `0` a `10`)                                                           |
| **Função de Transformação**    | $h(\text{chave}) = \text{chave} \bmod 11$                                                           |
| **Tratamento de Colisões**     | **Encadeamento Exterior** — novos elementos colididos são inseridos **no final** da lista encadeada |
| **Restrição de Implementação** | **100% manual** (sem uso de estruturas prontas como `HashMap`, `Hashtable` ou `dict`)               |

### Menu Interativo Obrigatório

1. **Inserir novo Aluno** _(calcula $h(\text{matrícula})$, impede matrícula duplicada e insere no final da lista)_
2. **Buscar Aluno** _(calcula $h(\text{matrícula})$ e pesquisa diretamente no índice correspondente)_
3. **Remover Aluno** _(calcula $h(\text{matrícula})$, localiza o nó e reencadeia os ponteiros)_
4. **Exibir Tabela Hash** _(mostra todos os 11 compartimentos e suas respectivas listas encadeadas)_
5. **Encerrar Sistema**

---

## 2. Como a Tabela Hash Funciona (Analogia Visual)

Para explicar o conceito de forma palpável durante a apresentação:

- **O Problema da Busca Linear:** Em um vetor ou lista comum com $1.000$ alunos, encontrar uma matrícula pode exigir até $1.000$ comparações ($O(n)$).
- **A Solução com Tabela Hash (Armário com 11 Gavetas):**
  1. Em vez de procurar de gaveta em gaveta, usamos uma **fórmula matemática** ($h(\text{chave}) = \text{chave} \bmod 11$) que diz **exatamente em qual gaveta (`0` a `10`)** o aluno está.
  2. **Por que $M = 11$?** Porque $11$ é um **número primo**, o que ajuda a espalhar as matrículas de forma mais uniforme entre as gavetas e reduz o acúmulo de colisões.
  3. **E se duas matrículas caírem na mesma gaveta (Colisão)?** Dentro de cada gaveta existe uma **fila (lista encadeada)**. O novo aluno entra sempre **no final da fila** daquela gaveta.

---

## 3. Arquitetura e Estrutura de Dados

A estrutura combina um **vetor estático de $M = 11$ ponteiros** (a Tabela Hash) com **nós dinâmicos** (Lista Simplesmente Encadeada):

```text
+-------------------------------------------------------------------+
|                         REGISTRO: ALUNO                           |
|  [ matricula: int | nome: String | idade: int | proximo: *Aluno ] |
+-------------------------------------------------------------------+

TABELA HASH (M = 11)                 LISTAS ENCADEADAS (COLISÕES)
+-------+---------+
|  [0]  |   ●-----+---> [ Mat: 110 | Ana | 20 ] ---> NULL
+-------+---------+
|  [1]  |   ●-----+---> [ Mat: 100 | Bruno | 22 ] ---> [ Mat: 210 | Carla | 19 ] ---> NULL
+-------+---------+
|  [2]  |   ●-----+---> [ Mat: 2026 | Diego | 21 ] ---> NULL
+-------+---------+
|  [3]  |  NULL   |
+-------+---------+
|  ...  |  NULL   |
+-------+---------+
| [10]  |   ●-----+---> [ Mat: 109 | Elena | 23 ] ---> NULL
+-------+---------+
```

### Fluxo Interno Obrigatório das Operações

Antes de **Inserir**, **Buscar** ou **Remover**, o sistema **sempre** executa primeiro o cálculo do endereço:

```text
Matrícula (k) ──► [ Função Hash: indice = k % 11 ] ──► Acesso direto a Tabela[indice]
```

---

## 4. Passo a Passo: Função Hash e Tratamento de Colisões

Acompanhe um exemplo prático de inserção sequencial demonstrando o cálculo de $h(k) = k \bmod 11$ e a regra de **inserção no final da lista** quando há colisão:

| Ordem  | Matrícula ($k$) | Aluno | Cálculo $h(k) = k \bmod 11$         | Índice  |      Ocorre Colisão?       | Ação Executada na Lista                             |
| :----: | :-------------: | :---- | :---------------------------------- | :-----: | :------------------------: | :-------------------------------------------------- |
| **1º** |      `110`      | Ana   | $110 = 11 \times 10 + \mathbf{0}$   | **`0`** |     Não (lista vazia)      | Torna-se o 1º nó da posição `[0]`                   |
| **2º** |      `100`      | Bruno | $100 = 11 \times 9 + \mathbf{1}$    | **`1`** |     Não (lista vazia)      | Torna-se o 1º nó da posição `[1]`                   |
| **3º** |     `2026`      | Diego | $2026 = 11 \times 184 + \mathbf{2}$ | **`2`** |     Não (lista vazia)      | Torna-se o 1º nó da posição `[2]`                   |
| **4º** |      `210`      | Carla | $210 = 11 \times 19 + \mathbf{1}$   | **`1`** | **Sim!** (já existe `100`) | Inserida **no final** de `[1]`: `100 -> 210`        |
| **5º** |      `320`      | Lucas | $320 = 11 \times 29 + \mathbf{1}$   | **`1`** |  **Sim!** (`100`, `210`)   | Inserido **no final** de `[1]`: `100 -> 210 -> 320` |
| **6º** |      `210`      | Carla | $210 = 11 \times 19 + \mathbf{1}$   | **`1`** |       **Bloqueada!**       | Matrícula `210` já existe — inserção recusada       |

---

## 5. Exemplos Visuais de Entrada e Saída (Console)

Abaixo está a simulação completa do funcionamento do sistema no terminal, cobrindo todas as opções do menu exigidas.

### 5.1. Menu Principal e Inserção com Colisão

```text
=========================================
      SISTEMA UNIVERSITARIO - HASH
=========================================
1. Inserir novo Aluno
2. Buscar Aluno
3. Remover Aluno
4. Exibir Tabela Hash
5. Encerrar Sistema
Escolha uma opcao: 1

--- INSERIR ALUNO ---
Digite a matricula (inteiro): 100
Digite o nome: Bruno
Digite a idade: 22
-> Endereco calculado: h(100) = 100 mod 11 = 1
-> [OK] Aluno cadastrado com sucesso na posicao [1]!

Escolha uma opcao: 1

--- INSERIR ALUNO ---
Digite a matricula (inteiro): 210
Digite o nome: Carla
Digite a idade: 19
-> Endereco calculado: h(210) = 210 mod 11 = 1
-> [AVISO] Colisao detectada no indice [1]! Inserindo no final da lista...
-> [OK] Aluno cadastrado com sucesso na posicao [1]!
```

### 5.2. Validação de Matrícula Duplicada

```text
Escolha uma opcao: 1

--- INSERIR ALUNO ---
Digite a matricula (inteiro): 210
Digite o nome: Carla Duarte
Digite a idade: 19
-> Endereco calculado: h(210) = 210 mod 11 = 1
-> [ERRO] Ja existe um aluno cadastrado com a matricula 210!
```

### 5.3. Exibição Completa da Tabela Hash (`M = 11`)

```text
Escolha uma opcao: 4

================ TABELA HASH (M = 11) ================
[ 0] -> [Mat: 110 | Nome: Ana | Idade: 20] -> NULL
[ 1] -> [Mat: 100 | Nome: Bruno | Idade: 22] -> [Mat: 210 | Nome: Carla | Idade: 19] -> [Mat: 320 | Nome: Lucas | Idade: 21] -> NULL
[ 2] -> [Mat: 2026 | Nome: Diego | Idade: 21] -> NULL
[ 3] -> NULL
[ 4] -> NULL
[ 5] -> NULL
[ 6] -> [Mat: 105 | Nome: Mariana | Idade: 20] -> NULL
[ 7] -> NULL
[ 8] -> NULL
[ 9] -> NULL
[10] -> [Mat: 109 | Nome: Elena | Idade: 23] -> NULL
======================================================
```

### 5.4. Busca e Remoção de Aluno

```text
Escolha uma opcao: 2

--- BUSCAR ALUNO ---
Digite a matricula: 210
-> Endereco calculado: h(210) = 210 mod 11 = 1
-> [ENCONTRADO] Matricula: 210 | Nome: Carla | Idade: 19 (Indice [1], posicao 2 da lista)

Escolha uma opcao: 3

--- REMOVER ALUNO ---
Digite a matricula: 210
-> Endereco calculado: h(210) = 210 mod 11 = 1
-> [OK] Aluno (Matricula: 210 - Carla) removido com sucesso!
-> Lista atualizada no indice [1]: [Mat: 100 | Bruno] -> [Mat: 320 | Lucas] -> NULL
```

---

## 6. Análise de Complexidade das Operações

Considerando $n$ alunos cadastrados e $M = 11$ posições na tabela, definimos o **fator de carga** como $\alpha = \frac{n}{M}$ (número médio de alunos por lista):

| Operação                | Melhor Caso |   Caso Médio    | Pior Caso | Explicação para a Apresentação                                                                                        |
| :---------------------- | :---------: | :-------------: | :-------: | :-------------------------------------------------------------------------------------------------------------------- |
| **Cálculo Hash** $h(k)$ |   $O(1)$    |     $O(1)$      |  $O(1)$   | Operação aritmética direta (`k % 11`), tempo constante.                                                               |
| **Inserção**            |   $O(1)$    | $O(1 + \alpha)$ |  $O(n)$   | Como a inserção ocorre **no final da lista** e exige checar duplicatas, percorre os nós existentes naquele índice.    |
| **Busca**               |   $O(1)$    | $O(1 + \alpha)$ |  $O(n)$   | No melhor caso, o aluno é o 1º da lista; no pior caso, todas as $n$ matrículas colidiram no mesmo índice.             |
| **Remoção**             |   $O(1)$    | $O(1 + \alpha)$ |  $O(n)$   | Localiza o nó na lista do índice calculado e ajusta o ponteiro do nó anterior (`anterior->proximo = atual->proximo`). |

---

## 7. Equipe

- **Artur Dutra**
- **Daniel Tavares**
- **Paulo Artur**
- **Samuel Victor**
- **Samla Manathe**
- **Tainara David**
- **Gabriel Eduardo**
