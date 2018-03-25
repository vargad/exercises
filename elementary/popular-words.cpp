#include <iostream>
#include <cassert>
#include <locale>
#include <set>
#include <map>
#include <string>
#include <regex>
#include <algorithm>

template <typename Callback>
void each_word(std::string const &text, Callback cb) {
    auto isWordChar = [](char c){ return std::isalpha(c, std::locale()); };
    auto isNotWordChar = [](char c){ return !std::isalpha(c, std::locale()); };
    auto pos = std::find_if(text.begin(), text.end(), isWordChar);
    while (pos != text.end()) {
        auto wordEnd = std::find_if(pos, text.end(), isNotWordChar);
        cb(std::string(pos, wordEnd));
        pos = std::find_if(wordEnd, text.end(), isWordChar);
    }
}

std::map<std::string, int> popular_words(std::string text, std::set<std::string> const &words) {
    std::map<std::string, int> counter;
    // downcase text
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    each_word(text, [&](std::string const &word) {
            if (words.count(word) > 0) counter[word] += 1;
    });

    // set missing ones to zero
    for (auto const &word : words) counter.emplace(word, 0);
    return counter;
}

std::map<std::string, int> popular_words2(std::string text, std::set<std::string> const &words) {
    std::map<std::string, int> counter;
    // downcase text
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);

    std::regex word_match("['[:alpha:]]+");
    //std::regex word_match("[a-z]+");
    std::for_each(std::sregex_token_iterator(text.begin(), text.end(), word_match),
            std::sregex_token_iterator(),
            [&](auto match) {
                if (words.count(match) > 0) counter[match] += 1;
            });
    // set missing ones to zero
    for (auto const &word : words) counter.emplace(word, 0);
    return counter;
}

int main()
{
    std::string poem = "Tuzesen sut le a nyari nap sugara\n"
            "Az eg tetejerol a juhaszbojtarra.\n"
            "Folosleges dolog sutnie oly nagyon,\n"
            "A juhasznak ugyis nagy melege vagyon\n";
    assert((popular_words(poem, {"a", "nagy", "macska"})
            == std::map<std::string, int>({ {"a", 3}, {"nagy", 1}, {"macska", 0} })));
    assert((popular_words2(poem, {"a", "nagy", "macska"})
            == std::map<std::string, int>({ {"a", 3}, {"nagy", 1}, {"macska", 0} })));
}
