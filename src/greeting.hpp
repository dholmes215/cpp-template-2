#ifndef GREETING_HPP
#define GREETING_HPP

#include <iostream>
#include <string>

namespace hello {

struct greeting {
    std::string name{};
    friend std::ostream& operator<<(std::ostream& out, const greeting& obj);
};

}  // namespace hello

#endif  // GREETING_HPP
