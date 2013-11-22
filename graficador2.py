#! usr/bin/python

from matplotlib.pyplot import *
import sys
import time
import os
import math
import matplotlib.pyplot as plt

#for plotting
x=[]
x1=[]
x2=[]
x3=[]
y=[]
y1=[]
y2=[]
y3=[]

fo = str(sys.argv[1]) #txt para graficar
fo1 = str(sys.argv[2]) #txt para graficar
fo2 = str(sys.argv[3]) #txt para graficar
fo3 = str(sys.argv[4]) #txt para graficar
destino = str(sys.argv[5]) #destino
titulo = str(sys.argv[6]) #titulo del grafico

fo = open(fo,'r')
fo1 = open(fo1,'r')
fo2 = open(fo2,'r')
fo3 = open(fo3,'r')

while 1:
	line = fo.readline()
	line = line.split()
	if not line: break	
	cantNodos = float(line[0])
	x.append(cantNodos)
	ciclos = float(line[1])
	y.append(ciclos)
fo.close()

while 1:
	line = fo1.readline()
	line = line.split()
	if not line: break	
	cantNodos = float(line[0])
	x1.append(cantNodos)
	ciclos = float(line[1])
	y1.append(ciclos)
fo1.close()

while 1:
	line = fo2.readline()
	line = line.split()
	if not line: break	
	cantNodos = float(line[0])
	x2.append(cantNodos)
	ciclos = float(line[1])
	y2.append(ciclos)
fo2.close()

while 1:
	line = fo3.readline()
	line = line.split()
	if not line: break	
	cantNodos = float(line[0])
	x3.append(cantNodos)
	ciclos = float(line[1])
	y3.append(ciclos)
fo3.close()

#Graficador

plt.figure(0)

fig, ax = plt.subplots()
plt.title(titulo)
plt.xlim([20,120])
plt.xlabel("cantNodos")
plt.ylabel("Miles de ciclos")
y1 = [i * 150 for i in y1] 
y2 = [i * 0.014 for i in y2]
y3 = [i * 0.000005 for i in y3]
ax.plot(x,y, label="Exacto")
ax.plot(x1,y1, label="Goloso")
ax.plot(x2,y2, label="B.Local")
ax.plot(x3,y3, label="Tabu")
#z = [0.05 * i * i * 2**i for i in x ] #funcion para graficar junto a la del algoritmo
#z = [0.001 * i * i * i * i for i in x ] #funcion para graficar junto a la del algoritmo
#ax.plot(x,z,label="n^2 * 2^n")
#ax.plot(x,z,label="2^n * n^2")

# Now add the legend with some customizations.
legend = ax.legend(loc='upper center', shadow=True)

# The frame is matplotlib.patches.Rectangle instance surrounding the legend.
frame = legend.get_frame()
frame.set_facecolor('0.90')

# Set the fontsize
for label in legend.get_texts():
    label.set_fontsize('large')

for label in legend.get_lines():
    label.set_linewidth(1.5)  # the legend line width
    
savefig(destino)
