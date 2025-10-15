#ifndef PILHA_H
#define PILHA_H
#include "fila.h"

/**
 * @file pilha.h
 * @brief Protótipos das funções e constantes para manipulação de pilhas
 * @author Wellington Kister do Nascimento
 */

// Definição do tamanho máximo da pilha
#define MAX_PILHA 3

typedef struct {
    Peca itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p); // Inicializa a pilha
int pilhaVazia(Pilha *p); // Verifica se a pilha está vazia
int pilhaCheia(Pilha *p); // Verifica se a pilha está cheia
void push(Pilha *p, Peca nova); // Adiciona um elemento no topo da pilha
Peca pop(Pilha *p); // Remove o elemento do topo da pilha
void peek(Pilha *p, Peca *visualizada); // Visualiza o elemento do topo sem remover
void mostrarPilha(Pilha *p); // Mostra o conteúdo da pilha
void reservarPeca(Pilha* pilhaReserva, Fila* filaPecas); // Move a peça do início da fila para o topo da pilha de reserva
void usarPecaReserva(Pilha* pilhaReserva, No** tabuleiro); // Remove a peça do topo da pilha de reserva e a joga no tabuleiro

#endif