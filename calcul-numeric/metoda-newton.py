import numpy as np
import matplotlib.pyplot as plt
def SubsAsc(A, b):

    assert np.shape(A)[0] == np.shape(A)[1], " A nu este matrice patratica!"
    n = np.shape(A)[0]

    assert np.all(A == np.tril(A)), "A nu este inferior triunghiulara"



    assert np.linalg.det(A) != 0, "Sistemul nu este compatibil determinat!"

    x = np.full(shape=np.shape(b), fill_value=np.nan)

    x[0] = b[0] / A[0][0]
    for k in range(1,n):
        suma = 0
        for j in range(1,n):
            suma = suma + A[k,j]*x[j]
        x[k] = (b[k] - suma)/ A[k,k]
    return x

def MetNewton(X, Y, x):

    n = len(X)
    A = np.zeros((n, n), dtype=float)


    for i in range(0, n):
        for j in range(0, i+1):
            if j == 0:
                A[i][0] = 1
            else:
                prod = 1
                for k in range( j-1):
                    prod = prod * (X[i] - X[k])

                A[i][j] = prod
    print(Y, A)
    c = np.linalg.solve(A, Y)
    y = c[0]
    print(c)
    for i in range(1, n):
        prod = 1
        for j in range(0, i-1):
            prod = prod * (x - X[j])

        y = y +  c[i-1] * prod

    return y




X_interpolare = np.linspace(-np.pi/2, np.pi/2, 4)
Y_interpolare = np.sin(X_interpolare)

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
    y_aprox[i] = MetNewton(X_interpolare, Y_interpolare, x_domain[i])

""" Graficul lui f si al polinomului de interpolare """
plt.plot(x_domain, np.sin(x_domain), c='k', linewidth=2, label='Functie exacta')
plt.plot(x_domain, y_aprox, c='r', linewidth=1, linestyle='--', label='Aproximare directa')
plt.legend()
plt.show()

""" Graficul erorii de interpolare """
error = np.abs(y_aprox - np.sin(x_domain))
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
