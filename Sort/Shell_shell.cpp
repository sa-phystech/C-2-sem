#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int x, j, d;
    int* array = new int[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    d = N / 2;
    for (d; d > 0; d /= 2)
    {
        for (int i = 0; i < N; i++)
        {
            for ( j = i + d; j < N; j += d)
            {
                if (array[i] > array[j])
                {
                    x = array[i];
                    array [i] = array[j];
                    array[j] = x;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    delete [] array;
    return 0;
}
