#include <cmath>
#include <cstdlib>
#include <iostream>
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
#endif

double func(double x)
{
    return 1 + std::sin(x);
}

double trapezoidal_rule(int n, double a, double b, int thread_count)
{
    double h = (b - a) / n;

    double result = (func(a) + func(b)) / 2.0;

#pragma omp parallel for num_threads(thread_count) reduction(+ : result)
    for (int i = 1; i < n; i++)
        result += func(a + i * h);

    return result * h;
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
    double final_result = trapezoidal_rule(n, a, b, thread_count);
    print_info(thread_count);
    std::cout << "The area under the curve of (1 + six(x)) between 0 and PI is " << final_result << std::endl;
    return 0;
}