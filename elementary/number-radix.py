#!/usr/bin/env python3

def number_radix(str_number, radix):
    try:
        return int(str_number, radix)
    except:
        return -1

if __name__ == '__main__':
    assert number_radix("1234", 10) == 1234
    assert number_radix("FF", 16) == 255
    assert number_radix("FF", 10) == -1
