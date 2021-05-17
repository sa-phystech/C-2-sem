#include <iostream>
#include <complex>

int main()
{
    int n;
    std::cin >> n;
    std::complex<double> **A = new std::complex<double> *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new std::complex<double>[n];
    }
    std::complex<double> **B = new std::complex<double> *[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new std::complex<double>[n];
    }
    std::complex<double> **S = new std::complex<double> *[n];
    for (int i = 0; i < n; i++)
    {
        S[i] = new std::complex<double>[n];
    }
    //заполнение
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::complex< double > z(1 + rand() % 10, 1 + rand() % 10);
            A[i][j] = z;
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
            std::complex< double > z(1 + rand() % 10, 1 + rand() % 10);
            B[i][j] = z;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << S[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete A[i];
        }
    }
    delete [] A;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete B[i];
        }
    }
    delete [] B;
    return 0;
}
