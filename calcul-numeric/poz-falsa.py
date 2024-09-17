import numpy as np
import matplotlib.pyplot as plt


def metoda_poz_falsa(f, a, b, epsilon):
    k = 0
    a0 = a 
    b0 = b 
    x_p = (a0 * f(b0) - b0 * f(a0)) / (f(b0) - f(a0))

    conditie = epsilon
    while conditie >= epsilon:
        k = k + 1

        if f(x_p) == 0:
            x = x_p
            break
        elif f(a0) * f(x_p) < 0:
            a = a0
            b = x_p
            x = (a * f(b) - (b * f(a))) / (f(b) - f(a))
        elif f(a0) * f(x_p) > 0:
            a = x_p
            b = b0
            x = (a * f(b) - (b * f(a))) / (f(b) - f(a))
        
        conditie = np.abs(x - x_p) / np.abs(x_p)
        x_p = x
        a0 = a 
        b0 = b 

    
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
plt.title('Metoda pozitiei false')  # Titlul figurii
plt.grid(visible=True)  # Adauga grid
plt.legend()  # Arata legenda
plt.show()  # Arata graficul

x_num, N = metoda_poz_falsa(f = functie_exemplu, a = A, b = B, epsilon=EPSILON)

print(f'Solutia ecuatiei f(x) = 0 cu metoda pozitiei false este x_sol = {x_num:.8f} in N = {N} pasi.', )