#include <stdio.h>
#include <omp.h>
#define N 10000

int main() {
    double start, end;
    long long sum = 0;

    start = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            sum += j;
        }
    }
    end = omp_get_wtime();

    printf("sum: %lld\n", sum);
    printf("secuencial: %f segundos\n", end - start);
    return 0;
}
