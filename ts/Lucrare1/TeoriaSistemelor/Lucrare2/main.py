from matplotlib import pyplot as plt
import pandas as pd



data1 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare2/Date1.csv')
data2 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare2/Date2.csv')
data3 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare2/Date3.csv')
data4 = pd.read_csv(r'C:/Users/SEBI/Desktop/TeoriaSistemelor/Lucrare2/Date4.csv')

df1 = pd.DataFrame(data1, columns=['x', 'y'])
df2 = pd.DataFrame(data2, columns=['x', 'y'])
df3 = pd.DataFrame(data3, columns=['x', 'y'])
df4 = pd.DataFrame(data4, columns=['x', 'y'])


ax = df1.plot(x="x", y="y", grid=True, ylabel="Temp Actuala [°C]" ,xlabel="Temp Dorita rel" , title="Sisteme de control al temperaturii", linewidth=1.5,  label="u")
ax2=df2.plot(ax=ax, x="x", y="y", grid=True, ylabel="Temp Actuala [°C]" ,xlabel="Temp Dorita [°C]" ,  linewidth=1.5, color='red', label="Kl=5")
ax3=df3.plot(ax=ax2, x="x", y="y", grid=True, ylabel="Temp Actuala [°C]" ,xlabel="Temp Dorita [°C]" ,  linewidth=1.5, color='orange', label="Kl=15")
fig=df4.plot(ax=ax3, x="x", y="y", grid=True, ylabel="Temp Actuala [°C]" ,xlabel="Temp Dorita [°C]" , linewidth=1.5, color='green' , label="Kl=45")
plt.show()