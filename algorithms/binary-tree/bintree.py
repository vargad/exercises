#!/usr/bin/env python3
# 2019 Daniel Varga (vargad88@gmail.com)

import random

class Tree(object):
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def pretty_format(self, depth=0):
        s = ""
        if self.left:
            s += self.left.pretty_format(depth+2)
        s += " "*depth+str(self.value)+"\n"
        if self.right:
            s += self.right.pretty_format(depth+2)
        return s

    def __str__(self):
        return self.pretty_format()

def insert(root, value):
    if root == None:
        return Tree(value)
    if root.value == value:
        return root
    if root.value > value:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root

def inorder(root, cb):
    if root == None:
        return
    inorder(root.left, cb)
    cb(root.value)
    inorder(root.right, cb)

def preorder(root, cb):
    if root == None:
        return
    cb(root.value)
    inorder(root.left, cb)
    inorder(root.right, cb)

def depth(root):
    if root == None:
        return 0
    return 1+max(depth(root.left), depth(root.right))

def leaves(root):
    if root == None:
        return 0
    if root.left == None and root.right == None:
        return 1
    return leaves(root.left)+leaves(root.right)

def getmax(root):
    if root == None:
        return None
    if root.right:
        return getmax(root.right)
    return root.value

t = None
for _ in range(10):
    v = random.randint(10,99)
    print(f"INSERT {v}")
    t = insert(t, v)

print(t)

print("inorder:")
inorder(t, lambda e: print(e))
print("preorder:")
preorder(t, lambda e: print(e))
print(f"depth: {depth(t)}")
print(f"leaves: {leaves(t)}")
print(f"max: {getmax(t)}")
