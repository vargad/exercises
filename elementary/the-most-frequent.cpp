#include <list>
#include <deque>
#include <cassert>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

template <typename Container>
typename Container::value_type most_frequent(const Container &container) {
    std::map<typename Container::value_type, std::size_t> counter;
    for (auto const &elem : container) counter[elem]++;
    return std::max_element(counter.begin(), counter.end(), [](auto const &lhs, auto const &rhs) { return lhs.second < rhs.second; })->first;
}

int main()
{
    std::cout << most_frequent(std::vector<int>{1,1,3,1,1,1,2}) << std::endl;
    assert(most_frequent(std::vector<int>{1,1,3,1,1,1,2}) == 1);
    assert(most_frequent(std::list<int>{2,2,2,3,4,5,6}) == 2);
    assert(most_frequent(std::deque<std::string>{"mokus","mokus","abc","ghj","koala","qwerty"}) == "mokus");
}
