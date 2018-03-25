#!/usr/bin/env python3

def between_markers(text: str, begin: str, end: str) -> str:
    b=text.find(begin)
    e=text.find(end)
    b=0 if b==-1 else b+len(begin)
    return text[b:] if e==-1 else text[b:e]

if __name__ == '__main__':
    print(between_markers("What is >love<", ">", "<"))
    print(between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>"))

    assert between_markers("What is >love<", ">", "<") == "love"
    assert between_markers("<body><h1>My Little Phony</h1></body>", "<h1>", "</h1>") == "My Little Phony"
    assert between_markers("<body><h1>My Little Phony", "<h1>", "</h1>") == "My Little Phony"
    assert between_markers("My Little Phony", "<h1>", "</h1>") == "My Little Phony"
    assert between_markers("What is <love>", ">", "<") == ""
