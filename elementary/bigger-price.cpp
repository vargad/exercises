#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

struct Product {
    std::string name;
    int price;

    bool operator==(Product const &rhs) const {
        return name == rhs.name && price == rhs.price;
    }
};

std::vector<Product> bigger_price(int limit, std::vector<Product> const &data) {
    std::vector<Product> result(limit);
    std::partial_sort_copy(data.begin(), data.end(), result.begin(), result.end(),
            [](auto lhs, auto rhs){ return lhs.price > rhs.price; });
    return result;
}

std::ostream& operator<<(std::ostream &os, std::vector<Product> const &products) {
    for (auto const &product : products) {
        os << "{ name: " << product.name << ", price: " << product.price << " }\n";
    }
    return os;
}

int main()
{
    std::cout << bigger_price(2, {
            {"cheese", 110},
            {"wine", 152},
            {"meat", 60},
            {"olives", 50}
        }) << std::endl;

    assert(bigger_price(2, {
            {"cheese", 110},
            {"wine", 152},
            {"meat", 60},
            {"olives", 50}
        }) == std::vector<Product>({
            {"wine", 152},
            {"cheese", 110}
        }));

    assert(bigger_price(1, {
            {"pen", 2},
            {"paper", 120}
        }) == std::vector<Product>({{"paper", 120}}));
}
