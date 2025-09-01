#include "../include/pointers.h"

/**
 * @brief Função de comparação para qsort.
 * 
 * @param a Ponteiro para o primeiro elemento a ser comparado.
 * @param b Ponteiro para o segundo elemento a ser comparado.
 * @return int < 0 se a < b, 0 se a == b, > 0 se a > b.
 * 
 * A função qsort requer um ponteiro para uma função de comparação que
 * aceite dois ponteiros const void* e retorne um inteiro.
 * Dentro da função, convertemos os ponteiros void* para o tipo de dado
 * que queremos comparar (neste caso, int*).
 */
int compare_integers(const void *a, const void *b) {
    int int_a = *((const int *)a);
    int int_b = *((const int *)b);

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

/**
 * @brief Demonstra o uso de ponteiro para função com qsort.
 */
void demo_qsort() {
    printf("--- 6. Ponteiro para Função (qsort) ---\n");
    int numbers[] = {50, 20, 90, 10, 30, 70, 40, 80, 60, 100};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // qsort recebe o array, o número de elementos, o tamanho de cada elemento
    // e um ponteiro para a função de comparação.
    qsort(numbers, n, sizeof(int), compare_integers);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("-----------------------------------------\n\n");
}
