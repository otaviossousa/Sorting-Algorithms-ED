#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: https://www.programiz.com/dsa/selection-sort

// Funcao para trocar os elementos
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao principal par o Selection Sort
void selectionSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // Para ordenar em ordem decrescente, troque > por < nesta linha.
            // Seleciona o elemento mínimo em cada loop.
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }

        // Coloca o mínimo na posição correta
        swap(&arr[min_idx], &arr[step]);
    }
}

// Funcao para imprimir o array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// selectionSort(arr, n); // Ordenando com Selection Sort
// Código do programa
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    selectionSort(arr, n);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;
}