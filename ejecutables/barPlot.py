import pylab as p
import sys
import os
import glob

prueba = str(sys.argv[1]) #tests a Probar

#executing algorithms

os.system("./exacto < "+prueba+" > exacto.out")
os.system("./goloso < "+prueba+" > goloso.out")
os.system("./blocal < "+prueba+" > blocal.out")
#os.system("./tabu < "+prueba+" > tabu.out") para tabu

#reading outputs
y=[]
ys=[]
fo=open("exacto.out",'r')
while 1:
	line = fo.readline()
	line = line.split()
	if not line: break	
	y.append(float(line[0]))
fo.close()
ys.append(y)

y=[]
fo=open("goloso.out",'r')
while 1:
	line = fo.readline()
	line = line.split()
	if not line: break	
	y.append(float(line[0]))
fo.close()
ys.append(y)

y=[]
fo=open("blocal.out",'r')
while 1:
	line = fo.readline()
	line = line.split()
	if not line: break	
	y.append(float(line[0]))
fo.close()
ys.append(y)

#y=[]
#fo=open("tabu.out",'r')
#while 1:
#	line = fo.readline()
#	line = line.split()
#	if not line: break	
#	y.append(float(line[0]))
#fo.close()
#ys.append(y)
	
e=sum(ys[0])/len(ys[0])
g=sum(ys[1])/len(ys[1])
bl=sum(ys[2])/len(ys[2])
#t=sum(ys[0])/len(ys[0])

pe=100
pg=(g/e)*100
pbl=(bl/e)*100
#pg=(t/e)*100

fig = p.figure()
ax = fig.add_subplot(1,1,1)
y = [pe, pg, pbl]#, pt]
N = len(y)
ind = range(N)
p.ylim([0,110])
ax.bar(ind, y, facecolor='#777777',
       align='center', ecolor='black')
ax.set_ylabel('Efectividad (%)')
ax.set_title('CMF para cada algoritmo',fontstyle='italic')
ax.set_xticks(ind)
group_labels = ['Exacto', 'Goloso', 'B. Local', 'Tabu']
ax.set_xticklabels(group_labels)
fig.autofmt_xdate()
p.show()
