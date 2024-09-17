import numpy as np
from math import sqrt
A = np.array([[4,2,6], [2,5,5], [6,5,11]])
 
def cholesky(A):


    L=np.zeros((3,3))
    n = len(A)
    assert A.any()==A.transpose().any(), "A nu e simetrica"
    assert np.all(np.linalg.eigvals(A) > 0), "A nu e pozitiva definita"
    L[0][0]=sqrt(A[0][0])
    for i in range(1,n):
        L[i][0]=A[i][0]/L[0][0]

    for k in  range(1, n):
        sum=0
        sum2=0
        for i in range(k):
            sum=sum+L[k][i]**2

        aux=A[k][k]-sum

        L[k][k]=sqrt(aux)

        for i in range(k, n):
            sum2=0
            for j in range(k):
                sum2=sum2+L[i][j]*L[k][j]
            L[i][k]=(A[i][k]-sum2)/L[k][k]

    return L
def SubsAsc(A, b):

    assert np.shape(A)[0] == np.shape(A)[1], " A nu este matrice patratica!"
    n = np.shape(A)[0]

    assert np.all(A == np.tril(A)), "A nu este inferior triunghiulara"

    assert n == np.shape(b)[0], "A si b nu au acelasi numar de linii!"

    assert np.linalg.det(A) != 0, "Sistemul nu este compatibil determinat!"

    x = np.full(shape=b.shape, fill_value=np.nan)

    x[0] = b[0] / A[0][0]
    for k in range(1,n):
        suma = 0
        for j in range(k):
            suma = suma + A[k][j]*x[j]
        x[k] = (b[k] - suma)/ A[k][k]
    return x


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
            suma = suma + A[k][j] * x[j]
        x[k] = (b[k] - suma) / A[k][k]
        k=k-1
    return x





b = np.array([14, 9, 23])






L= cholesky(A)
print("matrice L este:\n")
print(L)

sol1 = SubsAsc(L, b)
sol2= SubsDesc(L.transpose(), sol1)

print("Solutia sistemului este:\n")
print(sol2)
