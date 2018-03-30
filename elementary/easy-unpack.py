#!/usr/bin/env python3

def easy_unpack(elements):
    return (elements[0], elements[2], elements[-2])

if __name__ == '__main__':
    a, b, c = easy_unpack((1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10));
    print(a, b, c)

    assert(easy_unpack((1, "Macska", "Mokus", 2, 3, 4 , 6, "Cica", 10)) == (1, "Mokus", "Cica"));
    assert(easy_unpack((1, "Macska", 2)) == (1, 2, "Macska"));
