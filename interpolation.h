#ifndef INTERPOLATION_H
#define INTERPOLATION_H

double linearInterpolation1D(double x1, double y1, double x2, double y2, double x);

double linearInterpolation2D(double p1[3], double p2[3], double p3[3], double p[3]); // x: p[0], y: p[1], z: p[2]

#endif