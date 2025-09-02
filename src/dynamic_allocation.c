#include <stdio.h>
#include <stdlib.h>

// Função que aloca dinamicamente um array de inteiros
// Recebe:
//   - int **arr : ponteiro para ponteiro, usado para devolver o endereço alocado (ponteiro duplo)
//   - int tamanho : quantidade de elementos que o array deve ter
void aloca_array(int **arr, int tamanho) {
    // malloc reserva memória no HEAP para "tamanho" inteiros
    // *arr significa: alteramos o ponteiro que está lá no main
    *arr = (int *) malloc(tamanho * sizeof(int));

    // Sempre bom verificar se a alocação deu certo
    if (*arr == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1); // encerra o programa em caso de erro
    }
}

void demo_dynamic_allocation() {
    printf("\n--- Demo Alocacao Dinamica ---\n");
    int *vetor = NULL; // ponteiro que apontará para o array dinâmico
    int n = 5;         // tamanho do array

    // Chamamos a função de alocação
    // Passamos &vetor porque a função espera um int** (int** ponteiro para ponteiro de inteiro)
    aloca_array(&vetor, n);

    // Agora "vetor" já aponta para o bloco de memória alocado
    // Vamos preencher o array com alguns valores
    for (int i = 0; i < n; i++) {
        vetor[i] = (i + 1) * 10; // exemplo: 10, 20, 30, 40, 50
    }

    // Imprime os valores armazenados no array
    printf("Conteudo do array dinamico:\n");
    for (int i = 0; i < n; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    // Quando não precisamos mais do array, devemos liberar a memória
    free(vetor);   // devolve a memória ao sistema
    vetor = NULL;  // boa prática: evitar ponteiro "solto"

    printf("Memoria para o vetor foi liberada.\n");
}
