#include <iostream>
#include <complex>
#include <cstdlib>

int main()
{
    int n;
    std::cin >> n;
    int **A = new int *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
    }
    int **B = new int *[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new int[n];
    }
    int **S = new int *[n];
    for (int i = 0; i < n; i++)
    {
        S[i] = new int[n];
    }
    //заполнение
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = 1 + rand() % 10;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << A[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = 1 + rand() % 10;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << B[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[i][j] = 0;
        }
    }
    //умножение
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int r = 0; r < n; r++)
            {
                S[i][j] += A[i][r]*B[r][j];
            }
        }

    }
    //вывод
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << S[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    delete [] A;
    delete [] B;
    return 0;
}
