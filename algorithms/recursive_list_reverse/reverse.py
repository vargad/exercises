#!/usr/bin/env python3
# 2017 Daniel Varga (vargad88@gmail.com)

class LinkedList:
    def __init__(self, data, rest=None):
        self.data = data
        self.next = rest

    def __str__(self):
        return "%d, %s" % (self.data, self.next)

def make_list(*elements):
    # alternate solution
    # from functools import reduce
    # return reduce(lambda c, e: LinkedList(e, c), reversed(elements), None)
    list = None
    for e in reversed(elements):
        list = LinkedList(e, list)
    return list

def reverse(list, rest=None):
    if list == None: return rest
    return reverse(list.next, LinkedList(list.data, rest))

l = make_list(1,2,3,4,5,6,7)
print(l)
l2 = reverse(l)
print(l2)
