#!/usr/bin/env python3

def absolute_sort(numbers_array):
    return sorted(numbers_array,key=abs)

if __name__ == '__main__':
    print(absolute_sort([-13, 3, -18, 24]))
    assert absolute_sort([-13, 3, -18, 24]) == [3, -13, -18, 24]
    assert absolute_sort([1, 2, 3, 0]) == [0, 1, 2, 3]
    assert absolute_sort([-42, -43, -44, 0]) == [0, -42, -43, -44]
