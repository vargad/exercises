#!/usr/bin/env python3

import re

def popular_words(text, words):
    counter = { word: 0 for word in words }
    for word in re.split("[^a-z']", text.lower()):
        if word in counter: counter[word] += 1
    return counter

if __name__ == '__main__':
    poem = '''Tuzesen sut le a nyari nap sugara\n
           Az eg tetejerol a juhaszbojtarra.\n
           Folosleges dolog sutnie oly nagyon,\n
           A juhasznak ugyis nagy melege vagyon\n'''

    print(popular_words(poem, ["a", "nagy", "macska"]))
    assert popular_words(poem, ["a", "nagy", "macska"]) == { "a": 3, "nagy": 1, "macska": 0 }
