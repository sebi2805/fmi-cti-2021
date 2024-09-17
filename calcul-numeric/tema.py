import numpy as np
import matplotlib.pyplot as plt


def metoda_secantei(f, a, b, x0, x1, epsilon):
    k = 1
    conditie = epsilon
    while k < 4:
        k = k + 1
        
        x = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0))
        print(x)

        if (x < a or x > b):
            print('Introduceti alte valori pentru x0, x1')
            break
        
        conditie = np.abs(x - x1) / np.abs(x1)
        
        x0 = x1
        x1 = x
    
    x_num = x

    return x_num, k


def functie_exemplu(x):
    
    #y = x**3 + 37/10 * x**2 + 147/20 * x + 5439/200  # Atribuirea in y a expresiei functiei
    #y = x**3 + 21/10 * x**2 + 79/20 * x + 79/20 * 21/10  # Atribuirea in y a expresiei functiei
    

    return y


A = -22/10
B = -20/10
NUM_POINTS = 100
x = np.linspace(A, B, NUM_POINTS)
EPSILON = 1e-5  
x0 = -2121/1000
x1 = -2079/1000
y = functie_exemplu(x)

print(functie_exemplu(x0))

print(functie_exemplu(x1))


x_num, N = metoda_secantei(f = functie_exemplu, a = A, b = B, x0 = x0, x1 = x1, epsilon=EPSILON)