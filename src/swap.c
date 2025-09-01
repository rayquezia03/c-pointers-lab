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

/**
 * @brief Demonstra o uso da função swap.
 */
void demo_swap() {
    printf("--- 4. Passagem por Referência com swap ---\n");
    int x = 10;
    int y = 20;

    printf("Valores originais: x = %d, y = %d\n", x, y);

    swap(&x, &y); // Passamos os endereços de x e y para a função

    printf("Valores após o swap: x = %d, y = %d\n", x, y);
    printf("--------------------------------------------\n\n");
}
