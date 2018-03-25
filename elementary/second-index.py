#!/usr/bin/env python3

def second_index(text: str, symbol: str):
    pos=text.find(symbol)
    if pos<0: return None
    pos=text.find(symbol, pos+1)
    return None if pos < 0 else pos

def second_index2(text: str, symbol: str):
    # Not so nice, using exception for control flow is discouraged generally
    try:
        return text.index(symbol, text.index(symbol) + 1)
    except ValueError:
        return None

if __name__ == '__main__':
    print(second_index("Hello World", 'o'))
    print(second_index2("Hello World", 'o'))

    assert second_index("Hello World", 'o') == 7
    assert second_index(" more spaces ", 'e') == 10
    assert second_index("hello, world", ' ') == None
    assert second_index("... very long sentence ...", ' ') == 8

    assert second_index2("Hello World", 'o') == 7
    assert second_index2(" more spaces ", 'e') == 10
    assert second_index2("hello, world", ' ') == None
    assert second_index2("... very long sentence ...", ' ') == 8
