#include <iostream>
using namespace std;
int main()
{
  int n, c;
  cin >> n;
  c = 2;
  while (n > 1)
  {
    while (n % c == 0)
    {
      cout << c << endl;
      n = n / c;
    }
    c = c + 1;
  }
  return 0;
}
