
import numpy as np
import numpy as np
from scipy.interpolate import make_interp_spline
import matplotlib.pyplot as plt

# Dataset
x = np.array([386.604370,465.358978,566.757568,657.666687,753.499939,852.111145,944.846130,1041.847412,1216.347778,1220.729858,1324.333252,1406.384521,1515.590210,1594.448120,1700.090820,1817.923096,1891.000000,1991.000122,2077.956543,2246.813721,2324.333496,2333324.500000])
y = np.array([ 0.023280, 0.019340, 0.015880, 0.013685, 0.011944, 0.010562, 0.009525, 0.008639, 0.006948, 0.007373, 0.006796, 0.006399, 0.005938, 0.005645, 0.005294, 0.004951, 0.004759, 0.004520, 0.004331, 0.004006, 0.003872, 0.000004])

X_Y_Spline = make_interp_spline(x, y)

# Returns evenly spaced numbers
# over a specified interval.
X_ = np.linspace(x.min(), x.max(), 500)
Y_ = X_Y_Spline(X_)

# Plotting the Graph
plt.plot(x, y)
plt.title("pula mea grafic")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
