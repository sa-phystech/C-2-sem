#include <iostream>

int main()
{
    int N;
    int k;
    std::cin >> N;
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> A[i][j];
        }
    }

    int** B = new int* [N];
    for (int i = 0; i < N; i++)
    {
        B[i] = new int[N];
    }


    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            k = A[i][j];
            A[i][j] = A[N - j - 1][i];
            A[N - j - 1][i] = A[N - i - 1][N - j - 1];
            A[N - i - 1][N - j - 1] = A[j][N - i - 1];
            A[j][N - i - 1] = k;
        }
    }



    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N; i++)
    {
        delete [] A[i];
    }
    delete [] A;

}
