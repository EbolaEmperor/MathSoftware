#include "png.h"
#include "axis.h"
#include "julia.h"
#include "color.h"
#include <cmath>
#include <complex>
#include <cstring>

std::complex<double> juliaFunc(const std::complex<double> &z, const std::complex<double> &c)
{
    return z*z*z*z + z*z*z/(z-1.0) + (z*z)/(z*z*z+4.0*z*z+5.0) + c;
}

int main(int argc, char* argv[])
{
    const char defeatFname[] = "test.png";
    char *fname;
    Cordinate center = (Cordinate){0.0, 0.0}, juliaCon = (Cordinate){0.0, 0.0};
    double diam = 5.0;
    int N = 100;
    std::complex<double> (*func)(const std::complex<double> &z, const std::complex<double> &c) = quadric;

    if(argc >= 2) fname = argv[1];
    if(argc >= 4) center = (Cordinate){std::atof(argv[2]), std::atof(argv[3])};
    if(argc >= 5) diam = std::atof(argv[4]);
    if(argc >= 6) N = std::atoi(argv[5]);
    if(argc >= 8) juliaCon = (Cordinate){std::atof(argv[6]), std::atof(argv[7])};
    if(argc >= 9)
    {
        if(strcmp(argv[8],"quadric") == 0) func = quadric;
        if(strcmp(argv[8],"julia") == 0) func = juliaFunc;
    }

    axis myAxis(center, diam);  //根据中心和直径定义一个像素点坐标-轴坐标转换器
    png myPng(myAxis.getWinHeight(), myAxis.getWinWidth());  //初始化一个png

    for(int i = 0; i < myAxis.getWinHeight(); i++)
        for(int j = 0; j < myAxis.getWinWidth(); j++)
        {
            Cordinate cord = myAxis.pix2cord((Pix){i,j});  //计算像素点(i,j)对应的轴坐标
            julia jul(cord.x, cord.y, juliaCon.x, juliaCon.y, N, func);   //给定迭代常数定义一个Mandelbrot迭代器
            while(!jul.unconverged())  //进行迭代
            {
                jul.iterate();
                if(jul.reachedMaxTimes())
                    break;
            }
            if(jul.unconverged())  //对不收敛区域进行着色
                myPng.setpix(i, j, colorFunc3(jul.getIterTimes()));
            else
                myPng.setpix(i, j, BLACK);
        }
    
    myPng.output(fname);
    return 0;
}