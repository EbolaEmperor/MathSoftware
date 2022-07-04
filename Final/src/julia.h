#ifndef _JULIA_H_MANDELBROT
#define _JULIA_H_

#include <complex>
#include "mandelbrot.h"

std::complex<double> quadric(const std::complex<double> &curPoint, const std::complex<double> &iterConst);

class julia : public mandelbrot
{
private:
    std::complex<double> (*iterFunc)(const std::complex<double> &, const std::complex<double> &);

public:
    julia();
    julia(const std::complex<double> &, const std::complex<double> &, const int &, 
          std::complex<double> (*iF)(const std::complex<double> &, const std::complex<double> &));
    julia(const double &, const double &, const double &, const double &, const int &, 
          std::complex<double> (*iF)(const std::complex<double> &, const std::complex<double> &));
    ~julia();
    void iterate();
};

#endif