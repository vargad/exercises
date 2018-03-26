#include <cassert>
#include <stdexcept>
#include <string>

int number_radix(const std::string &text, int radix) {
    try {
        return std::stoi(text, nullptr, radix);
    } catch (std::invalid_argument &) {
        return -1;
    }
}

int main()
{
    assert(number_radix("1234", 10) == 1234);
    assert(number_radix("FF", 16) == 255);
    assert(number_radix("FF", 10) == -1);
}
