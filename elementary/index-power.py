#!/usr/bin/env python3

def index_power(array, n):
    try:
        return array[n]**n
    except IndexError:
        return -1

if __name__ == '__main__':
    assert index_power([7, 2, 4, 8], 1) == 2
    assert index_power([7, 2, 10, 20, 9], 2) == 100
    assert index_power([20, 1], 0) == 1
    assert index_power([1], 4) == -1
