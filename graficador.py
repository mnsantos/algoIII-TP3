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
plt.title(titulo)
plt.xlabel("cantNodos")
plt.ylabel("Miles de ciclos")

fig, ax = plt.subplots()
ax.plot(x,y, label="Algoritmo")
z = [ i * i * 2**i for i in x ] #funcion para graficar junto a la del algoritmo
ax.plot(x,z,label="n^2 * 2^n")

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


