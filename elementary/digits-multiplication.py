#!/usr/bin/env python3

def digits_multiplication(number):
    if number == 0: return 1
    return max(number%10,1)*digits_multiplication(int(number/10))

if __name__ == '__main__':
    assert digits_multiplication(102345) == 120
    assert digits_multiplication(555) == 125
    assert digits_multiplication(2000) == 2
    assert digits_multiplication(1111111) == 1
