#include "greeting.hpp"

namespace hello {

std::ostream& operator<<(std::ostream& out, const greeting& obj) {
    if (obj.name.empty()) {
        return out << "Hello!";
    }
    return out << "Hello " << obj.name << '!';
}

}  // namespace hello
