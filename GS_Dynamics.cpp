#include "Parameters.h"
#include "Arrays.h"
#include "Index.h"

double Laplacian(double C[], int i, int j){
    int ip,jp,index;
    int x,y;
    double L = 0.0;

    for(ip=-1; ip<2; ip++){
        y = i - ip;
        GetPeriodicIndex(&y, Ny);

        for(jp=-1; jp<2; jp++){
            x = j - jp;
            GetPeriodicIndex(&x, Nx);
            index = GetIndex(x, y, Nx);

            L += KERNEL[ip+1][jp+1]*C[index];
        }
    }
    return L;
}

void AdvanceTimeStep(UVArrays *UV){
    int i,j,index;
    double uv2, LapU, LapV;

    for(i=0; i<Ny; i++){
        for(j=0; j<Nx; j++){
            index = GetIndex(j, i, Nx);

            uv2 = UV->U[index]*UV->V[index]*UV->V[index];
            LapU = r_u*Laplacian(UV->U, i, j);
            LapU = r_v*Laplacian(UV->V, i, j);

            UV->Up[index] = UV->U[index] + dt*(LapU -uv2 + f*(1.0 - UV->U[index]));
            UV->Up[index] = UV->U[index] + dt*(LapV - (f+k)*(UV->V[index]));
        }
    }
}