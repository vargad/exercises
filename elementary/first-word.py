#!/usr/bin/env python3

import re

def first_word(text: str) -> str:
    return re.search("([a-zA-Z']+)", text)[1]

if __name__ == '__main__':
    print(first_word("Hello World"))

    assert first_word("Hello World") == "Hello"
    assert first_word(" more spaces ") == "more"
    assert first_word("don't split it") == "don't"
    assert first_word("hello, world") == "hello"
    assert first_word("... very long sentence ...") == "very"
    assert first_word("mokus") == "mokus"
