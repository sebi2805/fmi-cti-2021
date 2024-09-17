import numpy as np
from math import sqrt

Q=np.identity(3)
A=np.array([[1,1,0],
            [1,0,1],
            [0,1,1]])
b=np.array([1,2,5])

def FactorizareQR(Q, A, b):
    n = len(A)



    for i in range(n-1):
        for j in range(i+1, n):
            R=np.identity(3)
            aux1=sqrt(A[i][i]**2+A[j][i]**2)
            if aux1==0:
                continue
            c=A[i][i]/aux1
            s=A[j][i]/aux1

            """
            for l in range(n):
                u=c*A[i][l]+s*A[j][l]
                v=-s*A[i][l]+c*A[j][l]
                A[i][l]=u
                A[j][l]=v
                u=c*Q[i][l]+s*Q[j][l]
                v=-s*Q[i][l]+c*Q[j][l]
                Q[i][l]=u
                Q[j][l]=v
            """
            R[i][i]=c
            R[i][j]=s
            R[j][i]=-s
            R[j][j]=c
            A= np.dot(R,A)
            Q= np.dot(R, Q)


    Q=Q.transpose()
    return A, Q

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


R, Q=FactorizareQR(Q, A, b)
R=np.around(R)

print("Matricea R este:\n", R, "\n","Matrice Q este:\n",   Q)
b= (np.dot(Q, b))
x= np.linalg.solve(R, b)
print("Solutia sistemului este: \n")
print(x)
