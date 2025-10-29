/**
 * @file tetris.c
 * @brief Desafio Tetris Stack
 * @note Tema 3 - Integração de Fila e Pilha
 * @author Wellington Kister do Nascimento
 *
 * @section compilation Compilação
 * Para compilar este projeto, você pode usar os seguintes comandos make:
 *
 * - make all       : Compila o projeto
 * - make run      : Compila e executa o programa
 * - make valgrind : Executa com verificação de vazamento de memória
 * - make debug    : Compila com flags de depuração adicionais
 * - make clean    : Remove arquivos compilados
 *
 * Exemplo de uso:
 * @code
 * $ make clean    # Limpa compilações anteriores
 * $ make         # Compila o projeto
 * $ make run     # Executa o programa
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h" // Protótipos das funções e definições gerais
#include "menu.h" // Protótipos das funções do menu
#include "fila.h" // Protóripos das funções de manipulação de filas
#include "pilha.h" // Protótipos das funções de manipulação de pilhas

int main() {

    // Semente para números aleatórios
    srand((unsigned int)time(NULL));

    // Definição e inicialização do tabuleiro
    No* tabuleiro = NULL; // Inicialmente vazio

    // Definição e inicialização da fila de peças
    Fila *filaPecas = malloc(sizeof(Fila));
    if (!filaPecas) {
        printf("Erro de alocação de memória para filaPecas!\n");
        return 1;
    }
    inicializarFila(filaPecas);
    populaFila(filaPecas); // Popula inicialmente a fila com 5 peças
    mostrarFila(filaPecas); // Mostra a fila inicial

    // Definição e inicialização da pilha de reserva
    Pilha pilhaReserva;
    inicializarPilha(&pilhaReserva);

    // Variável para armazenar a opção do menu
    int opcao = 0;
    do {
        mostrarFila(filaPecas);
        mostrarPilha(&pilhaReserva);
        mostrarTabuleiro(tabuleiro);

        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                mostrarFila(filaPecas);
                mostrarPilha(&pilhaReserva);
                mostrarTabuleiro(tabuleiro);
                pausa();
                break;
            case 2:
                // Jogar a peça no tabuleiro
                jogarPeca(filaPecas, &tabuleiro, 1);
                break;
            case 3:
                reservarPeca(&pilhaReserva, filaPecas);
                break;
            case 4:
                usarPecaReserva(&pilhaReserva, &tabuleiro);
                break;
            case 5:
                trocarPecasFilaPilha(&filaPecas, &pilhaReserva);
                break;
            case 0:
                printf("Saindo do jogo. Até a próxima!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

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


    free(filaPecas);
    return 0;
}

