import numpy as np
import matplotlib.pyplot as plt


def metoda_NR(f, df, x0, epsilon):
    k = 0
    conditie = epsilon
    while conditie >= epsilon:
        k = k + 1
        
        x = x0 - (f(x0)/df(x0))

        conditie = np.abs(x - x0) / np.abs(x0)
        x0 = x
    
    x_num = x

    return x_num, k



def functie_exemplu(x):
    
    y = -x**3 - 2 * np.cos(x)  # Atribuirea in y a expresiei functiei

    return y

def d_functie_exemplu(x):

    y = -3 * x**2 + 2 * np.sin(x)
    
    return y

A = -2
B = 2
NUM_POINTS = 100
x = np.linspace(A, B, NUM_POINTS)
EPSILON = 1e-5  
x0 = -2
y = functie_exemplu(x)

# ==============================================================
# Afisare grafic
# ==============================================================
plt.figure(0)  # Initializare figura
plt.plot(x, y, label='f(x)')  # Plotarea functiei

plt.axhline(0, c='black')  # Adauga axa OX
plt.axvline(0, c='black')  # Adauga axa OY
plt.xlabel('x')  # Label pentru axa OX
plt.ylabel('f(x) = y')  # Label pentru oy
plt.title('Metoda Newton-Raphson')  # Titlul figurii
plt.grid(visible=True)  # Adauga grid
plt.legend()  # Arata legenda
plt.show()  # Arata graficul

x_num, N = metoda_NR(f = functie_exemplu, df = d_functie_exemplu, x0 = x0, epsilon=EPSILON)

print(f'Solutia ecuatiei f(x) = 0 cu metoda Newton-Raphson este x_sol = {x_num:.8f} gasita in N = {N} pasi', )