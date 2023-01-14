#include <cmath>
#include <cstdlib>
#include <iostream>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
void print_info(int thread_count)
{
    std::cout << "Compiled with OpenMP and using " << thread_count << " threads\n";
}
#else
void print_info(int thread_count)
{
    std::cout << "Running in serial\n";
}
int omp_get_thread_num()
{
    return 0;
}
int omp_get_num_threads()
{
    return 1;
}
#endif

double func(double x)
{
    return 1 + std::sin(x);
}

void trapezoidal_rule(int n, double a, double b, double *result)
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    double h = (b - a) / n;

    int local_n = n / thread_count;
    double local_a = a + my_rank * local_n * h;
    double local_b = local_a + local_n * h;

    double total = (func(local_a) + func(local_b)) / 2.0;
    for (int i = 1; i < local_n; i++)
        total += func(local_a + i * h);

    total *= h;
#pragma omp critical
    *result += total; // race condition
}

int main(int argc, char *argv[])
{
    int thread_count = 1;
    if (argc == 2)
    {
        thread_count = atoi(argv[1]);
    }
    else
    {
        std::cout << "Please provide the number of threads\n";
    }

    int n = 100; // Should make sure that this number is divisible by the number of threads
    double a = 0.0;
    double b = M_PI;
    double final_result = 0.0;
    print_info(thread_count);

#pragma omp parallel num_threads(thread_count)
    trapezoidal_rule(n, a, b, &final_result);

    std::cout << "The area under the curve of (1 + six(x)) between 0 and PI is " << final_result << std::endl;
    return 0;
}