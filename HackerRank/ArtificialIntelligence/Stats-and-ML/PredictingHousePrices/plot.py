#!/usr/bin/env python
# -*- coding: utf-8 -*-
#

import matplotlib.pyplot as plt

train_x_data = []
train_y_data = []
f_data = []
f, n, t = 0, 0, 0

line = [int(x) for x in input().split()]

f = line[0]
n = line[1]

for i in range(n):
  line = [float(x) for x in input().split()]
  train_x_data.append(line[:-1])
  train_y_data.append(line[-1])
  f_data.append(line[1])

plt.plot(f_data, train_y_data, 'ro')
plt.show()
