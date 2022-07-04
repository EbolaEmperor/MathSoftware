#include "julia.h"
#include <iostream>

std::complex<double> quadric(const std::complex<double> &curPoint, const std::complex<double> &iterConst)
{
    return curPoint * curPoint + iterConst;
}

julia::julia()
{
	iterTimes = maxIterTimes = 0;
    iterFunc = quadric;
}

julia::julia(const std::complex<double> &p, const std::complex<double> &c, const int &n, 
             std::complex<double> (*iF)(const std::complex<double> &, const std::complex<double> &))
{
	curPoint = p;
	iterConst = c;
	maxIterTimes = n;
	iterTimes = 0;
    iterFunc = iF;
}

julia::julia(const double &pr, const double &pi, const double &cr, const double &ci, const int &n, 
            std::complex<double> (*iF)(const std::complex<double> &, const std::complex<double> &))
{
	curPoint = std::complex<double>(pr,pi);
	iterConst = std::complex<double>(cr,ci);
	maxIterTimes = n;
	iterTimes = 0;
    iterFunc = iF;
}

julia::~julia()
{
	iterTimes = maxIterTimes = 0;
    iterFunc = nullptr;
}

void julia::iterate()
{
	if(iterTimes >= maxIterTimes)
	{
		std::cerr << "Mandelbrot Error: Iteration times has already reach the max." << std::endl;
		return;
	}
	curPoint = iterFunc(curPoint, iterConst);
	iterTimes ++;
}
