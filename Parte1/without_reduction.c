#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double start, end;
    long long sum = 0;
    int *giga = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        giga[i] = i;
    }

    start = omp_get_wtime();
    #pragma omp parallel
    {
        long long local_sum = 0;
        #pragma omp for
        for (int i = 0; i < N; i++) {
            local_sum += giga[i];
        }
        #pragma omp critical
        sum += local_sum;
    }
    end = omp_get_wtime();

    printf("Suma: %lld\n", sum);
    printf("Sin reduccion: %f segundos\n", end - start);

    free(giga);
    return 0;
}
