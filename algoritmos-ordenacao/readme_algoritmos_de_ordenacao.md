# Análise Comparativa de Algoritmos de Ordenação em Java

> Estudo prático e teórico sobre o comportamento, a escalabilidade e a complexidade temporal de cinco algoritmos clássicos de ordenação diante do crescimento do volume de dados.

---

## Sumário

1. [Visão Geral do Projeto](#1-visão-geral-do-projeto)
2. [Estrutura do Código](#2-estrutura-do-código)
3. [Como Cada Algoritmo Funciona (Resumo Visual)](#3-como-cada-algoritmo-funciona-resumo-visual)
4. [Dados de Entrada e Saída ($n = 10$, $n^2 = 100$ e $n^3 = 1.000$)](#4-dados-de-entrada-e-saída-n--10-n2--100-e-n3--1000)
5. [Simulações de Desempenho com IA ($n$, $n^2$, $n^3$ e $n^{10}$)](#5-simulações-de-desempenho-com-ia-n-n2-n3-e-n10)
6. [Principais Conclusões para a Apresentação](#6-principais-conclusões-para-a-apresentação)
7. [Como Executar o Projeto](#7-como-executar-o-projeto)
8. [Equipe](#8-equipe)

---

## 1. Visão Geral do Projeto

Este projeto implementa cinco algoritmos fundamentais de ordenação em **Java** (**Bubble Sort**, **Insertion Sort**, **Selection Sort**, **Merge Sort** e **Quick Sort**) e combina **testes empíricos** com **simulações teóricas apoiadas por Inteligência Artificial** para responder a uma pergunta central da Computação:

> _"Como a escolha do algoritmo de ordenação impacta o tempo de execução quando o volume de dados cresce de dezenas para bilhões de elementos?"_

### Destaques da Implementação

- **Carga de teste configurável:** A classe `App.java` centraliza o tamanho da amostra na constante `TAMANHO_VETOR`, permitindo alternar facilmente entre $n = 10$, $n^2 = 100$, $n^3 = 1.000$ ou outros valores durante a execução.
- **Exibição controlada para grandes volumes:** O método auxiliar `Utils.imprimirVetor` exibe o vetor completo quando o tamanho é $\le 100$ e, para volumes maiores, exibe **apenas os 100 primeiros elementos**, evitando poluição visual no terminal.
- **Análise assintótica aplicada:** Complementa os testes locais com projeções matemáticas para entradas massivas ($n^{10} = 10^{10}$ elementos), onde a execução real seria inviável.

---

## 2. Estrutura do Código

```text
algoritmos-ordenacao/
└── src/
    ├── App.java            # Ponto de entrada: configura TAMANHO_VETOR e executa os testes
    ├── Utils.java          # Geração de vetores aleatórios e impressão limitada a 100 itens
    ├── BubbleSort.java     # Ordenação por trocas sucessivas entre elementos vizinhos
    ├── InsertionSort.java  # Ordenação por inserção na sublista já ordenada
    ├── SelectionSort.java  # Ordenação por seleção repetida do menor elemento
    ├── MergeSort.java      # Divisão e conquista com intercalação (memória auxiliar)
    └── QuickSort.java      # Divisão e conquista com particionamento por pivô
```

---

## 3. Como Cada Algoritmo Funciona (Resumo Visual)

Para facilitar a explicação durante a apresentação, cada algoritmo foi resumido abaixo com sua **ideia central**, uma **analogia palpável** e suas **complexidades**:

| Algoritmo          | Analogia do Dia a Dia                   | Como Funciona na Prática                                                                                                                      |  Melhor Caso  |  Caso Médio   |   Pior Caso   | Memória Extra |
| :----------------- | :-------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- | :-----------: | :-----------: | :-----------: | :-----------: |
| **Bubble Sort**    | Bolhas subindo na água                  | Compara pares de vizinhos e os troca se estiverem fora de ordem. A cada passada, o maior valor "flutua" para o final do vetor.                |   $O(n)$\*    |   $O(n^2)$    |   $O(n^2)$    |    $O(1)$     |
| **Insertion Sort** | Organizar cartas na mão                 | Pega um elemento por vez e o insere na posição exata dentro da parte esquerda do vetor, que já está ordenada.                                 |    $O(n)$     |   $O(n^2)$    |   $O(n^2)$    |    $O(1)$     |
| **Selection Sort** | Escolher o menor item da fila           | Varre toda a parte não ordenada para encontrar o menor elemento e o coloca na próxima posição fixa. Faz sempre o mesmo número de comparações. |   $O(n^2)$    |   $O(n^2)$    |   $O(n^2)$    |    $O(1)$     |
| **Merge Sort**     | Dividir para conquistar e juntar pilhas | Divide o vetor ao meio recursivamente até sobrarem unidades individuais e depois intercala (mescla) as partes em ordem.                       | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ |    $O(n)$     |
| **Quick Sort**     | Separar menores e maiores que um líder  | Escolhe um **pivô**, joga os menores para a esquerda e os maiores para a direita, repetindo o processo nas duas metades.                      | $O(n \log n)$ | $O(n \log n)$ |   $O(n^2)$    |  $O(\log n)$  |

_\*Nota: O Bubble Sort atinge $O(n)$ no melhor caso apenas quando implementado com verificação de parada antecipada (flag de trocas)._

---

## 4. Dados de Entrada e Saída ($n = 10$, $n^2 = 100$ e $n^3 = 1.000$)

Na classe `App.java`, o tamanho do conjunto de dados é controlado diretamente pela constante `TAMANHO_VETOR`:

```java
// Altere este valor para testar diferentes escalas durante a apresentação:
private static final int TAMANHO_VETOR = 10; // Exemplos: 10, 100, 1000
```

Abaixo estão representados visualmente os fluxos de **Entrada (vetor aleatório)** e **Saída (vetor ordenado)** para os cenários executáveis em memória, respeitando a regra de **exibir apenas os 100 primeiros elementos** em grandes volumes.

### Cenário A: Entrada Pequena — $n = 10$ elementos (Exibição Completa)

Como $10 \le 100$, todos os elementos são exibidos no console:

```text
ENTRADA (10 de 10 elementos):
[ 42,  7, 89, 15, 63,  3, 94, 28, 51, 19 ]
   │
   ▼  Execução dos algoritmos de ordenação
SAÍDA ORDENADA (10 de 10 elementos):
[  3,  7, 15, 19, 28, 42, 51, 63, 89, 94 ]
```

---

### Cenário B: Entrada Média — $n^2 = 100$ elementos (Limite Exato da Exibição Completa)

Com $100$ elementos, o sistema exibe o vetor inteiro em blocos estruturados:

```text
ENTRADA (100 de 100 elementos):
[  74,  12,  95,  38,  61,   4,  83,  27,  50,  19,
   88,  33,   6,  91,  45,  70,  16,  59,  82,  24,
   53,   9,  97,  41,  68,  14,  79,  31,  64,   2,
   86,  47,  21,  93,  35,  72,  11,  58,  99,  29,
   66,  18,  84,  39,  77,   5,  90,  26,  54,  13,
   92,  43,  17,  75,  30,  81,   8,  62,  96,  22,
   49,  15,  87,  36,  69,   1,  78,  34,  57,  25,
   80,  44,  10,  94,  32,  71,  20,  65,  98,  28,
   63,  23,  85,  40,  76,   7,  89,  37,  52, 100,
   67,  42,   3,  73,  46,  55,  48,  51,  56,  60 ]
   │
   ▼  Execução dos algoritmos de ordenação
SAÍDA ORDENADA (100 de 100 elementos):
[   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
   11,  12,  13,  14,  15,  16,  17,  18,  19,  20,
   21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
   31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
   41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
   51,  52,  53,  54,  55,  56,  57,  58,  59,  60,
   61,  62,  63,  64,  65,  66,  67,  68,  69,  70,
   71,  72,  73,  74,  75,  76,  77,  78,  79,  80,
   81,  82,  83,  84,  85,  86,  87,  88,  89,  90,
   91,  92,  93,  94,  95,  96,  97,  98,  99, 100 ]
```

---

### Cenário C: Grande Volume — $n^3 = 1.000$ elementos (Truncado nos 100 Primeiros)

Quando `TAMANHO_VETOR = 1000`, o volume ultrapassa o limite de visualização. O programa aplica o corte automático e exibe **somente os 100 primeiros elementos** da entrada e da saída:

```text
ENTRADA (Exibindo os 100 primeiros de 1.000 elementos):
[ 612,  45, 983, 217, 504,  19, 876, 331, 740, 128,
  951, 402,  67, 815, 290, 643,  11, 578, 924, 184,
  733, 359,  92, 864, 471, 695,  34, 518, 907, 246,
  789, 415,  53, 832, 310, 668,   4, 549, 962, 173,
  701, 388,  81, 847, 439, 625,  27, 591, 938, 195,
  756, 342,  60, 890, 483, 677,  14, 530, 975, 162,
  718, 374,  98, 821, 456, 639,  39, 564, 912, 208,
  774, 326,  72, 855, 492, 681,   8, 509, 946, 151,
  795, 397,  85, 809, 428, 654,  23, 583, 991, 137,
  748, 365,  51, 870, 464, 619,  31, 522, 933, 180 ]
  ... (+ 900 elementos ocultos | Total: 1.000 elementos)
   │
   ▼  Execução dos algoritmos de ordenação
SAÍDA ORDENADA (Exibindo os 100 primeiros de 1.000 elementos):
[   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
   11,  12,  13,  14,  15,  16,  17,  18,  19,  20,
   21,  22,  23,  24,  25,  26,  27,  28,  29,  30,
   31,  32,  33,  34,  35,  36,  37,  38,  39,  40,
   41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
   51,  52,  53,  54,  55,  56,  57,  58,  59,  60,
   61,  62,  63,  64,  65,  66,  67,  68,  69,  70,
   71,  72,  73,  74,  75,  76,  77,  78,  79,  80,
   81,  82,  83,  84,  85,  86,  87,  88,  89,  90,
   91,  92,  93,  94,  95,  96,  97,  98,  99, 100 ]
  ... (+ 900 elementos ocultos | Total: 1.000 elementos)
```

> **Por que não executar $n^{10} = 10.000.000.000$ diretamente no Java?**
> Um vetor com $10^{10}$ inteiros de 32 bits exigiria aproximadamente **$40\text{ GB}$ de memória RAM contígua** apenas para armazenar os dados (além de ultrapassar o limite nativo de indexação de arrays em Java, que é $2^{31} - 1 \approx 2,14 \times 10^9$). Por isso, essa escala foi avaliada por meio de simulação teórica.

---

## 5. Simulações de Desempenho com IA ($n$, $n^2$, $n^3$ e $n^{10}$)

### Ferramenta de Inteligência Artificial Utilizada

- **IA:** **ChatGPT** (desenvolvido pela **OpenAI**)
- **Objetivo do uso:** Identificar as classes de complexidade temporal, simular o crescimento assintótico das operações e estimar os tempos de execução para escalas inviáveis em hardware convencional.

### Parâmetros Matemáticos da Simulação

Partindo de uma base $n = 10$, foram avaliados quatro volumes de entrada ($m$):

- $n = 10$ elementos
- $n^2 = 100$ elementos
- $n^3 = 1.000$ elementos
- $n^{10} = 10.000.000.000$ ($10^{10}$) elementos

Adotando uma taxa de processamento hipotética de **$10^8$ operações básicas por segundo**, aplicaram-se os modelos teóricos:

$$T_{\text{quadrático}}(m) = \frac{m^2}{10^8} \qquad \text{e} \qquad T_{\text{linearítmico}}(m) = \frac{m \log_2(m)}{10^8}$$

<details>
<summary><strong>Ver prompts utilizados na simulação com o ChatGPT</strong></summary>

1. **Análise de complexidades:** _"Analise os cinco algoritmos de ordenação Bubble Sort, Insertion Sort, Selection Sort, Merge Sort e Quick Sort. Identifique a complexidade temporal de cada um, considerando melhor caso, caso médio e pior caso quando aplicável. Explique como cada algoritmo se comporta conforme aumenta a quantidade de elementos."_
2. **Simulação das entradas:** _"Considere $n=10$ e realize simulações teóricas dos cinco algoritmos de ordenação para os tamanhos de entrada $n$, $n^2$, $n^3$ e $n^{10}$. Utilize uma taxa hipotética de $10^8$ operações básicas por segundo para estimar os tempos de execução. Apresente os resultados em segundos e, quando necessário, converta para minutos, horas ou anos. Não execute entradas inviáveis; utilize estimativas matemáticas baseadas nas complexidades temporais."_
3. **Comparação de crescimento:** _"Compare o crescimento do tempo estimado de execução dos cinco algoritmos conforme o aumento do volume de dados. Identifique quais apresentam crescimento quadrático e quais possuem crescimento $O(n \log n)$. Explique as limitações de cada algoritmo para entradas muito grandes."_

</details>

### Tabela Comparativa de Tempo Estimado

| Algoritmo          | Complexidade Considerada |        $n = 10$        |      $n^2 = 100$      |     $n^3 = 1.000$     | $n^{10} = 10^{10}$ (10 Bilhões) | Equivalência Prática em $n^{10}$ |
| :----------------- | :----------------------: | :--------------------: | :-------------------: | :-------------------: | :-----------------------------: | :------------------------------- |
| **Bubble Sort**    |         $O(m^2)$         |  $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Insertion Sort** |         $O(m^2)$         |  $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Selection Sort** |         $O(m^2)$         |  $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Merge Sort**     |      $O(m \log m)$       | $0,000000332\text{ s}$ | $0,00000664\text{ s}$ | $0,00009966\text{ s}$ |        $3.322\text{ s}$         | $\approx 55\text{ minutos}$      |
| **Quick Sort**     | $O(m \log m)$ _(médio)_  | $0,000000332\text{ s}$ | $0,00000664\text{ s}$ | $0,00009966\text{ s}$ |        $3.322\text{ s}$         | $\approx 55\text{ minutos}$      |

---

## 6. Principais Conclusões para a Apresentação

1. **Para entradas pequenas ($n = 10$ ou $n^2 = 100$), todos parecem instantâneos:** A diferença entre $0,0001\text{ s}$ e $0,00000664\text{ s}$ é imperceptível ao olho humano. Nesses cenários, algoritmos simples como **Insertion Sort** são até vantajosos por não exigirem recursão nem memória extra.
2. **O abismo da escalabilidade em $n^{10}$:** Ao saltar para $10$ bilhões de elementos, os algoritmos $O(m^2)$ levariam **$1$ trilhão de segundos ($\approx 31.688\text{ anos}$)** — mais tempo do que toda a história da civilização humana registrada — enquanto **Merge Sort** e **Quick Sort** resolveriam o problema em aproximadamente **$55\text{ minutos}$**.
3. **Trade-offs de engenharia (não existe "bala de prata"):**
   - **Merge Sort** garante $O(n \log n)$ mesmo no pior caso, mas cobra o preço de **$O(n)$ em memória auxiliar**.
   - **Quick Sort** ordena _in-place_ (sem duplicar o vetor na memória) e costuma ser o mais rápido na prática, mas exige boa escolha de pivô para não cair no pior caso $O(n^2)$.
   - **Insertion Sort** brilha em vetores pequenos ou **quase ordenados**, onde seu custo cai para $O(n)$.

---

## 7. Como Executar o Projeto

### Pré-requisitos

- **Java JDK 11+** instalado e configurado no `PATH`.

### Passo a Passo no Terminal

```bash
# 1. Acesse o diretório do projeto de ordenação
cd algoritmos-ordenacao/src

# 2. Compile todos os arquivos Java
javac *.java

# 3. Execute a classe principal
java App
```

> **Dica para demonstração ao vivo:** Abra o arquivo `App.java`, altere o valor de `TAMANHO_VETOR` (`10` $\rightarrow$ `100` $\rightarrow$ `1000`), recompile com `javac *.java` e rode `java App` para demonstrar tanto a ordenação quanto o corte automático nos 100 primeiros elementos.

---

## 8. Equipe

- **Artur Dutra**
- **Daniel Tavares**
- **Paulo Artur**
- **Samuel Victor**
- **Samla Manathe**
- **Tainara David**
- **Gabriel Eduardo**
