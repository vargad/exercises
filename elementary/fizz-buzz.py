#!/usr/bin/env python3

def fizz_buzz(number):
    if number%15==0: return "Fizz Buzz"
    if number%3==0: return "Fizz"
    if number%5==0: return "Buzz"
    return str(number)

if __name__ == '__main__':
    assert fizz_buzz(30) == "Fizz Buzz"
    assert fizz_buzz(12) == "Fizz"
    assert fizz_buzz(5) == "Buzz"
    assert fizz_buzz(13) == "13"
