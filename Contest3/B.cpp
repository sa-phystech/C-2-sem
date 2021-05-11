#include <iostream>

int main()
{
    int N, M;
    unsigned int K;
    int x, y;
    std::cin >> N;
    std::cin >> M;
    int** A = new int* [N];
    for(unsigned int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j < M; j++)
        {
            A[i][j] = 0;
        }
    }
    std::cin >> K;
    for(int i = 0; i < K; i++)
    {
        std::cin >> x;
        std::cin >> y;
        A[x-1][y-1] = -1;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(A[i][j] != -1)
            {
                if(j != 0)
                {
                    if((i != 0)&&(A[i-1][j-1] == -1))
                        A[i][j] += 1;
                    if(A[i][j-1] == -1)
                        A[i][j] += 1;
                    if((i != N-1)&&(A[i+1][j-1] == -1))
                        A[i][j] += 1;
                }
                if(j != M-1)
                {
                    if((i != 0)&&(A[i-1][j+1] == -1))
                        A[i][j] += 1;
                    if(A[i][j+1] == -1)
                        A[i][j] += 1;
                    if((i != N-1)&&(A[i+1][j+1] == -1))
                        A[i][j] += 1;
                }
                if((i != 0)&&(A[i-1][j] == -1))
                    A[i][j] += 1;
                if((i != N-1)&&(A[i+1][j] == -1))
                    A[i][j] += 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
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
    return 0;
}
