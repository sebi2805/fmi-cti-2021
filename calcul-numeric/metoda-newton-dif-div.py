import numpy as np
import matplotlib.pyplot as plt

def MetNewtonDifDiv(X, Y, x):

    n = len(X)
    Q = np.zeros((n, n ), dtype=float)

    for i in range(0, n):
        for j in range(0, i + 1):
            if j == 0:
                Q[i,0] = Y[i]
            else:
                Q[i,j] = (Q[i,j-1] - Q[i-1,j-1]) / (X[i] - X[i - j])

    y = Q[0,0]
    
    for i in range(1, n):
        prod = 1
        for j in range(0, i):
            prod = prod * (x - X[j])
        y = y + Q[i,i] * prod

    return y


def functie(var_x):
    f = np.sin(var_x)
    return f

X_interpolare = np.linspace(-np.pi/2, np.pi/2, 4)
Y_interpolare = functie(X_interpolare)

plt.figure(0)
plt.scatter(X_interpolare, Y_interpolare, c ='red', s=50)
plt.xlabel('points')
plt.ylabel('values')
plt.grid()
plt.axhline(0, c='black')
plt.axvline(0, c='black')
plt.title('Interpolare')

x_domain = np.linspace(-np.pi/2, np.pi/2, 100)
y_aprox = np.zeros(100)
for i in range(100):
    y_aprox[i] = MetNewtonDifDiv(X_interpolare, Y_interpolare, x_domain[i])

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
