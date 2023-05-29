#include <stdio.h>
#include "interpolation.h"

double linearInterpolation1D(double x1, double y1, double x2, double y2, double x)
{
    // check x is between x1 and x2
    if((x > x1 && x < x2) || (x < x1 && x > x2))
    {
        return ((y2-y1)/(x2-x1))*(x-x1)+y1;
    }
    else
    {
        printf("x is not between x1 and x2!\n");
        return -1;
    }
        
}

double linearInterpolation2D(double p1[3], double p2[3], double p3[3], double p[3]) // x: p[0], y: p[1], z: p[2]
{
    // Ax + By + Cz + D = 0

    double A = p1[1]*(p2[2] - p3[2]) + p2[1]*(p3[2] - p1[2]) + p3[1]*(p1[2] - p2[2]);
    double B = p1[2]*(p2[0] - p3[0]) + p2[2]*(p3[0] - p1[0]) + p3[2]*(p1[0] - p2[0]);
    double C = p1[0]*(p2[1] - p3[1]) + p2[0]*(p3[1] - p1[1]) + p3[0]*(p1[1] - p2[1]);
    double D = -1*(p1[0]*(p2[1]*p3[2] - p3[1]*p2[2]) + p2[0]*(p3[1]*p1[2] - p1[1]*p3[2]) + p3[0]*(p1[1]*p2[2] - p2[1]*p1[2]));

    double z = (D - A*p[0] - B*p[1]) / C;

    return z;
}