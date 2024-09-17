import numpy as np
import matplotlib.pyplot as plt

def Lagrange(X, Y, z):
    n = np.shape(X)[0]
    L=np.zeros(n)
    for k in range(0, n):
        L[k]=1
        for j in range(0, n):
            if j!=k:
                L[k]=L[k]*(z-X[j])/(X[k]-X[j])


    t=0
    for k in range(0, n):
        t=t + L[k] * Y[k]
    return t




X= np.linspace(0, np.pi, 21)
Y= np.cos(2*X)
#print(X)
#print(Y)


##########################
plt.figure(0)
plt.scatter(X, Y, c="r", marker="*")
plt.plot(X, Y)
plt.axhline(0, c="black")
plt.xlabel("axa ox")
plt.ylabel("axa oy")
plt.axvline(0, c="black")
plt.grid()
plt.show()
#########################
x_num=np.linspace(0, np.pi, 110)
y_num=np.zeros(110)
for i in range(110):
    y_num[i]=Lagrange(X, Y, x_num[i])
########################
plt.figure(1)
plt.plot(x_num, y_num, label="linie fututa")
plt.legend()
plt.axhline(0, c="black")
plt.xlabel("axa ox")
plt.ylabel("axa oy")
plt.axvline(0, c="black")
plt.grid()
plt.show()
#####################
valoare_fixa= np.cos(2*x_num)
error= np.abs(y_num-valoare_fixa)
plt.figure(2)
plt.plot(x_num, error)
plt.axhline(0, c="black")
plt.xlabel("axa ox")
plt.ylabel("axa oy")
plt.axvline(0, c="black")
plt.grid()
plt.show()