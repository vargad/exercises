#include <cassert>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>

template <typename Container>
void absolute_sort(Container &container) {
    std::sort(container.begin(), container.end(), [](auto const &lhs, auto const &rhs){ return std::abs(lhs) < std::abs(rhs); });
}

int main()
{
    std::vector<int> v1 = { -13, 3, -18, 24 };
    absolute_sort(v1);
    assert((v1 == std::vector<int>{3, -13, -18, 24}));

    std::vector<int> v2 = { 1, 2, 3, 0 };
    absolute_sort(v2);
    assert((v2 == std::vector<int>{0, 1, 2, 3}));

    std::deque<int> v3 = { -42, -43, -44, 0 };
    absolute_sort(v3);
    assert((v3 == std::deque<int>{0, -42, -43, -44}));
}
