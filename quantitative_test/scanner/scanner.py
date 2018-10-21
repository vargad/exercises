#!/usr/bin/env python3
# 2018 Daniel Varga (vargad88@gmail.com)

import sys
import math
import numpy as np
import matplotlib.image as mpimg

img=mpimg.imread(sys.argv[1])

massTotal = 0
massSum = np.array([0,0])

# treat 'lighter' points as solid
def is_solid(px):
    return (px[0]+px[1]+px[2]) > 1

def pointsInsideCircle(center, radius):
    count = 0
    for i, imgLine in enumerate(img):
        for j, px in enumerate(imgLine):
            if is_solid(px):
                pos = np.array([i,j])
                if np.linalg.norm(center - pos) <= radius:
                    count += 1
    return count

for i, imgLine in enumerate(img):
    for j, px in enumerate(imgLine):
        if is_solid(px):
            massTotal += 1
            massSum[0] += i
            massSum[1] += j

centerOfMass = massSum/massTotal

# guess radius based on mass, should be close if it's a circle
guessedRadius = math.sqrt(massTotal/math.pi)

# consider it circle if at least 90% of the points are inside the candidate circle
if pointsInsideCircle(centerOfMass, guessedRadius) > massTotal*0.90:
    print("circle, center: (%.1f,%.1f) radius %f"%(centerOfMass[0], centerOfMass[1], guessedRadius))
else:
    print(massTotal*0.9)
    print(pointsInsideCircle(centerOfMass, guessedRadius))
    print("unknown shape, center of mass: (%.1f,%f.1)"%(centerOfMass[0], centerOfMass[1]))
