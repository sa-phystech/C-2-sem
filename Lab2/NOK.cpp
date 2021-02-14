#include <iostream>
using namespace std;
int main()
{
    int First, Second, a, b;
    cin >> First;
    cin >> Second;
    a = First;
    b = Second;
    while ((First != 0) && (Second != 0))
    {
        if (First > Second)
        {
            First = First % Second;
        }
        else
        {
            Second = Second % First;
        }
    }
    if (First == 0)
    {
        cout << (a*b)/Second << endl;
    }
    else
    {
        cout << (a*b)/First << endl;
    }
    return 0;
}
