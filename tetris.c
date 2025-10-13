/**
 * @file tetris.c
 * @brief Desafio Tetris Stack
 * @note Tema 3 - Integração de Fila e Pilha
 * @author Wellington Kister do Nascimento
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h" // Protótipos das funções e definições gerais
#include "menu.h" // Protótipos das funções do menu
#include "fila.h" // Protóripos das funções de manipulação de filas

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.

    // Semente para números aleatórios
    srand((unsigned int)time(NULL));

    // Definição e inicialização da fila de peças
    Fila filaPecas;
    inicializarFila(&filaPecas);

    // Variável para armazenar a opção do menu
    int opcao = 0;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao) {
            case 1:
                // jogarPeca(&filaPecas);
                // inserirPeca(&filaPecas);
                // mostrarFila(&filaPecas);
                break;
            case 2:
                inserirPeca(&filaPecas);
                mostrarFila(&filaPecas);
                break;
            case 0:
                printf("Saindo do jogo. Até a próxima!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

