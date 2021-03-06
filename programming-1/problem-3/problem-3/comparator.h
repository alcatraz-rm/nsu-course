#pragma once

#include <time.h>
#include <stdio.h>

typedef struct benchmark_result {
	size_t calls_number;
	size_t best_run;
	size_t worst_run;
	double *runtime;
	double average_time;
	double standard_dev_1;
	double standard_dev_2;
} benchmark_res;

double count_average(double *runtime, size_t num);
double *run_algorithm(size_t calls_number, void *input, void*(*algorithm)(void*), void*(*read)(FILE*, void*), char* filename);
double count_standard_dev_1(double *runtime, double average, size_t num);
double count_standard_dev_2(double *runtime, double average, size_t num);
benchmark_res benchmark(size_t calls_number, void *input, void*(*algorithm)(void*), void*(*read)(FILE*, void*), char *filename);
void free_benchmark_result(benchmark_res result);
void print_benchmark_result(FILE *file, benchmark_res result);
size_t find_best_run(double *runtime, size_t num);
size_t find_worst_run(double *runtime, size_t num);
