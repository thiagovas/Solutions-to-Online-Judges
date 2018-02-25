#!/usr/bin/env python
# -*- coding: utf-8 -*-
# In this piece of code, I try to find the linear regression coefficients.

from sklearn import linear_model

model = linear_model.LinearRegression(fit_intercept=True)

train_x_data = []
train_y_data = []

with open('trainingdata.txt', 'r') as f:
  for line in f:
    line = [float(x) for x in line.split(',')]
    if line[0] > 3.9:
      continue
    train_x_data.append([line[0]])
    train_y_data.append(line[1])

model.fit(train_x_data, train_y_data)
print(model.coef_, model.intercept_)
