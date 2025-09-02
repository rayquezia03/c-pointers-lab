#include "../include/pointers.h"

/**
 * @brief Troca os valores de duas variáveis inteiras.
 * 
 * @param a Ponteiro para a primeira variável.
 * @param b Ponteiro para a segunda variável.
 * 
 * Esta função recebe os endereços de duas variáveis e utiliza ponteiros para
 * modificar os valores originais dessas variáveis, efetivamente trocando-os.
 * Isso é conhecido como "passagem por referência".
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void criarArray(int **arr, int tamanho) {
    *arr = (int *) malloc(tamanho * sizeof(int));
    if (*arr == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        (*arr)[i] = (i + 1) * 10;
    }
}

void demo_swap() {
    printf("--- 4.1 Passagem por Referência com swap ---\n");
    int x = 10, y = 20;
    printf("Antes do swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("Depois do swap: x = %d, y = %d\n\n", x, y);

    printf("--- 4.2 Passagem Ponteiro para Ponteiro ---\n");
    int *vetor = NULL;
    int n = 5;

    criarArray(&vetor, n); // Passa o endereço do ponteiro (int**)

    printf("Vetor alocado dinamicamente:\n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    free(vetor);
    printf("Memória liberada com sucesso.\n");
    printf("--------------------------------------------\n\n");
}

