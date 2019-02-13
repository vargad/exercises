#!/usr/bin/env python3
# 2019 Daniel Varga (vargad88@gmail.com)

# There are 300 different cards. How many cards I need to buy so that I have 50% chance getting all the 300 different cards.

import random
from collections import defaultdict


have300 = defaultdict(lambda:0)
TOTAL=40000
for _ in range(TOTAL):
    missing_cards = set(range(0,300))
    buys = 0
    while len(missing_cards)>0:
        bought = random.randint(0,299)
        if bought in missing_cards:
            missing_cards.remove(bought)
        buys += 1
    have300[buys] +=  1

have300_so_far = 0.0
prob = {}
for brought, count in sorted(have300.items(), key=lambda item: item[0]):
    have300_so_far += count
    prob[brought] = have300_so_far / TOTAL

for bought, p in prob.items():
    print(f"{brought} #{p*100}")
