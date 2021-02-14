#include <iostream>
using namespace std;
int main()
{
    int Year;
    cin >> Year;
    if (Year % 400 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        if ((Year % 4 == 0) && (Year % 100 != 0))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
