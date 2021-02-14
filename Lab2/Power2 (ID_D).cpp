#include <iostream>
using namespace std;
int main()
{
    unsigned int N;
    bool power;
    power = true;
    cin >> N;
    while ((N > 1)&&(power == true))
    {
        if (N % 2 == 1)
        {
            power = false;
        }
        else
        {
            power = true;
        }
        N = N/2;
    }
    if (power == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
