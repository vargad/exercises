#include <cassert>
#include <iostream>
#include <string>

std::string between_markers(std::string const &text, std::string const &beginMarker, std::string const &endMarker)
{
    auto beginPos = text.find(beginMarker);
    auto endPos = text.find(endMarker);
    beginPos = beginPos == text.npos ? 0 : beginPos+beginMarker.size();
    return text.substr(beginPos, endPos == text.npos ? endPos : endPos-beginPos);
}

int main()
{
    std::cout << between_markers("What is >love<", ">", "<") << std::endl;
    std::cout << between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>") << std::endl;

    assert(between_markers("What is >love<", ">", "<") == "love");
    assert(between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>") == "My Little Phony");
    assert(between_markers("<body><h1>My Little Phony", "<h1>", "</h1>") == "My Little Phony");
    assert(between_markers("My Little Phony", "<h1>", "</h1>") == "My Little Phony");
    assert(between_markers("What is <love>", ">", "<") == "");
}
