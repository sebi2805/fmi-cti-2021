from matplotlib import pyplot as plt
import pandas as pd



data1 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare1/Date1.csv')
data2 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare1/Date2.csv')


df1 = pd.DataFrame(data1, columns=['x', 'y'])
df2 = pd.DataFrame(data2, columns=['x', 'y'])



df1.plot(x="x", y="y", grid=True, ylabel="Q [°C]" ,xlabel="Temp Dorita rel" , title="Sisteme de control al temperaturii", linewidth=1.5,  label="u")
plt.show()
plt.savefig("Control u")
#df2.plot(ax=ax, x="x", y="y", grid=True, ylabel="Temp Actuala [°C]" ,xlabel="Temp Dorita [°C]" ,  linewidth=1.5, color='red', label="Kl=5")
plt.show()
plt.savefig("Control Q")