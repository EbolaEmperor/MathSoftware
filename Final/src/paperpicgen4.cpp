#include <stdlib.h>
#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
    double d = 5.0;
    double n = 250;
    char syscmd[160];

    double x = std::atof(argv[1]);
    double y = std::atof(argv[2]);

    for(int i = 0; i < 1000; i++)
    {
        sprintf(syscmd, "./mandelbrotGen img/pic%d.png %.20lf %.20lf %.20lf %d", i, x, y, d, 10000);
        if(i%50 == 0 && i>700)
        {
            printf("%s\n", syscmd);
            system(syscmd);
        }
        d *= 0.99;
        d *= 0.99;
    }

    return 0;
}
