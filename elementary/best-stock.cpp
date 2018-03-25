#include <iostream>
#include <cassert>
#include <map>
#include <string>
#include <algorithm>

std::string best_stock(std::map<std::string, double> const &data) {
    return std::max_element(data.begin(), data.end(), [](auto lhs, auto rhs){ return lhs.second < rhs.second; })->first;
}

int main()
{
    std::cout << best_stock({ {"CAL", 42.0}, {"GOG", 190.5}, {"DAG", 32.2} }) << std::endl;

    assert(best_stock({ {"CAL", 42.0}, {"GOG", 190.5}, {"DAG", 32.2} }) == "GOG");
    assert(best_stock({ {"CAL", 31.4}, {"GOG", 3.42}, {"APL", 170.34} }) == "APL");
}
