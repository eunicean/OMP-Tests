#include <stdio.h>
#include <omp.h>
#define N 10000

int main() {
    double start, end;
    long long sum = 0;

    #pragma omp parallel
    {
        #pragma omp single
        printf("Hilos usados: %d\n", omp_get_num_threads());
    }
    
    start = omp_get_wtime();
    #pragma omp parallel for schedule(guided, 10) reduction(+:sum)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            sum += j;
        }
    }
    end = omp_get_wtime();
    
    printf("sum: %lld\n", sum);
    printf("guided: %f segundos\n", end - start);
    return 0;
}
