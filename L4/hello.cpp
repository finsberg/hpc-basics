#include <cstdlib>
#include <iostream>
#ifdef _OPENMP
#include <omp.h>
#else
int omp_get_thread_num()
{
    return 0;
}
int omp_get_num_threads()
{
    return 1;
}
#endif

void hello()
{
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    std::cout << "Hello from thread " << my_rank << " of " << thread_count << std::endl;
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

#pragma omp parallel num_threads(thread_count)
    hello();
    return 0;
}