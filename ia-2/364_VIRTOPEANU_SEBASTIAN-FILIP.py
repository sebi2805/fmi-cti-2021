# Virtopeanu Sebastian-Filip Gr. 364

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import GridSearchCV
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.linear_model import Perceptron
from sklearn.neural_network import MLPClassifier


# Deschiderea fisierului csv "fashion-mnist.csv"
# aceasta a fost calea catre fisier in cazul meu
csv_data = pd.read_csv("test_lab_cti_2024_22_mai/test_lab_cti_2024_22_mai/fashion-mnist.csv")

data = csv_data.drop(['label'],axis=1).values

labels = csv_data['label'].values

class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat', 'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']


# pentru a afisa datele am ales sa le fac subplot deoarece dura prea mult sa iterez printre toate imaginile.
# Astfel fiecare rand de 784 de elemente il refacem intr o matrice de 28 pe 28
# plt.imshow(np.reshape(data[0], (28, 28)), cmap='gray' )
# plt.show()

# subiectul 1
for idx in range(0, 10):
    for idx2, img in enumerate(data):
        if labels[idx2] == idx:
            plt.subplot(2, 5, idx+1)
            plt.imshow(np.reshape(img, (28, 28)), cmap="gray")
            plt.axis("off")
            break 
plt.show()

# versiunea fara subplot ar fi aceasta:
# in care iteram si afisam fiecare imagine cu clasa respectiva
# for idx in range(0, 10):
#     for idx2, img in enumerate(data):
#         if labels[idx2] == idx:
#             plt.imshow(np.reshape(img, (28, 28)), cmap="gray")
#             plt.axis("off")
#             # titlul acelei imaginiii
#             plt.title(class_names[idx])
#             plt.show()
#             break 

# Subiectul 2
odd_data = []
for idx, img in enumerate(data):
    if labels[idx] % 2 ==1:
        odd_data.append(img)

odd_data_shape = np.shape(odd_data)
print(odd_data_shape)

# Subiectul 3
# aici avem 2 variante putem sa impartim pe baza de index sau cu train test split  
# X_train, X_test, y_train, y_test = train_test_split(data, labels, test_size=0.1, random_state=42)
# si pasul urmator ar fi sa impart train inca o data in train si val 

# aceasta este varianta cu index         

# selectam doar datele din exemplu anterior
# astfel o sa avem 70% date de train
train_size = int(0.7 * odd_data_shape[0])
# 20% date de validare
val_size = int(0.2 * odd_data_shape[0])
# 10% date de test
test_size = int(0.1 * odd_data_shape[0])

print(train_size, val_size, test_size)

X_train = data[0:train_size]
X_val = data[train_size:train_size + val_size]
X_test = data[train_size + val_size:]

y_train = labels[0:train_size]
y_val = labels[train_size:train_size + val_size]
y_test = labels[train_size + val_size:]

print(X_train.shape, X_val.shape, X_test.shape)
print(y_train.shape, y_val.shape, y_test.shape)



# Subiectul 4 
# Pasi:
#    1. Incerc sa gasesc cei mai buni parametrii cu grid search pe datele de train si val
#    2. Aplic algoritmul cu cei parametrii pe datele concatenate de train si val si fac predict pe datele de test
# putem implement un grid search astfel incat sa gasim cea mai buna varianta
# incercam sa gasim cei mai bun parametrii pe date de train si validate si dupa aceea
# incercam sa facem predict pe datele de test cu acei parametrii
# astfel facem si cross validation

# Knn 
# knn = KNeighborsClassifier(n_neighbors=3, p=1)
# knn.fit(X_train, y_train)
# y_pred = knn.predict(X_val)
# print("Acurracy is:", accuracy_score(y_val, y_pred))
# print("Confusion matrix is:",  confusion_matrix(y_val, y_pred))

# param_grid = {
#     'n_neighbors':range(1, 5),
#     # pentru a folosi cele 2 tipuri de distante
#     'p': [1, 2]
# }

# grid_search = GridSearchCV(KNeighborsClassifier(), param_grid=param_grid, cv=5)
# grid_search.fit(X_train, y_train)
# grid_search.predict(X_val)

# print(f'Cele mai bune hiperparametri: {grid_search.best_params_}')
# print(f'Cel mai bun scor: {grid_search.best_score_:.2f}')



