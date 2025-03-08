#include <stdlib.h>
#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
    double d = 5.0;
    double n = 250;
    char syscmd[160];

    double x = atof(argv[1]);
    double y = atof(argv[2]);

    for(int i = 0; i < 1400; i++)
    {
        sprintf(syscmd, "./test img/pic%d.png %.20lf %.20lf %.20lf %d", i, x, y, d, (int)round(n));
        if(i%50 == 0)  //将此if条件改为恒true，可以生成1400张图片，然后用Pr可以制作一个视频
        {
            printf("%s\n", syscmd);
            system(syscmd);
        }
        d *= 0.99;
        d *= 0.99;
        n *= 1.0025;
        n *= 1.0025;
    }

    return 0;
}
