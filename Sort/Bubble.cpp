#include <iostream>

int main()
{
    int N;
    int x;
    std::cin >> N;
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
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (array[i] > array[j])
            {
                x = array[i];
                array[i] = array[j];
                array[j] = x;
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
