#include <iostream>
using namespace std;
int main()
{
    unsigned int N;
    double S;
    cin >> N;
    S = 0;
    for (int i = 1; i < N + 1; i++)
    {
        S = S + 1/(static_cast<double>(i)*static_cast<double>(i));
    }
    cout << S << endl;
    return 0;
}
