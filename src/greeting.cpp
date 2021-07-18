#include "greeting.hpp"

namespace hello {

std::ostream& operator<<(std::ostream& out, const greeting& obj) {
    out << "Hello " << obj.name << '!';
    return out;
}

}  // namespace hello
