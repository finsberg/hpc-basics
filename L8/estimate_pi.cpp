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
#endif

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

    print_info(thread_count);

    double sum = 0.0;
    int N = 10000;
    double sign = 1.0;

#pragma omp parallel for num_threads(thread_count) reduction(+ : sum) private(sign)
    for (int k = 0; k < N; k++)
    {
        if (k % 2 == 0)
        {
            sign = 1.0;
        }
        else
        {
            sign = -1.0;
        }
        sum += sign / (2 * k + 1);
    }
    double pi = 4 * sum;
    std::cout << "Pi = " << pi << std::endl;
    return 0;
}