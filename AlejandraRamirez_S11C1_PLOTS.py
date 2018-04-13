import numpy as np
import matplotlib.pyplot as plt

I = np.genfromtxt("datos.dat", delimiter = ",", usecols = 0)
t = np.genfromtxt("datos.dat", delimiter = ",", usecols = 1)

plt.plot(t,I)
plt.savefig("SIR.pdf")

