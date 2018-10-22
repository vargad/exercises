#!/usr/bin/env python3

import sys
import cv2
import numpy as np

img = cv2.imread(sys.argv[1], 1)
cimg = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

imgSize = max(cimg.shape)

circles = cv2.HoughCircles(cimg, cv2.HOUGH_GRADIENT, 1, minDist=imgSize*0.2, param1=50,param2=10)

print(circles)
