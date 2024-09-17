import numpy as np
import matplotlib.pyplot as plt

# Parametrii pentru timp și frecvența de eșantionare
t_max = 1.0
f_sampling = 10  # 10 Hz
t_samples = np.arange(0, t_max, 1 / f_sampling)

# Frecvența semnalului original
f1 = 4  # 4 Hz

# Generăm un semnal sinusoidal
y1 = np.sin(2 * np.pi * f1 * t_samples)

# Un semnal care produce același set de valori eșantionate poate fi un cosinus defazat
y2 = np.cos(2 * np.pi * f1 * t_samples - np.pi / 2)

print("Valori eșantionate pentru semnalul original:")
print(y1)
print("Valori eșantionate pentru semnalul 'aliat':")
print(y2)

# Plot
plt.figure(figsize=(12, 6))

plt.subplot(2, 1, 1)
plt.stem(t_samples, y1, 'r', markerfmt='ro', basefmt=" ", linefmt='r')
plt.title('Semnalul original')

plt.subplot(2, 1, 2)
plt.stem(t_samples, y2, 'b', markerfmt='bo', basefmt=" ", linefmt='b')
plt.title('Semnalul aliat')

plt.tight_layout()
plt.show()
