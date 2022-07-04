all:
	g++ -o mandelbrotGen -O2 -Ofast mandelbrotGen.cpp mandelbrot.cpp axis.cpp png.cpp color.cpp
	g++ -o juliaGen -O2 -Ofast juliaGen.cpp julia.cpp mandelbrot.cpp axis.cpp png.cpp color.cpp
	g++ -o paperpicgen3 paperpicgen3.cpp
	g++ -o paperpicgen4 paperpicgen4.cpp

clear:
	rm test
	rm paperpicgen
