#include "greeting.hpp"

#include <iostream>

int main()
{
    std::cout << hello::greeting{"World"} << '\n';
}
