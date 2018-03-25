#!/usr/bin/env python3

import re

def three_words(words):
    return re.search("[a-zA-Z]+ [a-zA-Z]+ [a-zA-Z]+", words) != None

if __name__ == '__main__':
    assert three_words("Mokus felmaszott fara") == True
    assert three_words("This squirrel 999 apple") == False
    assert three_words("9 8 7 6") == False
    assert three_words("little little little") == True
    assert three_words("Wow") == False
