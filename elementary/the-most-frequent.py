#!/usr/bin/env python3

from collections import Counter

def most_frequent(data):
    return Counter(data).most_common(1)[0][0]

if __name__ == '__main__':
    print(most_frequent([1,1,3,1,1,1,2]))
    assert most_frequent([1,1,3,1,1,1,2]) == 1
    assert most_frequent([2,2,2,3,4,5,6]) == 2
    assert most_frequent(["mokus","mokus","abc","ghj","koala","qwerty"]) == "mokus"
