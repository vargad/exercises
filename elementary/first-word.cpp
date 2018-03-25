#include <cassert>
#include <iostream>
#include <regex>

std::string first_word(const std::string &text) {
    std::regex firstWord("[^a-zA-Z']*([a-zA-Z']+)");
    std::smatch match;
    std::regex_search(text, match, firstWord);
    return match[1];
}

std::string first_word2(const std::string &text) {
    auto isWordChar = [](char c) { return std::isalpha(c) || c == '\''; };
    auto b = std::find_if(text.begin(), text.end(), isWordChar);
    auto e = std::find_if(b, text.end(), [&](char c) { return !isWordChar(c); });
    return std::string(b, e);
}


int main()
{
    std::cout << first_word("Hello World") << std::endl;
    std::cout << first_word2("Hello World") << std::endl;

    assert(first_word("Hello World") == "Hello");
    assert(first_word(" more spaces ") == "more");
    assert(first_word("don't split it") == "don't");
    assert(first_word("hello, world") == "hello");
    assert(first_word("... very long sentence ...") == "very");
    assert(first_word("mokus") == "mokus");

    assert(first_word2("Hello World") == "Hello");
    assert(first_word2(" more spaces ") == "more");
    assert(first_word2("don't split it") == "don't");
    assert(first_word2("hello, world") == "hello");
    assert(first_word2("... very long sentence ...") == "very");
    assert(first_word2("mokus") == "mokus");
}
