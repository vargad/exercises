#!/usr/bin/env python3
# 2018 Daniel Varga (vargad88@gmail.com)

import sys
from scipy.stats import binom

n = 40
p = 0.7

def value_func(value, round_left):
    sf = binom.sf(value, n, p)
    if round_left == 1: return sf
    prob = sf
    for _ in range(round_left-1):
        prob = prob+sf - prob*sf
    assert prob <= 1 # this must always hold
    return prob

rounds = int(sys.argv[1])

A=[]

for round_left in range(rounds-1,0,-1):
    for v in range(n,0, -1):
        if value_func(v, round_left)>=0.5:
            A.append(v)
            break

A.append(0)
print(A)
