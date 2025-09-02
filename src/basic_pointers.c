#include "../include/pointers.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Demonstra o uso básico e conceitos essenciais de ponteiros.
 * 
 * Esta função foi expandida para servir como uma mini-aula sobre ponteiros,
 * cobrindo desde a declaração básica até conceitos como ponteiros nulos,
 * ponteiros para ponteiros e ponteiros genéricos (void).
 */
void demo_basic_pointers() {
    printf("--- 1. Demonstração de Ponteiros Básicos ---\n\n");

    // declaração da variável 'idade' que guarda um valor
    int idade = 30;
    printf("Cenário Inicial:\n");
    printf("  - A variável 'idade' contém o valor: %d\n", idade);
    printf("  - Ela está guardada no endereço de memória: %p\n\n", (void*)&idade);

    // Declaração de um Ponteiro (*)
    // A sintaxe 'int *ponteiro_para_idade;' declara uma variável especial.
    // O '*' aqui significa "isto é um ponteiro". Ele não guarda um número como 'idade',
    // mas sim um ENDEREÇO de memória onde um 'int' está guardado.
    int *ponteiro_para_idade;
    printf("Passo 1: Declaração do Ponteiro\n");
    printf("  - O ponteiro 'ponteiro_para_idade' foi criado. Seu conteúdo atual é lixo.\n\n");

    // Atribuição de Endereço (&)
    // O operador '&' (address-of) obtém o endereço de memória de uma variável.
    // Aqui, estamos dizendo: "pegue o endereço de 'idade' e guarde-o em 'ponteiro_para_idade'".
    ponteiro_para_idade = &idade;
    printf("Passo 2: Atribuição de Endereço\n");
    printf("  - O ponteiro agora contém o endereço de 'idade': %p\n\n", (void*)ponteiro_para_idade);

    // Desreferência (*)
    // O operador '*' (desreferência) acessa o VALOR que existe no endereço apontado.
    // É como dizer: "vá até o endereço que está guardado no ponteiro e me diga o que tem lá".
    int valor_acessado = *ponteiro_para_idade;
    printf("Passo 3: Acessando o Valor (Desreferência)\n");
    printf("  - No endereço %p, encontramos o valor: %d\n\n", (void*)ponteiro_para_idade, valor_acessado);

    // A desreferência também permite MODIFICAR o valor original indiretamente.
    printf("Modificando o valor através do ponteiro...\n");
    *ponteiro_para_idade = 31; // acessando o endereço e alterando o valor para 31.
    printf("  - O valor da variável 'idade' original agora é: %d\n", idade);

    printf("\n----------------------------------------------------------\n\n");
}
