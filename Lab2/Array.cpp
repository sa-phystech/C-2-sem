#include <iostream>
using namespace std;
int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : A)
    {
        cout << i << endl;
    }
    cout << sizeof(A)/sizeof(int) << endl;
    auto x = A;
    cout << x << endl;
    return 0;
}
