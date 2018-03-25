#!/usr/bin/env python3

import re

def secret_message(text):
    return re.sub("[^A-Z]", "", text)

if __name__ == '__main__':
    print(secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten."))
    assert secret_message("Meow... Arggh... Choose the Silver Key to enter the Arcane temple of kitten.") == "MACSKA"
    assert secret_message("hello world!") == ""
    assert secret_message("HELLO WORLD!") == "HELLOWORLD"
