#include <iostream>


int main()
{

    int N;
    int j;
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
    for (int i = 1; i < N; i++)
    {
        j = i-1;
        while((j >= 0)&&(array[j] > array[j+1]))
        {
            x = array[j];
            array[j] = array[j+1];
            array[j+1] = x;
            j--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
