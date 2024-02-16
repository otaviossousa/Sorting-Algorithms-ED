#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    // Melhor caso
    int n = 100000; // ou 250000 ou 500000;
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Preenche o array com valores de 1 a n em ordem crescente
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    mergeSort(arr, 0, n - 1);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    free(arr);
    arr = NULL;
    return 0;
}

//==================================================================================================//

int main(){

    // Medio caso
    int n = 100000; // ou 250000 ou 500000;
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preenche o array com números aleatórios de 1 a n
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }

    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    mergeSort(arr, 0, n - 1);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    free(arr);
    arr = NULL;
    return 0;
}

//==================================================================================================//

int main(){

    // Pior caso
    int n = 100000; // ou 250000 ou 500000;
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Preenche o array com valores de n até 1 em ordem decrescente
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    mergeSort(arr, 0, n - 1);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    free(arr);
    arr = NULL;
    return 0;
}




