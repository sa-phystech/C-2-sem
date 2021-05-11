#include <iostream>

using namespace std;

int main()
{
    int N, Sum;
    double Middle;
    Middle = 0.;
    Sum = 0;
    cin >> N;
    int* array = new int [N];
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        Middle = Middle + array[i];
    }
    Middle = Middle / N;
    for (int i = 0; i < N; i++)
    {
        if (array[i] > Middle)
        {
            Sum = Sum + array[i];
        }
    }
    delete [] array;
    cout << Sum << endl;
    return 0;
}
