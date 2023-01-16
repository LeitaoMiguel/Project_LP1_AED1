//
// Created by migue on 07/12/2022.
//

#ifndef PROJETOAEDELP_LIBS_STATS_H
#define PROJETOAEDELP_LIBS_STATS_H
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>


double max_double(double* a, int N);
double max_double_subarray(double* a, int N, int lo, int hi);
int max_int(int* a, int N);
double min_double(double* a, int N);
double min_double_subarray(double* a, int N, int lo, int hi);
int min_int(int* a, int N);
double mean_double(double* a, int N);
double mean_double_subarray(double* a, int N, int lo, int hi);
double mean_int(int* a, int N);
double var_double(double* a, int N);
double var_double_subarray(double* a, int N, int lo, int hi);
double var_int(int* a, int N);
double varp_double(double* a, int N);
double varp_double_subarray(double* a, int N, int lo, int hi);
double stddev_double(double* a, int N);
double stddev_double_subarray(double* a, int N, int lo, int hi);
double stddev_int(int* a, int N);
double stddevp_double(double* a, int N);
double stddevp_double_subarray(double* a, int N, int lo, int hi);
double sum_double(double* a, int N);
double sum_double_subarray(double* a, int N, int lo, int hi);
int sum_int(int* a, int N);
#endif //PROJETOAEDELP_LIBS_STATS_H
