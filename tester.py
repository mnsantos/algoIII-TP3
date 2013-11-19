import sys
import os
import glob

algoritmo = str(sys.argv[1]) #algoritmo
prueba = str(sys.argv[2]) #test

if (algoritmo=="local"):
	algoritmo="BusquedaLocal/src"
	ejecutable="blocal"
if(algoritmo=="exacto"):
	algoritmo="exacto/src"
	ejecutable="exacto"
if(algoritmo=="tabu"):
	algoritmo="tabu/src"
	ejecutable="tabu"
if(algoritmo=="goloso"):
	algoritmo="goloso/src"
	ejecutable="goloso"
		
os.chdir(algoritmo)
os.system("make")
os.chdir("../../tests/"+prueba)
res = 1

for files in glob.glob("*.in"):
	os.chdir("../../"+algoritmo)
	os.system("./"+ejecutable+" < ../../tests/"+prueba+"/"+files+" > log.txt")
	array = open("log.txt", 'r').readline()
	array = array.split()
	frontera = int(array[0])
	files = files[:-2]+"out"
	os.chdir("../../tests/"+prueba)
	array = open(files, 'r').readline()
	array = array.split()
	test = int(array[0])
	files = files[8:10]
	if (files[1]=="."):
		files = files[0]
	if (frontera!=test):
		a = str(frontera)
		b = str(test)
		res = 0
		print "Test "+files+" NO superado!"
		print "Frontera esperada: "+b
		print "Frontera devuelta: "+a
	else:
		print "Test "+files+ "...ok"
		
os.chdir("../../"+algoritmo)
os.system("rm log.txt")
if (res==1):
	print prueba+"/ superado!"
