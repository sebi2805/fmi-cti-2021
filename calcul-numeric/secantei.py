import numpy as np
import matplotlib.pyplot as plt


def metoda_secantei(f, a, b, x0, x1, epsilon):
    k = 1
    conditie = epsilon
    while conditie >= epsilon:
        k = k + 1
        
        x = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0))

        if (x < a or x > b):
            print('Introduceti alte valori pentru x0, x1')
            break
        
        conditie = np.abs(x - x1) / np.abs(x1)
        
        x0 = x1
        x1 = x
    
    x_num = x

    return x_num, k



def functie_exemplu(x):
    
    y = -x**3 - 2 * np.cos(x)  # Atribuirea in y a expresiei functiei

    return y


A = -2
B = 2
NUM_POINTS = 100
x = np.linspace(A, B, NUM_POINTS)
EPSILON = 1e-5  
x0 = -1.5
x1 = -0.5
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
plt.title('Metoda secantei')  # Titlul figurii
plt.grid(visible=True)  # Adauga grid
plt.legend()  # Arata legenda
plt.show()  # Arata graficul

x_num, N = metoda_secantei(f = functie_exemplu, a = A, b = B, x0 = x0, x1 = x1, epsilon=EPSILON)

print(f'Solutia ecuatiei f(x) = 0 cu metoda secantei este x_sol = {x_num:.8f} in N = {N} pasi.', )