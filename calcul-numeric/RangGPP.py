import numpy as np

def RangGpp(A):
    
    h = 0
    k = 0
    rang = 0

    m = np.shape(A)[0]
    n = np.shape(A)[1]
    
    while (h < m) & (k < n):

        indice = -1
        max = 0
        for j in range(h, m):
            if np.abs(A[j,k]) > max:
                max = np.abs(A[j,k])
                indice = j
        
        if max == 0:
            k = k + 1
            continue

        if indice != h:
            A[[indice, h], :] = A[[h, indice], :]
        
        for l in range(h+1, m):
            aux = A[l,k] / A[h,k]
            A[l,:] = A[l,:] - aux * A[h,:]
        
        h = h + 1
        k = k + 1
        rang = rang + 1


    return rang


A_num = np.array([
    [4, -1, 5, 0],
    [1, 0, -3, 0],
    [0, 0, 0, 1],
    [3, -1, 8, 0]
    ])

rang = RangGpp(A=A_num)

print(rang)

