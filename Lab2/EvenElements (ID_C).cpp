#include <iostream>
using namespace std;
int main()
{
    int N, S;
    cin >> N;
    S = 0;
    while (N != 0)
    {
        if (N % 2 == 0)
        {
            S = S + 1;
        }
        cin >> N;
    }
    cout << S << endl;
    return 0;
}
