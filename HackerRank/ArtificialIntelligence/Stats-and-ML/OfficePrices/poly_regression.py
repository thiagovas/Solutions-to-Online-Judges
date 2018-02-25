#!/usr/bin/env python
# -*- coding: utf-8 -*-

from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.pipeline import Pipeline

model = Pipeline([('poly', PolynomialFeatures(degree=3)),
                  ('linear', LinearRegression(fit_intercept=False))])

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

model.fit(train_x_set, train_y_set)

t = int(input())
for i in range(t):
  line = [[float(x) for x in input().split()]]
  print(model.predict(line)[0])
