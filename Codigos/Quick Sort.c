#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: https://www.programiz.com/dsa/quick-sort

// Funcao para trocar os elementos
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar a posição de partição
int partition(int arr[], int low, int high)
{

    // Selecione o elemento mais à direita como pivô
    int pivot = arr[high];

    // Ponteiro para elemento maior
    int i = (low - 1);

    // Percorre cada elemento do array comparando com o pivô
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {

            // se um elemento menor que o pivô for encontrado, troca como elemento maior apontado por i
            i++;

            // Troca o elemento em i pelo elemento em j
            swap(&arr[i], &arr[j]);
        }
    }

    // Troca o elemento pivô pelo elemento maior em i
    swap(&arr[i + 1], &arr[high]);

    // Retorna ao ponto de partição
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        // encontra o elemento pivô de forma que
        // os elementos menores que o pivô estejam à esquerda do pivô
        // e os elementos maiores que o pivô estejam à direita do pivô
        int pi = partition(arr, low, high);

        // chamada recursiva à esquerda do pivô
        quickSort(arr, low, pi - 1);

        // chamada recursiva à direita do pivô
        quickSort(arr, pi + 1, high);
    }
}

// Funcao para imprimir o array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// quickSort(arr, 0, n - 1); // Ordenando com Quick Sort Ordenador //
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    quickSort(arr, 0, n - 1);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;
}