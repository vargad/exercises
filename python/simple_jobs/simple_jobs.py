#!/usr/bin/env python3
# 2019 Daniel Varga (vargad88@gmail.com)

import time
import math
import traceback
import logging
from multiprocessing import Pool

logger = logging.getLogger(__file__)

def is_prime(num):
    divisors = 0
    for i in range(2, int(math.sqrt(num))):
        if num%i == 0: divisors += 1
    return divisors == 0

def test_job_calc_primes(upto):
    logger.info("[START] up to %d", upto)
    primes = 0
    for i in range(upto):
        if is_prime(i): primes += 1
    logger.info("[DONE] up to %d found %d primes", upto, primes)

def mandelbrot(z, maxiter):
    c = z
    for n in range(maxiter):
        if abs(z) > 2:
            return n
        z = z*z + c
    return True

def test_job_mandelbrot(width, height):
    logger.info("[START] %dx%d", width, height)
    maxiter = 16
    char_map = ['#', '@', '&', '0', 'O', 'o', '+', '-']
    pic = []
    for i in range(width):
        row = ""
        for j in range(height):
            result = mandelbrot(complex(i/width*3-2, j/height*2-1), maxiter)
            row += " " if result == True else char_map[int(result/(maxiter/len(char_map)))]
        pic.append(row)
    print("\n".join(pic))
    logger.info("[DONE] %dx%d", width, height)

def test_job_broken():
    time.sleep(5)
    raise Exception("Not working sorry")

if __name__ == '__main__':
    logging.basicConfig(format='%(asctime)-15s [%(levelname)s] %(funcName)s: %(message)s', level=logging.INFO)

    # make a pool with as many workes as cpu core on current machine
    pool = Pool(processes=None)
    jobs = []
    jobs.append(pool.apply_async(test_job_calc_primes, (10**3,)))
    jobs.append(pool.apply_async(test_job_calc_primes, (10**4,)))
    jobs.append(pool.apply_async(test_job_calc_primes, (10**5,)))
    jobs.append(pool.apply_async(test_job_mandelbrot, (90, 60)))
    jobs.append(pool.apply_async(test_job_mandelbrot, (30, 20)))
    jobs.append(pool.apply_async(test_job_broken))

    for job in jobs:
        try:
            job.get()
        except:
            logger.error("job error: %s", traceback.format_exc())
