#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: https://www.programiz.com/dsa/heap-sort

// Função para trocar a posição dos elementos
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao para amontoar os elementos da heap
void heapify(int arr[], int n, int i)
{
    // Encontra o maior entre a raiz, filho da esquerda e filho da direita
    int maior = i;
    int esquerdo = 2 * i + 1;
    int direito = 2 * i + 2;

    if (esquerdo < n && arr[esquerdo] > arr[maior])
        maior = esquerdo;

    if (direito < n && arr[direito] > arr[maior])
        maior = direito;

    // Troca e continua amontoando se a raiz não for a maior
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

// Função principal para realizar o heap sort
void heapSort(int arr[], int n)
{
    // Constrói um max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Realiza o heap sort
    for (int i = n - 1; i >= 0; i--) {
        trocar(&arr[0], &arr[i]);

        // Amontoa o elemento raiz para obter o maior elemento na raiz novamente
        heapify(arr, i, 0);
    }
}

// Imprime o array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// heapSort(arr, n);  // Ordenação usando o Heap Sort
// Código do programa
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    heapSort(arr, n);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;
}