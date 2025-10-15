#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"

/**
 * @brief Função para exibir o menu principal
 */
void exibirMenu(){
    printf("\n----------------------\n");
    printf("--- MENU PRINCIPAL ---\n");
    printf("----------------------\n");
    printf("1. Mostrar situação jogo\n");
    printf("2. Jogar peça\n");
    printf("3. Reservar peça\n");
    printf("4. Usar peça reservada\n");
    printf("5. Trocar pecas da frente da fila com a pilha\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}
