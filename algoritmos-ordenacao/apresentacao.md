# Análise Comparativa de Algoritmos de Ordenação em Java

> Estudo prático e teórico sobre o comportamento, a escalabilidade e a complexidade temporal de cinco algoritmos clássicos de ordenação diante do crescimento do volume de dados.

---

## Sumário

1. [Como Cada Algoritmo Funciona (Resumo Visual)](#1-como-cada-algoritmo-funciona-resumo-visual)
2. [Simulações de Desempenho com IA ($n$, $n^2$, $n^3$ e $n^{10}$)](#2-simulações-de-desempenho-com-ia-n-n2-n3-e-n10)
3. [Principais Conclusões](#3-principais-conclusões-para-a-apresentação)

---

## 1. Como Cada Algoritmo Funciona (Resumo Visual)

| Algoritmo          | Analogia                  | Como Funciona na Prática                                                                                                                      |
| :----------------- | :-------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------- | 
| **Bubble Sort**    | Bolhas subindo na água                  | Compara pares de vizinhos e os troca se estiverem fora de ordem. A cada passada, o maior valor "flutua" para o final do vetor.                |
| **Insertion Sort** | Organizar cartas na mão                 | Pega um elemento por vez e o insere na posição exata dentro da parte esquerda do vetor, que já está ordenada.                                 |
| **Selection Sort** | Escolher o menor item da fila           | Varre toda a parte não ordenada para encontrar o menor elemento e o coloca na próxima posição fixa. Faz sempre o mesmo número de comparações. |
| **Merge Sort**     | Dividir para conquistar e juntar pilhas | Divide o vetor ao meio recursivamente até sobrarem unidades individuais e depois intercala (mescla) as partes em ordem.                       |
| **Quick Sort**     | Separar menores e maiores que um líder  | Escolhe um **pivô**, joga os menores para a esquerda e os maiores para a direita, repetindo o processo nas duas metades.                      |

---

## 2. Simulações de Desempenho com IA ($n$, $n^2$, $n^3$ e $n^{10}$)

### Ferramenta de Inteligência Artificial Utilizada

- **IA:** **ChatGPT** (desenvolvido pela **OpenAI**)
- **Objetivo do uso:** Identificar as classes de complexidade temporal, simular o crescimento assintótico das operações e estimar os tempos de execução para escalas inviáveis em hardware convencional.

### Parâmetros Matemáticos da Simulação

Partindo de uma base $n = 10$, foram avaliados quatro volumes de entrada ($m$):

- $n = 10$ elementos
- $n^2 = 100$ elementos
- $n^3 = 1.000$ elementos
- $n^{10} = 10.000.000.000$ ($10^{10}$) elementos

<details>
<summary><strong>Ver prompts utilizados na simulação com o ChatGPT</strong></summary>

1. **Análise de complexidades:** _"Analise os cinco algoritmos de ordenação Bubble Sort, Insertion Sort, Selection Sort, Merge Sort e Quick Sort. Identifique a complexidade temporal de cada um, considerando melhor caso, caso médio e pior caso quando aplicável. Explique como cada algoritmo se comporta conforme aumenta a quantidade de elementos."_
2. **Simulação das entradas:** _"Considere $n=10$ e realize simulações teóricas dos cinco algoritmos de ordenação para os tamanhos de entrada $n$, $n^2$, $n^3$ e $n^{10}$. Utilize uma taxa hipotética de $10^8$ operações básicas por segundo para estimar os tempos de execução. Apresente os resultados em segundos e, quando necessário, converta para minutos, horas ou anos. Não execute entradas inviáveis; utilize estimativas matemáticas baseadas nas complexidades temporais."_
3. **Comparação de crescimento:** _"Compare o crescimento do tempo estimado de execução dos cinco algoritmos conforme o aumento do volume de dados. Identifique quais apresentam crescimento quadrático e quais possuem crescimento $O(n \log n)$. Explique as limitações de cada algoritmo para entradas muito grandes."_

</details>

### Tabela Comparativa de Tempo Estimado

| Algoritmo          |        $n = 10$        |      $n^2 = 100$      |     $n^3 = 1.000$     | $n^{10} = 10^{10}$ (10 Bilhões) | Equivalência Prática em $n^{10}$ |
| :----------------- | :--------------------: | :-------------------: | :-------------------: | :-----------------------------: | :------------------------------- |
| **Bubble Sort**    |  $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Insertion Sort** |   $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Selection Sort** | $0,000001\text{ s}$   |   $0,0001\text{ s}$   |    $0,01\text{ s}$    |  $1.000.000.000.000\text{ s}$   | $\approx 31.688\text{ anos}$     |
| **Merge Sort**     | $0,000000332\text{ s}$ | $0,00000664\text{ s}$ | $0,00009966\text{ s}$ |        $3.322\text{ s}$         | $\approx 55\text{ minutos}$      |
| **Quick Sort**     | $0,000000332\text{ s}$ | $0,00000664\text{ s}$ | $0,00009966\text{ s}$ |        $3.322\text{ s}$         | $\approx 55\text{ minutos}$      |

---

## 3. Principais Conclusões

1. **Entradas pequenas:** Para vetores pequenos, como 10 ou 100 elementos, todos os algoritmos apresentam tempos muito baixos. Nesses casos, algoritmos mais simples, como o Insertion Sort, podem ser vantajosos, principalmente por não precisarem de memória extra nem de recursão.

2. **Entradas muito grandes:** Quando aumentamos a quantidade para 10 bilhões de elementos, a diferença fica enorme. Bubble Sort, Insertion Sort e Selection Sort levariam aproximadamente 31.688 anos, enquanto Merge Sort e Quick Sort levariam cerca de 55 minutos, considerando as estimativas teóricas.

3. **Cada algoritmo tem suas vantagens e desvantagens:**
   - **Merge Sort:** É eficiente mesmo em grandes quantidades de dados, mas precisa de memória extra para realizar a ordenação.
   - **Quick Sort:** Geralmente é muito rápido e não precisa criar outro vetor completo, mas pode ficar mais lento dependendo da escolha do pivô.
   - **Insertion Sort:** Funciona muito bem com vetores pequenos ou que já estão quase ordenados.

**Conclusão:** Não existe um único algoritmo ideal para todas as situações. A escolha depende da quantidade de dados, da organização dos elementos e dos recursos disponíveis.
