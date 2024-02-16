#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: https://www.programiz.com/dsa/merge-sort

// Mescla os dois subarrays L e M no arr
void merge(int arr[], int p, int q, int r)
{

    // Cria L ← A[p..q] e M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Mantém o índice atual de subarrays e matriz principal
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Até chegarmos ao final de L ou M, escolhe o maior entre
    // os elementos L e M e coloca na posição correta em A[p.. r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Quando ficarmos sem elementos em L ou M
    // peguamos os elementos restantes e colocamos em A[p.. r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide o array em dois subarrays ordena e mescla
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {

        // m é o ponto onde o array é dividido em dois subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla os subarrays ordenados
        merge(arr, l, m, r);
    }
}

// Funcao para imprimir o array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// mergeSort(arr, 0, n - 1); // Ordenando com Merge Sort
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    mergeSort(arr, 0, n - 1);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;

}