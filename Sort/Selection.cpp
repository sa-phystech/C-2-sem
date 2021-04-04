#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int x, min;
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
        min = i;
        for (int j = i + 1; j < N; j++)
        {
            if(array[j]<array[min])
            {
                min = j;
            }
        }
        x = array[i];
        array[i] = array[min];
        array[min] = x;
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    delete [] array;
    return 0;
}
