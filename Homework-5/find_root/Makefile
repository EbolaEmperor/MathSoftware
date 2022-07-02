all:
	$(shell if [ ! -e bin/ ];then mkdir -p bin/; fi)
	gcc -I/usr/local/include/gsl src/roots.c -o bin/roots -lgsl -lgslcblas

report:
	xelatex doc/report
	mv report.log log/report.log

clean:
	$(shell if [ -e report.aux ];then rm report.aux; fi)
	$(shell if [ -e report.out ];then rm report.out; fi)