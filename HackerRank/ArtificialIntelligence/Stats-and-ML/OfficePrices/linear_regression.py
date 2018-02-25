#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sklearn import linear_model

reg = linear_model.LinearRegression()

train_x_set = []
train_y_set = []
f, n, t = 0, 0, 0

line = [int(x) for x in input().split()]
f = line[0]
n = line[1]

for i in range(n):
  line = [float(x) for x in input().split()]
  train_x_set.append(line[:-1])
  train_y_set.append(line[-1])

reg.fit(train_x_set, train_y_set)


t = int(input())
for i in range(t):
  line = [[float(x) for x in input().split()]]
  print(reg.predict(line)[0])
