#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double start, end;
    long long sum = 0;
    int *giga = new int[N];

    for (int i = 0; i < N; i++) {
        giga[i] = i;
    }

    start = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        sum += giga[i];
    }
    end = omp_get_wtime();

    printf("Suma: %lld\n", sum);
    printf("Tiempo secuencial: %f segundos\n", end - start);

    free(giga);
    return 0;
}
