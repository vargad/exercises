#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

std::string find_and_replace(std::string const &str, std::string const &find, std::string const &replace)
{
    std::string result;
    std::size_t start = 0;
    auto pos = str.find(find);
    while (pos != str.npos) {
        result.append(str, start, pos-start);
        result.append(replace);
        start = pos+find.size();
        pos = str.find(find, start);
    }
    result.append(str, start, str.size()-start);
    return result;
}

std::string left_join(std::vector<std::string> const &phrases) {
    return find_and_replace(std::accumulate(phrases.begin(), phrases.end(), std::string(),
            [](std::string const &accu, std::string const &str) {
                return accu.empty() ? str : accu+','+str;
            }), "right", "left");
}

int main()
{
    std::cout << left_join({"right", "right", "left", "left", "forward"}) << std::endl;
    assert(left_join({"right", "right", "left", "left", "forward"}) == "left,left,left,left,forward");
    assert(left_join({"alright outright", "squirrel"}) == "alleft outleft,squirrel");
    assert(left_join({"frightened", "eyebright"}) == "fleftened,eyebleft");
    assert(left_join({"little", "squirrel"}) == "little,squirrel");
}
