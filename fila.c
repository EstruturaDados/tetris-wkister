#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h" // Protótipos das funções e definições gerais
#include "fila.h" // Protóripos das funções de manipulação de filas

// Definição dos tipos de peças
char tipoPecas[4] = {'I', 'O', 'T', 'L'};

/**
 * @file fila.c
 * @brief Implementação de uma fila usando arrays circulares
 * @note A fila segue a estrutura FIFO (First In, First Out)
 * @author Wellington Kister do Nascimento
 */

 /**
 * @brief Inicializa a fila
 * @param f Ponteiro para a fila a ser inicializada
 */
void inicializarFila(Fila *fila) {
    printf("\n-----------------------\n");
    printf("Inicializando a fila...\n");
    printf("-----------------------\n");
    fila->inicio = 0;
    fila->fim = 0;
    fila->total = 0;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaCheia(Fila *fila) {
    return fila->total == MAX_PECAS;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaVazia(Fila *fila) {
    return fila->total == 0;
}

/**
 * @brief Insere um elemento aleatório no fim da fila
 * @param f Ponteiro para a fila onde o elemento será inserido
 * @param p Elemento a ser inserido na fila
 */
void inserirPeca(Fila *fila) {
  printf("\n----------------------------------\n");
  printf("Inserindo uma nova peça na fila...\n");
  printf("----------------------------------\n");
  // Contador estático para garantir IDs únicos
  static int idCounter = 1;
  Peca p;
  // Gerar uma peça aleatória
  p.tipo = tipoPecas[rand() % 4]; // Tipo aleatório entre 'I', 'O', 'T', 'L'
  p.id = idCounter++;

  if (fila->total == MAX_PECAS) {
      printf("Fila cheia. Não é possível inserir.\n");
      return;
  }

  fila->itens[fila->fim] = p;
  fila->fim = (fila->fim + 1) % MAX_PECAS;
  fila->total++;
}

/**
 * @brief Exibe os elementos da fila
 * @param f Ponteiro para a fila a ser exibida
 */
void mostrarFila(Fila *fila) {
    printf("Fila: ");
    for (int i = 0, idx = fila->inicio; i < fila->total; i++, idx = (idx + 1) % MAX_PECAS) {
        printf("[%c, %d] ", fila->itens[idx].tipo, fila->itens[idx].id);
    }
    printf("\n");
}