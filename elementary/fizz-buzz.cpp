#include <cassert>
#include <string>
#include <algorithm>

std::string fizz_buzz(int number) {
    if (number%15==0) return "Fizz Buzz";
    if (number%3==0) return "Fizz";
    if (number%5==0) return "Buzz";
    return std::to_string(number);
}

std::string fizz_buzz2(int number) {
    return number%15 ? (number%3 ? (number%5 ? std::to_string(number) : "Buzz") : "Fizz") : "Fizz Buzz";
}

int main()
{
    assert(fizz_buzz(30) == "Fizz Buzz");
    assert(fizz_buzz(12) == "Fizz");
    assert(fizz_buzz(5) == "Buzz");
    assert(fizz_buzz(13) == "13");

    assert(fizz_buzz2(30) == "Fizz Buzz");
    assert(fizz_buzz2(12) == "Fizz");
    assert(fizz_buzz2(5) == "Buzz");
    assert(fizz_buzz2(13) == "13");
}
