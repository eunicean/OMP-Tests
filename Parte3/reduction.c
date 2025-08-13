#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000

int main() {
    int *wiwi = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) wiwi[i] = i;

    #pragma omp parallel
    {
        #pragma omp single
        printf("Hilos usados: %d\n", omp_get_num_threads());
    }

    int count = 0;
    double start = omp_get_wtime();
    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < N; i++) {
        if (wiwi[i] % 2 == 0) count++;
    }
    double end = omp_get_wtime();

    printf("Cant pares: %d\n", count);
    printf("paralelo con reduction: %f segundos\n", end - start);
    free(wiwi);
    return 0;
}
