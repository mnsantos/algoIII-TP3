import sys
import os
import Gnuplot

file = str(sys.argv[1])
barras = str(sys.argv[1])
file = '\''+file+'\''
plot = Gnuplot.Gnuplot()

if (barras=="b"):
	barrasFile = str(sys.argv[2])
	barrasFile = '\''+barrasFile+'\''
	output = str(sys.argv[3])
	output = '\''+output+'\''
	range = str(sys.argv[4])
	range = '\''+range+'\''
	plot("set terminal png size 1024,768")
	plot('set output '+output)
	plot('set ylabel "Miles de ciclos"')
	plot('set yrange [0:'+range+']')
	plot('set boxwidth 0.5')
	plot('set style fill solid')
	plot('plot '+barrasFile+' using 1:3:xtic(2) with boxes')
else:
	output = str(sys.argv[2])
	output = '\''+output+'\''
	plot("set terminal png size 1024,768")
	plot('set output '+output)
	plot('set ylabel "Ciclos"')
	plot('set xlabel "n"')
	if (len(sys.argv)==5):
		funcion = str(sys.argv[3])
		constante = str(sys.argv[4])
		if(funcion=="cuadratica"):
			plot('plot '+file+' with linespoints title "Algoritmo", x*x*'+constante+' title "n*n"')
		if(funcion=="nlogn"):
			plot('plot '+file+' with linespoints title "Algoritmo", x*log(x)*'+constante+' title "n*log(n)"')
		if(funcion=="n"):
			plot('plot '+file+' with linespoints title "Algoritmo", x*'+constante+' title "n"')
			
	else:
		plot('plot '+file+' with linespoints title "Algoritmo"')
