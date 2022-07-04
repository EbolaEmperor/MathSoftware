FNAME=report

all:
	cd src && make
	$(shell if [ ! -e bin/ ];then mkdir bin; fi)
	cp src/paperpicgen1.sh bin/
	cp src/paperpicgen2.sh bin/
	mv src/paperpicgen3 bin/
	mv src/paperpicgen4 bin/
	mv src/mandelbrotGen bin/
	mv src/juliaGen bin/

report: doc/$(FNAME).tex doc/reference.bib
	cd doc && xelatex $(FNAME)
	cd doc && bibtex $(FNAME)
	cd doc && xelatex $(FNAME)
	cd doc && xelatex $(FNAME)
	mv doc/$(FNAME).pdf .

img:
	bash imggen.sh

clean:
	$(shell if [ -e bin/ ];then rm -rf bin/; fi)
	$(shell if [ -e img/ ];then rm -rf img/; fi)
	$(shell if [ -e doc/$(FNAME).out ];then rm doc/$(FNAME).out; fi)
	rm doc/$(FNAME).aux doc/$(FNAME).bbl doc/$(FNAME).blg doc/$(FNAME).log
