#!/usr/bin/env ruby
# 2018 Daniel Varga (vargad88@gmail.com)

import random

def simulate_colony():
    size = 1
    while size > 0 and size < 2000:
        new_size = 0
        for _ in range(size):
            new_size += random.randint(0,3)
        size = new_size
    return size > 0

iterations=10000
dieout = 0
for _ in range(iterations):
    if not simulate_colony(): dieout += 1

print("chance of never die: %f"%(100-float(dieout)/iterations*100))
