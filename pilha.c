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
Peca pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Não é possível remover.\n");
        return (Peca){'X', -1}; // Retorna uma peça inválida
    }

    return p->itens[p->topo--];
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
    printf("\n----------------------------------------\n");
    printf("Pilha (topo -> base): ");
    if (pilhaVazia(p)) {
        printf("Vazia.");
        return;
    }
    for (int i = p->topo; i >= 0; i--) {
        printf("[%c, %d] ", p->itens[i].tipo, p->itens[i].id);
    }
}

/**
 * @brief Move a peça do início da fila para o topo da pilha de reserva
 * @param pilhaReserva Ponteiro para a pilha de reserva
 * @param filaPecas Ponteiro para a fila de peças
 */
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

    // Pega o início da fila e insere a peça na pilha de reserva
    push(pilhaReserva, removerPeca(filaPecas));
    // Insere uma nova peça na fila
    inserirPeca(filaPecas, pecaAleatoria());
}

/**
 * @brief Remove a peça do topo da pilha de reserva e a joga no tabuleiro
 * @param pilhaReserva Ponteiro para a pilha de reserva
 * @param tabuleiro Ponteiro para o início da lista encadeada representando o tabuleiro
 */
void usarPecaReserva(Pilha* pilhaReserva, No** tabuleiro){
    if (pilhaVazia(pilhaReserva)) {
        printf("\n--------------------------\n");
        printf("Pilha de reserva vazia. Não há peça para usar.\n");
        printf("--------------------------\n");
        return;
    }

    inserirTabuleiro(tabuleiro, pop(pilhaReserva));
}

/**
 * @brief Troca as peças da frente da fila com o topo da pilha de reserva
 * @param filaPecas Ponteiro para a fila de peças
 * @param pilhaReserva Ponteiro para a pilha de reserva
 */
void trocarPecasFilaPilha(Fila** filaPecas, Pilha* pilha){
    if (filaVazia(*filaPecas)) {
        printf("\n-------------------------------------------------------\n");
        printf("Fila de peças vazia. Não é possível trocar peças.\n");
        printf("-------------------------------------------------------\n");
        return;
    }
    if (pilhaVazia(pilha)) {
        printf("\n-------------------------------------------------------\n");
        printf("Pilha de reserva vazia. Não é possível trocar peças.\n");
        printf("-------------------------------------------------------\n");
        return;
    }

    printf("\n-------------------------------------------------------\n");
    printf("Trocando a peça da frente da fila com o topo da pilha...\n");
    printf("-------------------------------------------------------\n");

    int numPecas = 0; // Número de pecas a serem trocadas, de 1 a 3
    int numPecasPilha = pilha->topo + 1; // Número de peças na pilha

    Fila* filaAux = (Fila*) malloc(sizeof(Fila));

    inicializarFila(filaAux);

    printf("Quantas peças deseja trocar? (1 a %d): ", numPecasPilha);
    do {
        scanf("%d", &numPecas);
        limparBufferEntrada();
        if (numPecas < 1 || numPecas > numPecasPilha){
            printf("Número inválido. Digite um valor entre 1 e %d: ", numPecasPilha);
        }
    } while (numPecas < 1 || numPecas > numPecasPilha);

    // Removendo as peças da pilha e armazenando na fila auxiliar
    for (int i = 0; i < numPecas; i++){
        inserirPeca(filaAux,  pop(pilha));
    }

    // Removendo as peças da fila original e armazenando na pilha
    for (int i = 0; i < numPecas; i++){
        push(pilha, removerPeca(*filaPecas));
    }

    // Movendo as peças sobressalentes da fila original para a fila auxiliar
    // for (int i = filaPecas->inicio; i < filaPecas->fim; i++){
    for (int i = 0; i < (MAX_PECAS - numPecas); i++){
        inserirPeca(filaAux, removerPeca(*filaPecas));
    }

    // Copiando as peças da fila auxiliar de volta para a fila original
    *filaPecas = filaAux;
}