#include <iostream>
using namespace std;
int main()
{
     unsigned int N;
     bool output;
     cin >> N;
     output = true;
     if (N > 1)
     {
         for (int i = 2; i < N; i++)
         {
             if (N % i == 0)
             {
                 output = false;
             }
             else if (output != false)
             {
                 output = true;
             }
         }
     }
     else
     {
         output = false;
     }
     if (output == true)
     {
         cout << "YES" << endl;
     }
     else
     {
         cout << "NO" << endl;
     }
}
