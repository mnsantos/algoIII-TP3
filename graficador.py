#! usr/bin/python

from matplotlib.pyplot import *
import sys
import time
import os
import math
import matplotlib.pyplot as plt

#for plotting
x=[]
y=[]

fo = str(sys.argv[1]) #txt para graficar
destino = str(sys.argv[2]) #destino
titulo = str(sys.argv[3]) #titulo del grafico

fo = open(fo,'r')

while 1:
	line = fo.readline()
	line = line.split()
	if not line: break	
	cantNodos = float(line[0])
	x.append(cantNodos)
	ciclos = float(line[1])
	y.append(ciclos)
fo.close()

#Graficador

plt.figure(0)

fig, ax = plt.subplots()
plt.title(titulo)
plt.xlim([12,20])
plt.xlabel("cantNodos")
plt.ylabel("Miles de ciclos")
ax.plot(x,y, label="Algoritmo")
z = [0.05 * i * i * 2**i for i in x ] #funcion para graficar junto a la del algoritmo
#z = [0.001 * i * i * i * i for i in x ] #funcion para graficar junto a la del algoritmo
#ax.plot(x,z,label="n^2 * 2^n")
ax.plot(x,z,label="2^n * n^2")

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


