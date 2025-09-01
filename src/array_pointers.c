#include "../include/pointers.h"

/**
 * @brief Demonstra a relação entre arrays e ponteiros.
 * 
 * Um nome de array em C é, na maioria dos contextos, convertido para um ponteiro
 * para seu primeiro elemento. Esta função explora essa relação e a aritmética
 * de ponteiros para percorrer o array.
 */
void demo_array_pointers() {
    printf("--- 2. Relação entre Arrays e Ponteiros ---\n");
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // O ponteiro 'ptr' aponta para o primeiro elemento de 'arr'

    printf("Acessando elementos do array usando o ponteiro:\n");
    for (int i = 0; i < 5; i++) {
        // *(ptr + i) é equivalente a arr[i]
        printf("Elemento %d: arr[%d] = %d, *(ptr + %d) = %d\n", i, i, arr[i], i, *(ptr + i));
    }

    printf("\nEndereços dos elementos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Endereço de arr[%d]: %p, Valor de (ptr + %d): %p\n", i, (void*)&arr[i], i, (void*)(ptr + i));
    }
    printf("---------------------------------------------\n\n");
}

/**
 * @brief Demonstra a diferença entre 'char s[]' e 'const char *'.
 * 
 * 'char s[]' declara um array de caracteres. O conteúdo do array é
 * modificável e o ponteiro 's' em si não é um l-value (não pode ser reatribuído).
 * 
 * 'const char *p' declara um ponteiro para uma string literal constante.
 * A string em si não pode ser modificada, mas o ponteiro 'p' pode ser
 * reatribuído para apontar para outra string.
 */
void demo_char_pointers() {
    printf("--- 3. Diferença entre char s[] e const char * ---\n");

    // char s[] é um array modificável na stack
    char s[] = "Hello, World!";
    printf("Array 's' (char s[]): %s\n", s);
    s[0] = 'h'; // Modificação permitida
    printf("Array 's' após modificação: %s\n", s);
    // s = "new string"; // Erro de compilação: 's' não é um l-value modificável.

    // const char *p é um ponteiro para uma string literal (constante)
    const char *p = "Hello, Universe!";
    printf("\nPonteiro 'p' (const char *p): %s\n", p);
    // p[0] = 'h'; // Erro em tempo de execução (segmentation fault): tenta modificar memória somente leitura.
    p = "Nova string literal"; // Permitido: o ponteiro 'p' agora aponta para outro local.
    printf("Ponteiro 'p' após reatribuição: %s\n", p);

    printf("-----------------------------------------------------\n\n");
}
