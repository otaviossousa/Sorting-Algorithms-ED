#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int RUN = 32; // Usado no Tim Sort

// Função para trocar a posição dos elementos
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
        swap(&arr[i], &arr[maior]);
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
        swap(&arr[0], &arr[i]);

        // Amontoa o elemento raiz para obter o maior elemento na raiz novamente
        heapify(arr, i, 0);
    }
}

// Esta função implementa o algoritmo de ordenação por inserção.
// Ela recebe um array de inteiros 'arr', o índice esquerdo 'esquerda'
// e o índice direito 'direita' que definem a parte do array a ser ordenada
void insertionSortTIM(int arr[], int esquerda, int direita) // Funcao usada no Tim Sort
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
    // Ordena subarrays individuais de tamanho RUN usando insertionSortTIM
    for (int i = 0; i < n; i += RUN)
        insertionSortTIM(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));

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
        printf("%d,", arr[i]);
    }
    printf("\n");
}

// Funcao para desornar o array a cada execucao
void desordenarArray(int arr[], int n)
{
    // Usando srand e rand para desordenar o array
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Funcao para medir o tempo de execucao da funcao
void elapsedTimer(clock_t start, clock_t end) {
    double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Tempo de execucao para ordenacao: %.6f segundos\n\n", elapsed);
}

int main()
{
    clock_t startTime, endTime; // Variáveis para armazenar os tempos inicial e final

   int arr[] = {9,8,7,6,6,5,4,4,43,43,2,1,1,};

    int n = sizeof(arr) / sizeof(arr[0]);

    int opt = -1;
    do {

        puts("Menu de Algoritmos de Ordenacao");
        puts("Escolha com qual algoritmo de ordenacao voce deseja ordenar o vetor:\n1 - Merge Sort\n2 - Quick Sort\n3 - Insertion Sort\n4 - Selection Sort\n5 - Heap Sort\n6 - Tim Sort\n0 - Encerrar Programa");
        scanf("%d",&opt);
        printf("------------------------------------\n");
        switch (opt) {
            case 1:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                mergeSort(arr, 0, n - 1); // Ordenando com Merge Sort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 2:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                quickSort(arr, 0, n - 1); // Ordenando com Quick Sort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 3:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                insertionSort(arr, n); // Ordenando com Insertion Sort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 4:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                selectionSort(arr, n); // Ordenando com Selection Sort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 5:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                heapSort(arr, n);  // Ordenação usando o Heap Sort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 6:
                startTime = clock();
                printf("Array desordenado:\n");
                printArray(arr, n);
                timSort(arr, n);  // Ordenação usando o Timsort
                endTime = clock();
                printf("\nArray ordenado:\n");
                printArray(arr, n);
                elapsedTimer(startTime, endTime); // Calcula e exibe o tempo decorrido
                desordenarArray(arr,n);
                break;
            case 0:
                puts("Programa finalizado!");
                break;
            default:
                puts("Opcao invalida! Tente novamente\n");
                break;
        }
    } while (opt != 0);

    return 0;
}