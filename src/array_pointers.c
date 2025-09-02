#include "../include/pointers.h"

/**
 * @brief Demonstra a relação entre arrays e ponteiros.
 * 
 * Um nome de array em C é, na maioria dos contextos, convertido para um ponteiro
 * para seu primeiro elemento. Esta função explora essa relação e a aritmética
 * de ponteiros para percorrer o array.
 */
void demo_array_pointers() {
    printf("--- 2. Aritmética de Ponteiros ---\n");
    printf("O 'salto' na memória ao somar 1 a um ponteiro depende do seu tipo.\n");

    // --- Exemplo com INT  ---
    int arr_int[2] = {15, 34};
    int *ptr_int = arr_int;
    printf("\n1. Ponteiro para INT (avança %zu bytes)\n", sizeof(int));
    printf("   - Antes : Endereço=%p, Valor=%d\n", (void*)ptr_int, *ptr_int);
    ptr_int = ptr_int + 1;
    printf("   - Depois: Endereço=%p, Valor=%d\n", (void*)ptr_int, *ptr_int);

    // --- Exemplo com SHORT ---
    short arr_short[2] = {100, 200};
    short *ptr_short = arr_short;
    printf("\n2. Ponteiro para SHORT (avança %zu bytes)\n", sizeof(short));
    printf("   - Antes : Endereço=%p, Valor=%d\n", (void*)ptr_short, *ptr_short);
    ptr_short = ptr_short + 1;
    printf("   - Depois: Endereço=%p, Valor=%d\n", (void*)ptr_short, *ptr_short);

    // --- Exemplo com CHAR ---
    char arr_char[2] = {'X', 'Y'};
    char *ptr_char = arr_char;
    printf("\n3. Ponteiro para CHAR (avança %zu byte)\n", sizeof(char));
    printf("   - Antes : Endereço=%p, Valor='%c'\n", (void*)ptr_char, *ptr_char);
    ptr_char = ptr_char + 1;
    printf("   - Depois: Endereço=%p, Valor='%c'\n", (void*)ptr_char, *ptr_char);

    printf("\n--- Exemplo Prático: Percorrendo um Array com um Ponteiro ---\n");
    int numeros[] = {10, 20, 30, 15, 5, 10, 30, 11};
    int *ptr = numeros;
    int n = sizeof(numeros) / sizeof(numeros[0]);

    printf("Conteúdo do array 'numeros':\n");
    for (int i = 0; i < n; i++) {
        printf("  - Endereço: %p, Valor: %d\n", (void*)(ptr + i), *(ptr + i));
    }

    printf("\n----------------------------------------------------------\n\n");
}
