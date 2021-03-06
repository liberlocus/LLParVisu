/*
  liberOut.h - Scientific Visualization Library.
  Created by Liberlocus, Feb 2, 2013.
  Released into the public domain.
*/
#ifndef LIBERPARVISU_H
#define LIBERPARVISU_H

#include <iostream>
#include <string>
#include <fstream>

#include "liberVisu.h"
#include "liberParVisuVTK.h"
#include "liberParVisuXMF.h"

using namespace std;

void liberParVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix, int mpiRank, int mpiSize){

    c_ParVTK *ParVTK = new c_ParVTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix, mpiRank, mpiSize);
    ParVTK->doAll();
//    delete VTK;

    if(mpiRank == 0){
      cout << "Parallel VTK file is created." << '\n';
    }

}

#endif

