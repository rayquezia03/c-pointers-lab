#include "../include/pointers.h"
#include <stdio.h>

/**
 * @brief Demonstra a diferença entre 'char s[]' e 'const char *'.
 * 
 * 'char s[]' declara um array de caracteres. O conteúdo do array é
 * modificável e o ponteiro 's' em si não é um l-value (não pode ser reatribuído).
 * 
 * 'const char *p' declara um ponteiro para uma string literal, que é armazenada
 * em memória somente leitura. O ponteiro 'p' pode ser reatribuído para apontar
 * para outro local, mas o conteúdo original não pode ser modificado através dele.
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