# Multilayer Perceptron 
# am incercat sa fac si aici un grid search doar ca a durat destul de mult
# param_grid = {
#     'hidden_layer_sizes':[(100, ), (100, 100)],
#     'activation': ['identity', 'logistic', 'tanh', 'relu'],
#     'solver': ['lbfgs', 'sgd', 'adam'],
#     # aici numarul de iteratii ar trb sa apartina dintr o gama mai larga deoarece anumiti parametrii au nevoie de mai multe iteratii
#     # altfel retea nu converge
#     'max_iter' : [300, 400, 500]
# }

# grid_search = GridSearchCV(MLPClassifier(), param_grid=param_grid, cv=5)
# grid_search.fit(X_train, y_train)
# grid_search.predict(X_val)

# print(f'Cele mai bune hiperparametri: {grid_search.best_params_}')
# print(f'Cel mai bun scor: {grid_search.best_score_:.2f}')

# acestia sunt parametrii pe care i-am gasit manual a fi cel mai performanti
# mlp = MLPClassifier(hidden_layer_sizes=(100, 100 ), activation='relu', solver='adam', max_iter=300, random_state=42)
# mlp.fit(X_train, y_train)

# y_pred = mlp.predict(X_val)

# accuracy = accuracy_score(y_val, y_pred)
# print(f'Acuratețea modelului MLPClassifier: {accuracy:.2f}')
# print("Confusion matrix is:",  confusion_matrix(y_val, y_pred))



# # Am antrenat si un perceptron normal 
# perceptron = Perceptron(max_iter=1000, eta0=0.01, random_state=42)
# perceptron.fit(X_train, y_train)

# y_pred = perceptron.predict(X_test)

# accuracy = accuracy_score(y_test, y_pred)
# print(f'Acuratețea modelului perceptron: {accuracy:.2f}')


# In urma testelor pe care le am efectua cele doua modele am gasit ce parametri functioneaza cel mai bine pe 
# datele de train si validate, astfel o sa trecem pe datele de test

# concatenez datele de train si val astfel incat si mai multe date pentru partea de test
X_train = np.concatenate([X_train, X_val])
y_train = np.concatenate([y_train, y_val])

knn = KNeighborsClassifier(n_neighbors=1, p=2)
knn.fit(X_train, y_train)
y_pred = knn.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f'Acuratețea modelului KNN: {accuracy:.4f}')
print("Confusion matrix is:",  confusion_matrix(y_test, y_pred))

###################################################################################################################

mlp = MLPClassifier(hidden_layer_sizes=(100, 100), activation='relu', solver='adam', max_iter=300, random_state=42)
mlp.fit(X_train, y_train)
y_pred = mlp.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)
print(f'Acuratețea modelului MLPClassifier: {accuracy:.4f}')
print("Confusion matrix is:",  confusion_matrix(y_test, y_pred))

# Putem observa ca KNN functioneaza mai bine decat MLP, dar diferenta este una destul de mica 

# O prima imbunatire la care ma gandesc ca as putea sa o fac asupra datelor este sa normalizez datele
# un argument ar fi ca noi stim ca anumiti pixeli vor fi mereu negrii, astfel nu are rost sa comparam marginiile imaginilor

# o alta idee ar fi sa calculam frecventa intervalelor de pixeli pe fiecare rand/coloana si sa comparam aceste feature-uri


# idee pe care vreau sa o implementez este cea cu standard scaler 
from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()

scaler.fit(X_train)

X_train_standardized = scaler.transform(X_train)
X_test_standardized = scaler.transform(X_test)

knn.fit(X_train_standardized, y_train)
y_pred = knn.predict(X_test_standardized)

accuracy = accuracy_score(y_test, y_pred)
print(f'Acuratețea modelului KNN: {accuracy:.4f}')
print("Confusion matrix is:",  confusion_matrix(y_test, y_pred))

# din ce am observat aceasta metoda nu a adus imbunatiri majore 79.71% -> 79.76%, probabil pentru ca orice pixel se afla in intervalul [0, 255]

mlp = MLPClassifier(hidden_layer_sizes=(100, 100), activation='relu', solver='adam', max_iter=300, random_state=42)
mlp.fit(X_train_standardized, y_train)
y_pred = mlp.predict(X_test_standardized)

accuracy = accuracy_score(y_test, y_pred)
print(f'Acuratețea modelului MLPClassifier: {accuracy:.4f}')
print("Confusion matrix is:",  confusion_matrix(y_test, y_pred))


# in schimb pentru MLP vedeam o optimzare de 5%, ceea ce este suficient
# imbunatiri asupra modelelor am efectutuat cu grid search si cross validation