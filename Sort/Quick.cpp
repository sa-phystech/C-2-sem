#include <iostream>


void quick_sort( int* arr, int head, int tail)
{
    if (head >= tail)
    {
        return;
    }
    int left = head;
    int right = tail;
    int middle = arr[(left+right)/2];
    while (left <= right)
    {
        while (arr[left] < middle)
        {
            left += 1;
        }
        while (arr[right] > middle)
        {
            right -= 1;
        }
        if (left <= right)
        {
            int x = arr[left];
            arr[left] = arr[right];
            arr[right] = x;
            left += 1;
            right -= 1;

        }
        quick_sort(arr, head, right);
        quick_sort(arr, left, tail);
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
    quick_sort(array, 0, N-1);
    for (int i = 0; i < N; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
