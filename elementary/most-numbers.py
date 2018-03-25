#!/usr/bin/env python3

def most_numbers(*args):
    return max(args)-min(args) if args else 0

if __name__ == '__main__':
    print(most_numbers(2,5,3,7,5,8))
    assert most_numbers(2,5,3,7,5,8) == 6
    assert most_numbers(2.5,5,3,7,5,8.5) == 6
    assert most_numbers() == 0
    assert most_numbers(2,5,7,6,4) == 5
