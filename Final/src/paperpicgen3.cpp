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

    for(int i = 0; i < 400; i++)
    {
        sprintf(syscmd, "./juliaGen img/pic%d.png 0 0 %.20lf %d %.20lf %.20lf", i, d, 10000, x, y);
        if(i%50 == 0)
        {
            printf("%s\n", syscmd);
            system(syscmd);
        }
        d *= 0.99;
        d *= 0.99;
    }

    return 0;
}
