#include <iostream>
using namespace std;
int main()
{
    int N, max;
    cin >> N;
    if (N % 2 == 0)
    {
        max = N;
    }
    else
    {
        max = 0;
    }
    while (N != 0)
    {
        if ((N > max) && (N % 2 == 0))
        {
            max = N;
        }
        cin >> N;
    }
    if (max != 0)
    {
        cout << max << endl;
    }
    else
    {
        cout << "There is no even elements" << endl;
    }
    return 0;
}
