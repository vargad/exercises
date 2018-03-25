#include <cassert>
#include <iostream>
#include <regex>
#include <cctype>

std::string secret_message(const std::string &text) {
    return std::regex_replace(text, std::regex("[^A-Z]"), "");
}

std::string secret_message2(const std::string &text) {
    std::string result;
    for (auto c : text)
    {
        if (std::isupper(c)) result.push_back(c);
    }
    return result;
}


int main()
{
    std::cout << secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") << std::endl;

    assert(secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") == "MACSKA");
    assert(secret_message("hello world!") == "");
    assert(secret_message("HELLO WORLD!") == "HELLOWORLD");

    assert(secret_message2("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") == "MACSKA");
    assert(secret_message2("hello world!") == "");
    assert(secret_message2("HELLO WORLD!") == "HELLOWORLD");
}
