#include <cassert>
#include <vector>
#include <array>
#include <list>
#include <iostream>

int even_last(std::vector<int> const &v) {
    int sum = 0;
    for (std::size_t i=0; i<v.size(); i+=2) sum += v[i];
    return v.empty() ? 0 : sum*v.back();
}

template <typename Container>
auto even_last2(Container const &c) {
    typename Container::value_type sum = 0;
    // A little but more complicated, but slighlt more flexable
    // std::remove_reference<decltype(*(c.begin()))> sum = 0;
    auto it = std::begin(c);
    auto last = it;
    while (it != std::end(c)) {
        sum += *it;
        last = it;
        // increment iterator
        ++it;
        // skip next element, we only need every second
        if (it != std::end(c)) {
            last = it;
            ++it;
        }
    }
    return last == std::end(c) ? 0 : sum*(*last);
}

int main()
{
    std::cout << even_last2(std::list<int>{1,2,3,4,5}) << std::endl;
    assert(even_last(std::vector<int>{1,2,3,4,5}) == 45);
    assert(even_last2(std::list<int>{1,2,3,4,5}) == 45);
    assert(even_last2(std::vector<double>{1.5,2,3.5,4,5,6}) == 60);
    assert(even_last2(std::array<int,6>{1,2,3,4,5,6}) == 54);
}
