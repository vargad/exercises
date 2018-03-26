#include <cassert>
#include <algorithm>

// tail recursion, compiler should be able to compile as a loop
// anyway, number of digits is quite limited, this should not cause stack overflow
int digits_multiplication(int number) {
    if (number == 0) return 1;
    return std::max(number%10, 1) * digits_multiplication(number/10);
}

int main()
{
    assert(digits_multiplication(102345) == 120);
    assert(digits_multiplication(555) == 125);
    assert(digits_multiplication(2000) == 2);
    assert(digits_multiplication(1111111) == 1);
}
