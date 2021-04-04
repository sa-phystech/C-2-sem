#include <iostream>

int main()
{
    int N;
    int head, tail;
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
    head = 0;
    tail = N - 1;
    while (head <= tail)
    {
        for( int i = head; i < tail; i++)
        {
            if (array[i] > array[i+1])
            {
                x = array[i];
                array[i] = array[i+1];
                array[i+1] = x;
            }

        }
        tail -= 1;
        for( int i = tail; i > head; i--)
        {
            if (array[i-1] > array[i])
            {
                x = array[i-1];
                array[i-1] = array[i];
                array[i] = x;
            }

        }
        head += 1;
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    delete [] array;
    return 0;
}
