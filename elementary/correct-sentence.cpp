#include <iostream>
#include <locale>
#include <cassert>

std::string correct_sentence(const std::string &text) {
    return std::toupper(text[0], std::locale())+text.substr(1, text.npos)+(text.back() == '.' ? "" : ".");
}

int main()
{
    std::cout << correct_sentence("hello, world") << std::endl;
    assert(correct_sentence("hello, world") == "Hello, world.");
    assert(correct_sentence("kis mokus felmaszott a fara.") == "Kis mokus felmaszott a fara.");
}
