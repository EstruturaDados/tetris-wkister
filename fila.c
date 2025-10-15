#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h" // Protótipos das funções e definições gerais
#include "pilha.h" // Protótipos das funções de manipulação de pilhas
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
    // fila->total = 0;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaCheia(Fila *fila) {
    return (fila->fim - fila->inicio) == MAX_PECAS;
}

/**
 * @brief Verifica se a fila está vazia
 * @param f Ponteiro para a fila a ser verificada
 * @return 1 se a fila estiver vazia, 0 caso contrário
 */
int filaVazia(Fila *fila) {
    return fila->inicio == fila->fim;
}

/**
 * @brief Insere um elemento aleatório no fim da fila
 * @param f Ponteiro para a fila onde o elemento será inserido
 * @param p Elemento a ser inserido na fila
 */
void inserirPeca(Fila *fila, Peca p) {
  if (filaCheia(fila)) {
    printf("\n-------------------------------\n");
    printf("Fila cheia. Não é possível inserir.\n");
    printf("-------------------------------\n");
    return;
  }
  fila->itens[fila->fim++ % MAX_PECAS] = p;
}

/**
 * @brief Exibe os elementos da fila
 * @param f Ponteiro para a fila a ser exibida
 */
void mostrarFila(Fila *fila) {
    printf("\n----------------------------------------\n");
    printf("Fila: ");
    if (filaVazia(fila)) {
        printf("Vazia.");
        return;
    }
    for (int i = fila->inicio; i < fila->fim; i++) {
        printf("[%c, %d] ", fila->itens[i % MAX_PECAS].tipo, fila->itens[i % MAX_PECAS].id);
    }
}

/**
 * @brief Exibe as peças no tabuleiro (lista encadeada)
 * @param tabuleiro Ponteiro para o início da lista encadeada representando o tabuleiro
 */
void mostrarTabuleiro(No* tabuleiro) {
    printf("\n----------------------------------------\n");
    if (tabuleiro == NULL) {
        printf("Tabuleiro: Vazio.\n");
        printf("----------------------------------------\n");
        return;
    }

    No* atual = tabuleiro;
    printf("Tabuleiro: ");
    while (atual != NULL) {
        printf("[%c, %d] ", atual->peca.tipo, atual->peca.id);
        atual = atual->proximo;
    }
    printf("\n----------------------------------------\n");
}

/**
 * @brief Remove o elemento da frente da fila
 * @param f Ponteiro para a fila
 * @return A peça removida da frente da fila
 */
Peca removerPeca(Fila* fila) {
    if (filaVazia(fila)) {
        printf("\n----------------------------------\n");
        printf("Fila vazia. Não é possível remover.\n");
        printf("----------------------------------\n");
        Peca p = {'X', -1}; // Retorna uma peça inválida
        return p;
    }

    // Peca p = fila->itens[fila->inicio % MAX_PECAS];
    // Peca papa = fila->itens[fila->inicio++];
    return fila->itens[fila->inicio++ % MAX_PECAS];
}

/**
 * @brief Remove o elemento da frente da fila
 * @param f Ponteiro para a fila
 * @param opcao Define se imprimirá ou não as mensagens de remoção. 1 - Sim, 0 - Não
 */
void jogarPeca(Fila *fila, No** tabuleiro, int opcao) {
    if (opcao){
        printf("\n----------------------------------\n");
        printf("Removendo a peça da frente da fila...\n");
        printf("----------------------------------\n");
    }
    if (filaVazia(fila)) {
        printf("\n----------------------------------\n");
        printf("Fila vazia. Não é possível remover.\n");
        printf("----------------------------------\n");
        return;
    }

    // Colocando a peça no tabuleiro
    inserirTabuleiro(tabuleiro, removerPeca(fila));

    // Automaticamente insere uma nova peça após jogar
    inserirPeca(fila, pecaAleatoria());
}

/**
 * @brief Popula a fila inicialmente com 5 peças
 * @param f Ponteiro para a fila a ser populada
 */
void populaFila(Fila *fila) {
    // Contador estático para garantir IDs únicos
    static int idCounter = 1;
    Peca p;

    printf("\n----------------------------------\n");
    printf("Populando a fila inicialmente...\n");
    printf("----------------------------------\n");
    while (!filaCheia(fila)) {
        inserirPeca(fila, pecaAleatoria());
    }
}

/**
 * @brief Insere uma peça no tabuleiro (lista encadeada)
 * @param tabuleiro Ponteiro para o início da lista encadeada representando o tabuleiro
 * @param peca Peça a ser inserida no tabuleiro
 */
void inserirTabuleiro(No** tabuleiro, Peca peca) {
    No* novaPeca = (No*)malloc(sizeof(No));
    if (novaPeca == NULL) {
        printf("Erro ao alocar memória para nova peça no tabuleiro.\n");
        return;
    }
    novaPeca->peca = peca;
    novaPeca->proximo = NULL;
    if (*tabuleiro == NULL) {
        *tabuleiro = novaPeca;
    } else {
        No* atual = *tabuleiro;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novaPeca;
    }
}

Peca pecaAleatoria() {
    static int idCounter = 1;
    Peca p;
    p.tipo = tipoPecas[rand() % 4]; // Tipo aleatório entre 'I', 'O', 'T', 'L'
    p.id = idCounter++;
    return p;
}