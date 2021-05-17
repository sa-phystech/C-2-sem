#include <iostream>

int main()
{
int a, b, c, d, x, x1, x2, mark;
std::cin >> a;
std::cin >> b;
std::cin >> c;
std::cin >> d;
std::cin >> x;
x1 = b - a;
x2 = d / c;
mark = 2;
if ( x == x1)
{
    mark += 2;
    if (x == x2)
    {
        mark += 1;
    }
}
else {if ( x == x2)
{
    mark += 2;
    if (x == x1)
    {
        mark += 1;
    }
}
else {if (x == 1024)
{
    mark += 1;
}}}

std::cout << mark << std::endl;
return 0;
}
