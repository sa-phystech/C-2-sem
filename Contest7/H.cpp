#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int length = 0;
    int* arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
    for(int i =0; i < N-1; i++)
    {
        if(arr[i] < 0)
        {
            for (int j = i + 1; j < N; j++)
            {
                if ((-1)*arr[i] == arr[j])
                {
                    if(((j-i)<length)||(length == 0))
                    {
                        length = j - i;
                    }

                }
            }
        }
    }
    std::cout << length << std::endl;
    return 0;
}
