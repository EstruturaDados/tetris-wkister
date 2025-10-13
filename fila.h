#ifndef FILA_H
#define FILA_H
/**
 * @file fila.h
 * @brief Protótipos das funções e constantes para manipulação de filas
 * @author Wellington Kister do Nascimento
 */

// Vetor de tipos de peças
extern char tipoPecas[4];

// Estrutura para representar uma peça
typedef struct {
    char tipo; // Tipo da peça (por exemplo, 'I', 'O', 'T', 'L')
    int id;    // Identificador único da peça
} Peca;

// Estrutura da fila
typedef struct {
    Peca itens[MAX_PECAS]; // Array para armazenar as peças na fila
    int inicio;    // Índice do início da fila
    int fim;       // Índice do fim da fila
    int total;     // Total de peças na fila
} Fila;

void inicializarFila(Fila* fila); // Inicializa a fila
int filaVazia(Fila* fila); // Verifica se a fila está vazia
int filaCheia(Fila* fila); // Verifica se a fila está cheia
void jogarPeca(Fila* fila); // Remove a peça da frente da fila
void inserirPeca(Fila* fila); // Insere uma peça na fila
void mostrarFila(Fila* fila); // Mostra o conteúdo da fila

 #endif