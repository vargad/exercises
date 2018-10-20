#!/usr/bin/env python3
# 2018 Daniel Varga (vargad88@gmail.com)

from itertools import permutations

def joindigits(arr):
    return int(''.join((str(d) for d in arr)))

def solve():
    for p in permutations(range(1,10), 9):
        if (p[7]*p[8])%10 != p[3]: continue
        d,m = divmod(joindigits(p[0:4]), joindigits(p[4:8]))
        if m == 0 and d == p[8]: yield p

for s in solve():
    print(f"{joindigits(s[0:4])}/{joindigits(s[4:8])}={s[8]}")
