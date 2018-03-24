#!/usr/bin/env python3

def say_hi(name, age):
    return f"Hi. My name is {name} and I'm {age} years old"

if __name__ == '__main__':
    assert say_hi("Kitty", 28) == "Hi. My name is Kitty and I'm 28 years old"
    assert say_hi("Peter", 42) == "Hi. My name is Peter and I'm 42 years old"
