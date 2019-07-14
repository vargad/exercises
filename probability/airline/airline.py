#!/usr/bin/env python
# 2019 Daniel Varga (vargad88@gmail.com)

# There are 100 people to board a plane with 100 seats. First person lost his
# boarding pass taking a random seat. Everyone else takes their assigned seat
# if available, otherwise taking a random unoccupied seat. What is the
# probability that the last passenger ends up in his/her assigned seat?


import random


class Simulation(object):

    def __init__(self):
        self.tickets = list(range(100))
        random.shuffle(self.tickets)
        self.seats_free = list(range(100))

    def simulate_can_sit_own(self):
        if not self._sit_random_taking_last(): return False
        for ticket in self.tickets[1:-1]:
            if ticket in self.seats_free:
                self.seats_free.remove(ticket)
            else:
                if not self._sit_random_taking_last(): return False
        return True

    def _sit_random_taking_last(self):
        s = random.sample(self.seats_free, 1)[0]
        if s == self.tickets[-1]: return False
        self.seats_free.remove(s)
        return True

SIMULATE_TOTAL = 10000

own_seat = 0
for _ in range(SIMULATE_TOTAL):
    s = Simulation()
    if s.simulate_can_sit_own():
        own_seat += 1

print(own_seat/SIMULATE_TOTAL)
