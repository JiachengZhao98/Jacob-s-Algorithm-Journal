import csv
import numpy as np
import math
import matplotlib.pyplot as plt

# Global variables for storing CSV data
xList = []
yList = []

# read data from the CSV file
def readDataFromCSV(filename):
    xList = []
    yList = []
    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            if not row[0].isdigit():
                continue
            xList.append(int(row[0]))
            yList.append(float(row[1]))
    return xList, yList

# Solving tridiagonal matrices using LU factorization
def LUFactorization(a, b, c, d, n):
    mu = [0] * (n + 1)
    l = [0] * (n + 1)
    mu[1] = b[1]
    for i in range(2, n + 1):
        l[i] = a[i] / mu[i - 1]
        mu[i] = b[i] - l[i] * c[i - 1]
    y = [0] * (n + 1)
    x = [0] * (n + 1)
    y[1] = d[1]
    for i in range(2, n + 1):
        y[i] = d[i] - l[i] * y[i - 1]
    x[n] = y[n] / mu[n]
    for i in range(n - 1, 0, -1):
        x[i] = (y[i] - c[i] * x[i + 1]) / mu[i]
    return x

# cubic spline interpolation
def spline(x, M, h):
    n = len(xList) - 1
    i = 0
    for j in range(1, n + 1):
        if x <= xList[j]:
            i = j
            break
    return M[i - 1] * ((xList[i] - x) ** 3 ) / (6 * h[i]) \
           + M[i] * ((x - xList[i - 1]) ** 3 ) / (6 * h[i]) \
           + (yList[i - 1] - M[i - 1] * h[i] * h[i] / 6) \
           * (xList[i] - x) / h[i] \
           + (yList[i] - M[i] * h[i] * h[i] / 6) \
           * (x - xList[i - 1]) / h[i]

# Plot cubic spline interpolation curve and original data points
def plot(M, h):
    x = np.arange(xList[0], xList[-1], 0.1)
    y = []
    for t in x:
        y_1 = spline(t, M, h)
        y.append(y_1)
    plt.plot(x, y, label="cubic spline interpolation")
    plt.plot(xList, yList, '+', label="initial points")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.legend()
    plt.show()

# Calculate the length of a cubic spline interpolation curve
def lengthCalculation(M, h):
    x = np.arange(xList[0], xList[-1], 0.01)
    s = 0
    for i in range(1, len(x)):
        s += math.sqrt((spline(x[i - 1], M, h) \
        		- spline(x[i], M, h)) ** 2 + 0.01 ** 2)
    return s

def main():
    filename = 'sea2023.csv'
    global xList, yList
    xList, yList = readDataFromCSV(filename)
    n = len(xList) - 1
    h = [0] * (n + 1)
    d = [0] * (n + 1)
    C = [0] * (n + 1)
    lam = [0] * (n + 1)
    mu = [0] * (n + 1)
    for i in range(1, n + 1):
        h[i] = xList[i] - xList[i - 1]
    for i in range(1, n):
        d[i] = 6 * ((yList[i + 1] - yList[i]) / h[i + 1] \
             - (yList[i] - yList[i - 1]) / h[i]) / (h[i] + h[i + 1])
        C[i] = 2
        lam[i] = h[i + 1] / (h[i] + h[i + 1])
        mu[i] = 1 - lam[i]
    C[n] = 2
    M = LUFactorization(mu, C, lam, d, n - 1)
    M.append(0)  # Mn=0
    print(lengthCalculation(M, h))
    plot(M, h)

if __name__ == '__main__':
    main()
