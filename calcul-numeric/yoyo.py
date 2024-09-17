import numpy as np
import matplotlib.pyplot as plt


def metoda_NR(f, df, x0, epsilon):
    k = 0
    conditie = epsilon
    while k < 3:
        k = k + 1
        
        x = x0 - (f(x0)/df(x0))
        print(x)
        conditie = np.abs(x - x0) / np.abs(x0)
        x0 = x
    
    x_num = x

    return x_num, k



def functie_exemplu(x):
    
    #y = -x**3 - 2 * np.cos(x)  # Atribuirea in y a expresiei functiei
    y = x**3 + 3 * x**2 + 108/20 * x + 108/20 * 30/10  # Atribuirea in y a expresiei functiei



    return y

def d_functie_exemplu(x):

    y = 3 * x**2 + 6 * x + 108/20
    
    return y

A = -31/10
B = -29/10
NUM_POINTS = 100
x = np.linspace(A, B, NUM_POINTS)
EPSILON = 1e-5  
x0 = -303/100
y = functie_exemplu(x)


x_num, N = metoda_NR(f = functie_exemplu, df = d_functie_exemplu, x0 = x0, epsilon=EPSILON)

print(f'Solutia ecuatiei f(x) = 0 cu metoda Newton-Raphson este x_sol = {x_num:.8f} gasita in N = {N} pasi', )