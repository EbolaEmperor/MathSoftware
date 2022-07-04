#include "axis.h"
#include <iostream>

axis::axis()
{
    winWidth = 1920;
    winHeight = 1080;
    center = (Cordinate){0.0, 0.0};
    diam = 5.0;
}

axis::axis(const Cordinate &c, const double &d)
{
    winWidth = 1920;
    winHeight = 1080;
    center = c;
    diam = d;
}

axis::axis(const int &w, const int &h, const Cordinate &c, const double &d)
{
    winWidth = w;
    winHeight = h;
    center = c;
    diam = d;
}

Pix axis::cord2pix(const Cordinate &c) const
{
    Pix centerPix = (Pix){winHeight/2, winWidth/2};
    Pix result;
    int maxLength = std::max(winHeight, winWidth);
    result.x = (c.x-center.x)/diam*maxLength + centerPix.y;
    result.y = centerPix.x - (c.y-center.y)/diam*maxLength;
    return result;
}

Cordinate axis::pix2cord(const Pix &p) const
{
    Pix centerPix = (Pix){winHeight/2, winWidth/2};
    Cordinate result;
    int maxLength = std::max(winHeight, winWidth);
    result.x = (double)(p.y-centerPix.y)/maxLength*diam + center.x;
    result.y = (double)(centerPix.x-p.x)/maxLength*diam + center.y;
    return result;
}

int axis::getWinWidth() const
{
    return winWidth;
}

int axis::getWinHeight() const
{
    return winHeight;
}