FNAME=report

all:
	g++ -o source/test -O2 -Ofast source/main.cpp source/mandelbrot.cpp source/axis.cpp source/png.cpp -std=c++20
	g++ -o source/paperpicgen source/paperpicgen.cpp -std=c++20

report: $(FNAME).tex reference.bib
	xelatex $(FNAME)
	bibtex $(FNAME)
	xelatex $(FNAME)
	xelatex $(FNAME)

img:
	bash imggen.sh

clean:
	rm $(FNAME).aux
	rm $(FNAME).bbl
	rm $(FNAME).blg
	rm $(FNAME).log
	rm $(FNAME).out