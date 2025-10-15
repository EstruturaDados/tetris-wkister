#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geral.h"
#include "fila.h"
#include "pilha.h"

/**
 * @file pilha.c
 * @brief Implementação de uma pilha usando arrays
 * @note A pilha segue a estrutura FILO (First In, Last Out)
 * @author Wellington Kister do Nascimento
 */

/**
 * @brief Inicializa a pilha
 * @param p Ponteiro para a pilha a ser inicializada
 */
void inicializarPilha(Pilha *p) {
    printf("\n-----------------------\n");
    printf("Inicializando a pilha...\n");
    printf("-----------------------\n");
    p->topo = -1;
}

/**
 * @brief Verifica se a pilha está vazia
 * @param p Ponteiro para a pilha a ser verificada
 * @return 1 se a pilha estiver vazia, 0 caso contrário
 */
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

/**
 * @brief Verifica se a pilha está cheia
 * @param p Ponteiro para a pilha a ser verificada
 * @return 1 se a pilha estiver cheia, 0 caso contrário
 */
int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

/**
 * @brief Adiciona um elemento no topo da pilha
 * @param p Ponteiro para a pilha onde o elemento será adicionado
 * @param nova Elemento a ser adicionado na pilha
 */
void push(Pilha *p, Peca nova) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia. Não é possível inserir.\n");
        return;
    }

    p->topo++;
    p->itens[p->topo] = nova;
}


/**
 * @brief Remove o elemento do topo da pilha
 * @param p Ponteiro para a pilha de onde o elemento será removido
 * @param removida Ponteiro para armazenar o elemento removido
 */
void pop(Pilha *p, Peca *removida) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Não é possível remover.\n");
        return;
    }

    *removida = p->itens[p->topo];
    p->topo--;
}

/**
 * @brief Visualiza o elemento do topo da pilha sem removê-lo
 * @param p Ponteiro para a pilha a ser visualizada
 * @param visualizada Ponteiro para armazenar o elemento visualizado
 */
void peek(Pilha *p, Peca *visualizada) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }

    *visualizada = p->itens[p->topo];
}

/**
 * @brief Mostra o conteúdo da pilha
 * @param p Ponteiro para a pilha a ser exibida
 */
void mostrarPilha(Pilha *p) {
    printf("\n-----------------------\n");
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c, %d]\n", p->itens[i].tipo, p->itens[i].id);
    }
    printf("\n-----------------------\n");
}

void reservarPeca(Pilha* pilhaReserva, Fila* filaPecas){
    if (pilhaCheia(pilhaReserva)) {
        printf("\n-------------------------------------------------------\n");
        printf("Pilha de reserva cheia. Não é possível reservar mais peças.\n");
        printf("-------------------------------------------------------\n");
        return;
    }
    if (filaVazia(filaPecas)) {
        printf("\n-------------------------------------------------------\n");
        printf("Fila de peças vazia. Não é possível reservar uma peça.\n");
        printf("-------------------------------------------------------\n");
        return;
    }

    // Pega o início da fila
    Peca p = filaPecas->itens[filaPecas->inicio];
    // Remove o primeiro elemento da fila
    jogarPeca(filaPecas, 0); // 0 para não imprimir mensagem de remoção
    inserirPeca(filaPecas); // Insere uma nova peça na fila
    // Insere a peça na pilha de reserva
    push(pilhaReserva, p);
}

void usarPecaReserva(Pilha* pilhaReserva){
    if (pilhaVazia(pilhaReserva)) {
        printf("\n--------------------------\n");
        printf("Pilha de reserva vazia. Não há peça para usar.\n");
        printf("--------------------------\n");
        return;
    }

    Peca p;
    pop(pilhaReserva, &p);
    printf("\n--------------------------\n");
    printf("Usando peça da reserva: [%c, %d]\n", p.tipo, p.id);
    printf("--------------------------\n");
}