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
plt.plot(x,y)
savefig(destino)
