#include <iostream>


void merge_sort(int* arr, int head, int tail, int length)
{
    if (tail <= head)
    {
        return;
    }
    int middle = head + (tail - head)/2;
    merge_sort(arr, head, middle, length);
    merge_sort(arr, middle + 1, tail, length);
    int* tmp = new int[length];
    for( int i = head; i < tail; i++)
    {
        tmp[i] = arr[i];
    }
    for( int i = head; i < tail; i++)
    {
        std::cout << tmp[i] << ' ';
    }
    std::cout << std::endl;
    int k = head;
    int j = middle + 1;
    for (int i = head; i < tail; i++)
    {
        if(k > middle)
        {
            arr[i] = tmp[j];
            j +=1;
        }
        else if (j > tail)
            {
                arr[i] = tmp[k];
                k += 1;
            }
            else if (tmp[j] < tmp[k])
                {
                    arr[i] = tmp[j];
                    j += 1;
                }
                else
                {
                    arr[i] = tmp[k];
                    k +=1;
                }

    }



}

int main()
{
    int N;
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
    merge_sort(array, 0, N-1, N);
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
