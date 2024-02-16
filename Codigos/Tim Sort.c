#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Fonte: 

const int RUN = 32;

// Esta função implementa o algoritmo de ordenação por inserção.
// Ela recebe um array de inteiros 'arr', o índice esquerdo 'esquerda'
// e o índice direito 'direita' que definem a parte do array a ser ordenada
void insertionSort(int arr[], int esquerda, int direita)
{
    // Percorre o array a partir do segundo elemento até o final
    for (int i = esquerda + 1; i <= direita; i++) {
        // Armazena o valor atual a ser comparado
        int temp = arr[i];
        // Inicializa 'j' como o elemento anterior ao valor atual
        int j = i - 1;

        // Move os elementos do array que são maiores que 'temp'
        // para uma posição à frente da sua posição atual
        // Isso cria espaço para inserir 'temp' na posição correta
        while (j >= esquerda && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insere 'temp' na posição correta no array ordenado.
        arr[j + 1] = temp;
    }
}

// Esta função mescla dois subarrays ordenados em um único array ordenado.
// Ela recebe o array original 'array', o índice de início 'inicio',
// o índice do meio 'meio' e o índice do fim 'fim'.
void mesclar(int arr[], int inicio, int meio, int fim)
{
    // Calcula o tamanho dos subarrays esquerda e direita.
    int len1 = meio - inicio + 1, len2 = fim - meio;

    // Aloca memória para os subarrays esquerda e direita.
    int *esquerda = (int *)malloc(len1 * sizeof(int));
    int *direita = (int *)malloc(len2 * sizeof(int));

    // Copia os elementos correspondentes do array original para os subarrays.
    for (int i = 0; i < len1; i++)
        esquerda[i] = arr[inicio + i];
    for (int i = 0; i < len2; i++)
        direita[i] = arr[meio + 1 + i];

    // Índices para percorrer os subarrays esquerdo, direito e o array original.
    int i = 0, j = 0, k = inicio;

    // Mescla os subarrays ordenados de volta no array original.
    while (i < len1 && j < len2) {
        if (esquerda[i] <= direita[j]) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do subarray esquerdo, se houver.
    while (i < len1) {
        arr[k] = esquerda[i];
        k++;
        i++;
    }

    // Copia os elementos restantes do subarray direito, se houver.
    while (j < len2) {
        arr[k] = direita[j];
        k++;
        j++;
    }

    // Libera a memória alocada para os subarrays.
    free(esquerda);
    free(direita);
    esquerda = NULL;
    direita = NULL;
}

// Função Timsort iterativa para ordenar o array[0...n-1] (similar ao merge sort)
void timSort(int arr[], int n)
{
    // Ordena subarrays individuais de tamanho RUN usando insertionSort
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));

    // Começa a mesclar a partir do tamanho RUN, mesclando para tamanhos maiores
    for (int tamanho = RUN; tamanho < n; tamanho = 2 * tamanho) {

        // Percorre o array mesclando subarrays de tamanho 'tamanho'
        for (int inicio = 0; inicio < n; inicio += 2 * tamanho) {

            // Encontra os pontos de início, meio e fim dos subarrays a mesclar
            int meio = inicio + tamanho - 1;
            int fim = (inicio + 2 * tamanho - 1) < (n - 1) ? (inicio + 2 * tamanho - 1) : (n - 1);

            // Mescla subarray[esquerda...meio] & array[meio + 1 ....direita]
            if (meio < fim)
                mesclar(arr, inicio, meio, fim);
        }
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

// timSort(arr, n);  // Ordenação usando o Timsort
int main()
{
    // Início da contagem de tempo
    clock_t start = clock();

    // Ordenando com o algoritmo.
    timSort(arr, n);

    // Fim da contagem de tempo
    clock_t end = clock();

    // Conversão do tempo para segundos
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nO tempo de execucao do programa foi de %.6f segundos.\n", elapsed);

    return 0;
}