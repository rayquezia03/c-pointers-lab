#include "../include/pointers.h"

/**
 * @brief Função principal que executa todas as demonstrações.
 */
int main() {
    printf("=====================================================\n");
    printf("Trabalho sobre Ponteiros com a Linguagem C\n");
    printf("=====================================================\n\n");

    // 1. Declaração e uso básico de ponteiros
    demo_basic_pointers();

    // 2. Relação entre arrays e ponteiros
    demo_array_pointers();

    // 3. Diferença entre char s[] e const char *
    demo_char_pointers();

    // 4. Passagem de parâmetros por referência (swap)
    demo_swap();

    // 5. Alocação dinâmica de um array via T**
    demo_dynamic_allocation();

    // 6. Exemplo com ponteiro para função (qsort)
    demo_qsort();

    // 7. Armadilhas comuns com ponteiros
    demo_common_pitfalls();

    printf("Todas as demonstrações foram concluídas.\n");

    return 0;
}
