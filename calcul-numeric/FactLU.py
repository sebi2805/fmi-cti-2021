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
        k = k - 1
    return x

def SubsAsc(A, b):

    assert np.shape(A)[0] == np.shape(A)[1], " A nu este matrice patratica!"
    n = np.shape(A)[0]

    assert np.all(A == np.tril(A)), "A nu este inferior triunghiulara"

    assert n == np.shape(b)[0], "A si b nu au acelasi numar de linii!"

    assert np.linalg.det(A) != 0, "Sistemul nu este compatibil determinat!"

    x = np.full(shape=b.shape, fill_value=np.nan)

    x[0] = b[0] / A[0, 0]
    for k in range(1,n):
        suma = 0
        for j in range(0,k):
            suma = suma + A[k,j]*x[j]
        x[k] = (b[k] - suma)/ A[k,k]
    return x

def FactLU(A):
    n = A.shape[0]
    L = np.eye(n, dtype=np.float32)
    w = np.array(range(n))

    for k in range(n-1):

        indice = -1
        max = 0
        for p in range(k, n):
            if np.abs(A[p,k]) > max:
                max = np.abs(A[p,k])
                indice = p
        
        if max == 0:
            print('A nu admite factorizare LU')
            break

        if indice != k:
            A[[indice,k], :] = A[[k, indice], :]
            w[[indice, k]] = w[[k, indice]]
            if k>0:
                L[[indice,k], :k] = L[[k,indice], :k]
        
        for l in range(k+1, n):
            L[l,k] = A[l,k]/A[k,k]
            A[l,:] = A[l,:] - L[l,k] * A[k,:]
    
    if A[n-1, n-1] == 0:
        print('A nu admite factorizare LU')
    else:
        U = A
    
    return L, U, w

A_num = np.array([
     [4., 0., 1.],
     [2., 1., 1.],
     [1., 3., 1.]
     ], dtype = np.float32)

b_num = np.array([
    [11.],
    [8.],
    [8.],
    ], dtype = np.float32)

L, U, w = FactLU(A=A_num)

b_prime = b_num[w]

y = SubsAsc(A=L, b=b_prime)

print(y)

x_sol = SubsDesc(A=U, b=y)

print(x_sol)

