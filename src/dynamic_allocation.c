#include "../include/pointers.h"

/**
 * @brief Aloca dinamicamente uma matriz de inteiros na heap.
 * 
 * @param rows O número de linhas da matriz.
 * @param cols O número de colunas da matriz.
 * @return Um ponteiro para ponteiro (int**) para a matriz alocada, ou NULL se a alocação falhar.
 * 
 * Esta função demonstra o uso de ponteiro para ponteiro para criar um array de ponteiros,
 * onde cada ponteiro aponta para uma linha da matriz. A memória é alocada na heap.
 */
int** allocate_int_matrix(int rows, int cols) {
    // Aloca um array de ponteiros (um para cada linha)
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        perror("Falha ao alocar memória para as linhas da matriz");
        return NULL;
    }

    // Aloca memória para cada linha da matriz
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            perror("Falha ao alocar memória para as colunas da matriz");
            // Em caso de falha, libera a memória já alocada para evitar memory leak
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

/**
 * @brief Libera a memória de uma matriz alocada dinamicamente.
 * 
 * @param matrix A matriz a ser liberada.
 * @param rows O número de linhas da matriz.
 */
void free_int_matrix(int **matrix, int rows) {
    if (matrix == NULL) return;

    // Libera a memória de cada linha
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    // Libera o array de ponteiros
    free(matrix);
}

/**
 * @brief Demonstra a alocação e liberação dinâmica de uma matriz.
 */
void demo_dynamic_allocation() {
    printf("--- 5. Alocação Dinâmica com T** (Matriz) ---\n");
    int rows = 3;
    int cols = 4;
    int **my_matrix = allocate_int_matrix(rows, cols);

    if (my_matrix == NULL) {
        printf("Não foi possível alocar a matriz.\n");
        return;
    }

    printf("Matriz %dx%d alocada dinamicamente na heap.\n", rows, cols);

    // Preenchendo a matriz com valores
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            my_matrix[i][j] = i * cols + j + 1;
        }
    }

    // Imprimindo a matriz
    printf("Conteúdo da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", my_matrix[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    free_int_matrix(my_matrix, rows);
    printf("\nMemória da matriz liberada com sucesso.\n");
    printf("----------------------------------------------\n\n");
}
