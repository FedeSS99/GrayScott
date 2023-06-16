#include "Parameters.h"
#include "Arrays.h"
#include "Index.h"
#include <random>

void SetInitConditions(UVArrays *UV, int dist){
    int i,j,index;
    int Nx_2 = Nx/2;
    int Ny_2 = Ny/2;

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 0.01);

    for(i=-dist; i<dist; i++){
        for(j=-dist; j<dist; j++){
            index = GetIndex(Nx_2 + j, Ny_2 + i, Nx);

            UV->U[index] = 0.5 + distribution(generator);
            UV->V[index] = 0.25 + distribution(generator);
        }
    }
}