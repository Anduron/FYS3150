import numpy as np
import matplotlib.pyplot as plt
from math import log

infile = open("r3a.txt", "r")

n = infile.readlines()
line = infile.readline()
x = np.zeros(len(n))
u = np.zeros(len(n))
error = np.zeros(len(n))

iteration = 0

for line in n:

    x[iteration] = line.split()[0]
    x[iteration] = log(x[iteration])
    u[iteration] = line.split()[1]
    error[iteration] = line.split()[2]
    error[iteration] = log(error[iteration])
    iteration += 1


plt.plot(x , error)

x2 = np.linspace(1,6,len(n))
y2 = 2*x2

plt.plot(x2,y2, "--")
plt.xlabel("$\log(n)$",size = 15); plt.ylabel("$\log(iterations)$",size=15)
plt.title("Iterations as function of matrix size n",size=15)
plt.legend(["$\log_{10}(iterations(n))$", "$y = 2\log_{10}(n)$"], prop={'size':15})
plt.show()
