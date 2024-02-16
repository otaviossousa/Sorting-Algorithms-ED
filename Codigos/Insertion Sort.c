#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: https://www.programiz.com/dsa/insertion-sort

// Funcao principal do Insertion Sort
void insertionSort(int arr[], int size)
{
    // Itera sobre o array a partir do segundo elemento (índice 1)
    for (int step = 1; step < size; step++) {
        // Seleciona o elemento atual como chave
        int key = arr[step];
        // Inicializa o índice para comparar com a chave
        int j = step - 1;

        // Compare a chave com cada elemento à esquerda até encontrar um elemento menor do que ela
        // Para ordem decrescente, mude key<arr[j] para key>arr[j]
        while (key < arr[j] && j >= 0) {
            // Desloca os elementos à direita para abrir espaço para a chave
            arr[j + 1] = arr[j];
            // Move para o elemento à esquerda
            --j;
        }
        // Insere a chave na posição correta
        arr[j + 1] = key;
    }
}

// Funcao para imprimir o array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// insertionSort(arr, n); // Ordenando com Insertion Sort
// Código do programa
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    insertionSort(arr, n);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;
}