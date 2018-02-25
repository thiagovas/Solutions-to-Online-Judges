#!/usr/bin/env python
# -*- coding: utf-8 -*-
#

from sklearn.linear_model import LinearRegression

train_x_data = []
train_y_data = []
f, n, t = 0, 0, 0

line = [int(x) for x in input().split()]

f = line[0]
n = line[1]

for i in range(n):
  line = [float(x) for x in input().split()]
  train_x_data.append(line[:-1])
  train_y_data.append(line[-1])

model = LinearRegression(fit_intercept=True)
model.fit(train_x_data, train_y_data)

t = int(input())
for i in range(t):
  line = [float(x) for x in input().split()]
  print(model.predict([line])[0])
