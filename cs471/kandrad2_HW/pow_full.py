#! /usr/bin/env python3

def powI(pow, base)
    acc = 1
    for p in range(pow)
        acc = acc * base
    return acc

def powF(pow, base)
    if pow == 0
        return 1;

    return base * powF(pow-1, base)
