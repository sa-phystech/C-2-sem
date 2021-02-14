#include <iostream>
using namespace std;
int main()
{
    int N, max, S;
    cin >> N;
    S = 1;
    max = N;
    while (N != 0)
    {
        if (N > max)
        {
            max = N;
            S = 1;
        }
        else if (N == max)
        {
           S++;
        }
        cin >> N;
    }
    cout << S << endl;
    return 0;
}
