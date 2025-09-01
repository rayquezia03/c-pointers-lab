#include "../include/pointers.h"

/**
 * @brief Demonstra o uso básico de ponteiros.
 * 
 * Esta função mostra como declarar um ponteiro, atribuir o endereço de uma variável
 * a ele usando o operador '&' (address-of) e como acessar o valor da variável
 * original através do ponteiro usando o operador '*' (dereference).
 */
void demo_basic_pointers() {
    printf("--- 1. Demonstração de Ponteiros Básicos ---\n");
    int var = 42;
    int *ptr; // Declaração de um ponteiro para um inteiro

    ptr = &var; // O ponteiro 'ptr' agora armazena o endereço de 'var'

    printf("Valor da variável 'var': %d\n", var);
    printf("Endereço da variável 'var' (&var): %p\n", (void*)&var);
    printf("Valor do ponteiro 'ptr' (endereço que ele aponta): %p\n", (void*)ptr);
    printf("Valor apontado pelo ponteiro 'ptr' (*ptr): %d\n\n", *ptr);

    // Modificando o valor de 'var' através do ponteiro
    *ptr = 100;
    printf("Após modificar com '*ptr = 100', o valor de 'var' é: %d\n", var);
    printf("--------------------------------------------\n\n");
}
