#include <iostream>
#include <tuple>
#include <cassert>

template <typename InTuple>
constexpr auto easy_unpack(const InTuple &tuple) {
    return std::make_tuple(std::get<0>(tuple), std::get<2>(tuple), std::get<std::tuple_size<InTuple>::value-2>(tuple));
}

int main()
{
    auto [a, b, c] = easy_unpack(std::make_tuple(1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10));
    std::cout << a << ' ' << b << ' ' << c << std::endl;

    assert(easy_unpack(std::make_tuple(1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10)) == std::make_tuple(1, "Mokus", "Cica"));
    assert(easy_unpack(std::make_tuple(1, "Macska", 2)) == std::make_tuple(1, 2, "Macska"));
}
