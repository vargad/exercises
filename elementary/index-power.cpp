#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

constexpr std::int64_t pow(std::int64_t num, std::int64_t power) {
    if (power < 1) return 1;
    return num*pow(num, power-1);
}

std::int64_t index_power(std::vector<int> const &array, std::size_t n) {
    return n >= array.size() ? -1 : pow(array[n], n);
}

int main()
{
    assert(index_power({7, 2, 4, 8}, 1) == 2);
    assert(index_power({7, 2, 10, 20, 9}, 2) == 100);
    assert(index_power({20, 1}, 0) == 1);
    assert(index_power({1}, 4) == -1);
}
