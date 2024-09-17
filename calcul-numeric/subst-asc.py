from turtle import shape
import numpy as np

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

A = [[1, 0, 0],
     [2, 5, 0],
     [3, 4, 2]]

b = [1, 3, 9]

sol = SubsAsc(A, b)

print(sol)
