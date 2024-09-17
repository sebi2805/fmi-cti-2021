import numpy as np
import matplotlib.pyplot as plt

def MetLagrange(X, Y, x):

    n = len(X)
    L = np.zeros(n, dtype=float)

    for i in range(0, n):
        L[i] = 1
        for j in range(0,n):
            if i != j:
                L[i] = L[i] * ((x - X[j]) / (X[i] - X[j]))

    y = 0
    
    for i in range(0, n):
        y = y + Y[i] * L[i]

    return y


def functie(var_x):
    f = np.sin(var_x)
    return f

X_interpolare = np.linspace(-np.pi/2, np.pi/2, 4)
Y_interpolare = functie(X_interpolare)

plt.figure(0)
plt.scatter(X_interpolare, Y_interpolare, marker='*', c ='red', s=50)
plt.xlabel('points')
plt.ylabel('values')
plt.grid()
plt.axhline(0, c='black')
plt.axvline(0, c='black')
plt.title('Interpolare')

x_domain = np.linspace(-np.pi/2, np.pi/2, 100)
y_aprox = np.zeros(100)
for i in range(100):
    y_aprox[i] = MetLagrange(X_interpolare, Y_interpolare, x_domain[i])

""" Graficul lui f si al polinomului de interpolare """
plt.plot(x_domain, functie(x_domain), c='k', linewidth=2, label='Functie exacta')
plt.plot(x_domain, y_aprox, c='r', linewidth=1, linestyle='--', label='Aproximare directa')
plt.legend()
plt.show()

""" Graficul erorii de interpolare """
error = np.abs(y_aprox - functie(x_domain))
plt.figure(1)
plt.plot(x_domain, error, c='b', linewidth=1, linestyle='--', label='Error')
plt.xlabel('points')
plt.ylabel('values')
plt.grid()
plt.axhline(0, c='black')
plt.axvline(0, c='black')
plt.title('Eroarea de interpolare')
plt.legend()
plt.show()
