#include "greeting.hpp"

#include <fmt/format.h>

int main()
{
    fmt::print("{}\n", hello::greeting{"World"});
}
