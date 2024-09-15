import numpy as np
import matplotlib.pyplot as plt


def int_romberg(a, b, f, n):  # folosita in ex 1
    if b < a:
        raise AssertionError('Interval invalid')
    h = b - a
    Q = np.zeros(shape=(n, n)) # vom scadea in continuare cu 1 toti indicii folositi in matrice fata de cei din pseudocod, data fiind indexarea in Python
    Q[0, 0] = h * (f(a) + f(b)) / 2.
    for i in range(2, n+1): # adaugam 1 la rangeurile descrise in pseudocod deoarece ultimul element nu va fi parcurs
        Q[i-1, 0] = (h / (2. ** i)) * (f(a) + 2. * (sum([f(a + (k - 1.) * h / 2. ** (i - 1.)) for k in range(2, 2 ** (i - 1) + 1)])) + f(b))
    for i in range(2, n+1):
        for j in range(2, i+1):
            Q[i-1, j-1] = (4. ** (j - 1.) * Q[i-1, j-2] - Q[i-2, j-1]) / (4. ** (j - 1) - 1)
    I = Q[n-1, n-1]
    return I


def interp_lagrange(X, Y, z): # folosita in ex 2
    n = len(X)
    L = np.zeros(shape=n)
    for k in range(n):
        p = 1 # initializarea produsului care va fi calculat
        for j in range(n):
            if j != k:
                p *= (z - X[j]) / (X[k] - X[j])
        L[k] = p
    t = sum([L[k] * Y[k] for k in range(n)])
    return t


def f1(x): # functia care este integrata in ex 1
    return 1 / (1 + x ** 2)


def I_exact(): # pentru calculul integralei exacte in ex 1 b)
    return np.arctan(4) - np.arctan(-4)


def f2(x): # functia din ex 2
    return np.cos(2 * x)


def ex1():
    # b)
    """I = arctg(4) - arctg(-4) (din formula)"""
    print(f'1 b) Integrala exacta este {I_exact()}')
    # c)
    I_aprox = int_romberg(-4, 4, f1, 4)
    print(f'1 c) Integrala aproximata este {I_aprox}')
    # d)
    E = np.abs(I_exact() - I_aprox)
    print(f'1 d) Eroarea absoluta de aproximare este {E}\n')


def ex2():
    # b)
    X = np.linspace(0, np.pi, 15)
    Y = f2(X)
    print(f'2 b) Datele cunoscute sunt X = {X}, Y = {Y}')
    # c)
    plt.figure(1)
    plt.xlabel('X')
    plt.ylabel('f2(X)')
    plt.title('2 c) Datele cunoscute X si valoarea functiei in acestea')
    plt.grid()
    plt.axhline(0, c='black')
    plt.axvline(0, c='black')
    plt.scatter(X, Y, label='Date cunoscute')
    plt.legend()
    plt.show()
    # d)
    X2 = np.linspace(0, np.pi, 100) # discretizare unde se va realiza aproximarea
    Y2 = np.zeros(shape=100) # pentru memorarea aproximarilor in fiecare punct din X2
    for i in range(100):
        Y2[i] = interp_lagrange(X, Y, X2[i])
    # e)
    plt.figure(2)
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('2 e) Reprezentare a functiei si a aproximarii acesteia')
    plt.grid()
    plt.axhline(0, c='black')
    plt.axvline(0, c='black')
    plt.scatter(X, Y, label='Date cunoscute')
    plt.plot(X, Y, color='red', label='f2')
    plt.plot(X2, Y2, color='blue', label='f2 aproximat')
    plt.legend()
    plt.show()
    # f)
    f_X2 = f2(X2) # valorile exacte ale functiei in punctele in care a fost aproximata
    E = np.abs(Y2 - f_X2) # eroarea de interpolare
    plt.figure(3)
    plt.xlabel('X')
    plt.ylabel('E')
    plt.title('2 f) Reprezentare a erorii de interpolare')
    plt.grid()
    plt.axhline(0, c='black')
    plt.axvline(0, c='black')
    plt.plot(X2, E, color='red', label='Eroare')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    ex1()
    ex2()