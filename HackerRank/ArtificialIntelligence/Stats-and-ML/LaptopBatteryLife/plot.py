#!/usr/bin/env python
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt

train_x_data = []
train_y_data = []

print('hue1')

with open('trainingdata.txt', 'r') as f:
  for line in f:
    line = [float(x) for x in line.split(',')]
    train_x_data.append(line[0])
    train_y_data.append(line[1])

print('hue2')
plt.plot(train_x_data, train_y_data, 'ro')
plt.show()
