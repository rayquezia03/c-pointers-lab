#include "../include/pointers.h"

/**
 * @brief Demonstra armadilhas comuns com ponteiros.
 * 
 * Esta função ilustra problemas que podem ocorrer com o uso incorreto de ponteiros,
 * como Dangling Pointers e Double Free. Também comenta sobre Wild Pointers.
 */
void demo_common_pitfalls() {
    printf("--- 7. Armadilhas Comuns com Ponteiros ---\n");

    // 1. Dangling Pointer (Ponteiro Pendente)
    // Um dangling pointer aponta para uma área de memória que já foi liberada (free) ou
    // que saiu de escopo. Acessar esse ponteiro leva a comportamento indefinido.
    printf("1. Dangling Pointer:\n");
    int *dangling_ptr = (int *)malloc(sizeof(int));
    if (dangling_ptr != NULL) {
        *dangling_ptr = 123;
        printf("  Ponteiro aponta para o valor: %d\n", *dangling_ptr);
        free(dangling_ptr);
        // Agora, 'dangling_ptr' é um dangling pointer. Acessá-lo é perigoso.
        // *dangling_ptr = 456; // COMPORTAMENTO INDEFINIDO! Pode causar crash ou corromper dados.
        printf("  Memória liberada. O ponteiro agora é 'dangling'.\n");
        // Boa prática: definir o ponteiro como NULL após liberar.
        dangling_ptr = NULL;
        printf("  Ponteiro definido como NULL para segurança.\n\n");
    }

    // 2. Double Free
    // Ocorre quando `free()` é chamado mais de uma vez no mesmo ponteiro.
    // Isso pode corromper a estrutura de gerenciamento da heap, levando a crashes.
    printf("2. Double Free:\n");
    int *ptr_to_free = (int *)malloc(sizeof(int));
    if (ptr_to_free != NULL) {
        *ptr_to_free = 789;
        printf("  Memória alocada e valor definido: %d\n", *ptr_to_free);
        free(ptr_to_free);
        printf("  Primeiro 'free' executado com sucesso.\n");
        // free(ptr_to_free); // ERRO GRAVE! Causa double free. Descomente para testar o crash.
        printf("  Chamar 'free' novamente no mesmo ponteiro causaria um erro fatal.\n\n");
        // A mesma boa prática de definir como NULL após o free ajuda a evitar isso:
        // ptr_to_free = NULL;
        // if (ptr_to_free != NULL) { free(ptr_to_free); } // A verificação impediria o double free.
    }

    // 3. Wild Pointer (Ponteiro Selvagem)
    // Um ponteiro que não foi inicializado. Ele aponta para um endereço de memória aleatório.
    // Escrever em um wild pointer pode corromper qualquer parte da memória do programa.
    printf("3. Wild Pointer:\n");
    int *wild_ptr; // 'wild_ptr' não foi inicializado. É um ponteiro selvagem.
    // *wild_ptr = 111; // PERIGOSÍSSIMO! Escrevendo em um local de memória desconhecido.
    printf("  Um ponteiro não inicializado ('wild pointer') aponta para um local arbitrário.\n");
    printf("  Escrever nele pode corromper o programa ou o sistema operacional.\n");
    printf("  Boa prática: sempre inicialize ponteiros (ex: com NULL).\n");
    int *safe_ptr = NULL; // Ponteiro seguro.

    printf("-------------------------------------------\n\n");
}
