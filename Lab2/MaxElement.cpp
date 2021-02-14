#include <iostream>
using namespace std;
int main()
{
    int N, max;
    cin >> N;
    max = N;
    while (N != 0)
    {
        if (N > max)
        {
            max = N;
        }
        cin >> N;
    }
    cout << max << endl;
    return 0;
}
