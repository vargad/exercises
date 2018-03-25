#include <cassert>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <iostream>

template <typename Container>
auto most_numbers(Container const &c) {
    auto max_it = std::max_element(std::begin(c), std::end(c));
    auto min_it = std::min_element(std::begin(c), std::end(c));
    return max_it == std::end(c) ? 0 : (*max_it) - (*min_it);
}

int main()
{
    std::cout << most_numbers(std::list<int>{2,5,3,7,5,8}) << std::endl;
    assert(most_numbers(std::list<int>{2,5,3,7,5,8}) == 6);
    assert(most_numbers(std::vector<double>{2.5,5,3,7,5,8.5}) == 6);
    assert(most_numbers(std::vector<int>{}) == 0);
    assert(most_numbers(std::array<int,5>{2,5,7,6,4}) == 5);
}
