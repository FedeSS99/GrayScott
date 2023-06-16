#ifndef ARRAYS_H
#define ARRAYS_H
#include "Parameters.h"

struct UVArrays{
    double U[NyNx];
    double V[NyNx];
    double Up[NyNx];
    double Vp[NyNx];
};

double KERNEL[3][3] = {{0.05, 0.2, 0.05},
                       {0.2, -1.0, 0.2},
                       {0.05, 0.2, 0.05}};

#endif