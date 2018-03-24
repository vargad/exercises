#!/usr/bin/env python3

def correct_sentence(text: str) -> str:
    return text[0].upper()+text[1:]+("" if text[-1] == "." else ".")

if __name__ == '__main__':
    print(correct_sentence("hello, world"))
    assert correct_sentence("hello, world") == "Hello, world."
    assert correct_sentence("kis mokus felmaszott a fara.") == "Kis mokus felmaszott a fara."
