#!/bin/python3

import sys
timeCharged = float(input().strip())

timeCharged *= 2
timeCharged = min(8, timeCharged)
print(timeCharged)
