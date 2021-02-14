#include <iostream>
#include <string>
using namespace std;

int
main ()
{
  unsigned int N;
  unsigned int s;
  unsigned int p;
  int j;
  j = 0;
  cin >> N;
  s = 0;
  p = 0;
  if (N < 60)
    {
      j = j + 1;
    }
  while (N > 0)
    {
      p = N % 60;
      s = s * 100 + (p % 10) * 10 + (p / 10);
      N = N / 60;
    }
  p = 0;
  N = 0;
  while (s > 0)
    {
      p = (s % 10);
      N = (s % 100) / 10;
      for (int i = 0; i < p; i++)
	    {
	      cout << "<";
	    }
      for (int i = 0; i < N; i++)
	    {
	      cout << "v";
	    }
      s = s / 100;
      if ((s != 0) || (j == 0))
	    {
	      cout << ".";
	    }
      j = j + 1;

    }

  return 0;
}

