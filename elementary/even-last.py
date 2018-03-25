#!/usr/bin/env python3

def even_last(array):
    return sum((v for i, v in enumerate(array) if i%2==0))*(array[-1] if array else 0)

if __name__ == '__main__':
    print(even_last([1,2,3,4,5]))
    assert even_last([1,2,3,4,5]) == 45
    assert even_last([1,2,3,4,5]) == 45
    assert even_last([1.5,2,3.5,4,5,6]) == 60
    assert even_last([1,2,3,4,5,6]) == 54
