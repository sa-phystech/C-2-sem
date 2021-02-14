#include <iostream>
using namespace std;
int main()
{
    int First, Second;
    cin >> First;
    cin >> Second;
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
        cout << Second << endl;
    }
    else
    {
        cout << First << endl;
    }
    return 0;
}
