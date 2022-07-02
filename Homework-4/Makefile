FNAME=report

report: $(FNAME).tex reference.bib
	xelatex $(FNAME)
	bibtex $(FNAME)
	xelatex $(FNAME)
	xelatex $(FNAME)

clean:
	rm $(FNAME).aux
	rm $(FNAME).bbl
	rm $(FNAME).blg
	rm $(FNAME).log
	rm $(FNAME).out