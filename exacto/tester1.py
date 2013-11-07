import sys
import os
import glob

os.chdir("src")
os.system("make")
os.chdir("../files/tests1")
res = 1
for files in glob.glob("*.in"):
	os.chdir("../../src")
	os.system("./exacto < ../files/tests1/"+files+" > log.txt")
	array = open("log.txt", 'r').readline()
	array = array.split()
	frontera = int(array[0])
	files = files[:-2]+"out"
	os.chdir("../files/tests1")
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
		os.system("echo Test "+files+ " NO superado!")
		os.system("echo Frontera esperada: "+b)
		os.system("echo Frontera devuelta: "+a)
	else:
		os.system("echo Test "+files+ "...ok")
		
os.chdir("../../src")
os.system("rm log.txt")
if (res==1):
	os.system("echo /tests1 superado!")
