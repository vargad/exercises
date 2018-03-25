#include <cassert>
#include <iostream>
#include <regex>

bool three_words(const std::string &text) {
    return std::regex_search(text, std::regex("[a-zA-Z]+ [a-zA-Z]+ [a-zA-Z]+"));
}

int main()
{
    assert(three_words("Mokus felmaszott fara") == true);
    assert(three_words("This squirrel 999 apple") == false);
    assert(three_words("9 8 7 6") == false);
    assert(three_words("little little little") == true);
    assert(three_words("Wow") == false);
}
