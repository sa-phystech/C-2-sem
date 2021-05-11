#include <iostream>

int main()
{
    int* a;
    int* b;
    int x, y;
    std::cin >> x;
    std::cin >> y;
    a = &x;
    b = &y;
    std::cout << do_some_awesome_work(a, b) << std::endl;
    return 0;

}
