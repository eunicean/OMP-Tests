#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000
#define Nthreads 1

int main() {
    double start, end;
    long long sum = 0;
    int *giga = malloc(N * sizeof(int));
    omp_set_num_threads(Nthreads);

    for (int i = 0; i < N; i++) {
        giga[i] = i;
    }

    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += giga[i];
    }
    end = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        printf("Hilos usados: %d\n", omp_get_num_threads());
    }

    printf("Suma: %lld\n", sum);
    printf("Tiempo secuencial: %f segundos\n", end - start);

    free(giga);
    return 0;
}
