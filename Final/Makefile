FNAME=report
SNAME=slide

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
	$(shell if [ -e doc/$(FNAME).out ];then rm doc/$(FNAME).out; fi)
	rm doc/$(FNAME).aux doc/$(FNAME).bbl doc/$(FNAME).blg doc/$(FNAME).log
	mv doc/$(FNAME).pdf .

slide: doc/$(SNAME).tex doc/reference.bib
	cd doc && xelatex $(SNAME)
	cd doc && bibtex $(SNAME)
	cd doc && xelatex $(SNAME)
	cd doc && xelatex $(SNAME)
	rm doc/$(SNAME).aux doc/$(SNAME).bbl doc/$(SNAME).blg doc/$(SNAME).log doc/$(SNAME).nav doc/$(SNAME).snm doc/$(SNAME).toc
	$(shell if [ -e doc/$(SNAME).out ];then rm doc/$(SNAME).out; fi)
	mv doc/$(SNAME).pdf .

image:
	bash imggen.sh

clean:
	rm -rf bin
	rm -rf img