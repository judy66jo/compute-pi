#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "computepi.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    clock_t start=0, end=0;

    if (argc < 2) return -1;

    int N = atoi(argv[1]);
    int i, loop = 25;

    // Baseline
    start = clock();
    for(i = 0; i < loop; i++) {
        compute_pi_baseline(N);
    }
	end = clock();
    printf("%lf,", ((double) (end - start)) / CLOCKS_PER_SEC);


    // OpenMP with 2 threads
	start=0, end=0;
    start = clock();
    for(i = 0; i < loop; i++) {
        compute_pi_openmp(N, 2);
    }
	end = clock();
    printf("%lf,", ((double) (end - start)) / CLOCKS_PER_SEC);


    // OpenMP with 4 threads
    start=0, end=0;
    start = clock();
    for(i = 0; i < loop; i++) {
        compute_pi_openmp(N, 4);
    }
    end = clock();
    printf("%lf,", ((double) (end - start)) / CLOCKS_PER_SEC);


    // AVX SIMD
    start=0, end=0;
    start = clock();
    for(i = 0; i < loop; i++) {
        compute_pi_avx(N);
    }
    end = clock();
    printf("%lf,", ((double) (end - start)) / CLOCKS_PER_SEC);


    // AVX SIMD + Loop unrolling
    start=0, end=0;
    start = clock();
    for(i = 0; i < loop; i++) {
        compute_pi_avx_unroll(N);
    }
    end = clock();
    printf("%lf\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    return 0;
}
