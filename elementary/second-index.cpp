#include <cassert>
#include <iostream>
#include <string>

std::size_t second_index(const std::string &text, char symbol) {
    auto pos = text.find(symbol);
    if (pos == text.npos) return pos;
    return text.find(symbol, pos+1);
}

int main()
{
    std::cout << second_index("Hello World", 'o') << std::endl;

    assert(second_index("Hello World", 'o') == 7);
    assert(second_index(" more spaces ", 'e') == 10);
    assert(second_index("hello, world", ' ') == std::string::npos);
    assert(second_index("... very long sentence ...", ' ') == 8);
}
