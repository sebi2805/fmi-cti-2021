from turtle import shape
import numpy as np

def SubsDesc(A, b):

    assert np.shape(A)[0] == np.shape(A)[1], " A nu este matrice patratica!"
    n = np.shape(A)[0]

    assert np.all(A == np.triu(A)), "A nu este superior triunghiulara"

    assert n == np.shape(b)[0], "A si b nu au acelasi numar de linii!"

    assert np.linalg.det(A) != 0, "Sistemul nu este compatibil determinat!"

    x = np.full(shape=b.shape, fill_value=np.nan)

    x[n-1] = b[n-1] / A[n-1, n-1]
    k = n - 2
    while k > -1:
        suma = 0
        for j in range(k + 1, n):
            suma = suma + A[k, j] * x[j]
        x[k] = (b[k] - suma) / A[k, k]
    return x

A = [[0, 0, 0],
     [0, 0, 0],
     [0, 0, 0]]

b = [0, 0, 0]

sol = SubsDesc(A, b)

print(sol)
