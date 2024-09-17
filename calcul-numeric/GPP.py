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

def GaussPivPart(A, b):
    A_ext = np.concatenate((A, b), axis = 1)
    n = b.shape[0] - 1
    for k in range(n):
        indice = k

        for p in range(k, n + 1):
            if np.abs(A_ext[p, k]) > np.abs(A_ext[indice, k]):
                indice = p
        
        if A_ext[p, k] == 0:
            print("Sistem incompatibil sau sistem compatibil nedeterminat")
            break

        if indice != k:
            A_ext[[p, k], :] = A_ext[[k, p], :]
        
        for l in range(k + 1, n + 1):
            m = A_ext[l, k] / A_ext[k, k]
            A_ext[l, :] = A_ext[l, :] - m * A_ext[k, :]
    if A_ext[n, n] == 0:
        print("Sistem incompatibil sau sistem compatibil nedeterminat")
    else:
        x_num = SubsDesc(A_ext[:, 0:n+1], A_ext[:, n + 1])
        
    return x_num


A_num = np.array([
    [0, 1, 1],
    [1, 0, 2],
    [2, 1, -1]
])

b_num = np.array([
    [2],
    [3],
    [2]
])

sol1 = GaussPivPart(A = A_num, b = b_num)

print("Solutia gasita cu metoda Gauss cu pivotare partiala este x_sol = ", sol1)