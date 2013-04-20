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

//Serial

void liberVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix);

//void liberParVisuVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConMatrix, char** varName, int varSize, float **varMatrix){
//
//    c_ParVTK *ParVTK = new c_ParVTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConMatrix, varName, varSize, varMatrix);
//    ParVTK->doAll();
////    delete VTK;
//
//    cout << "Parallel VTK file is created." << '\n';
//
//}
//void liberVisuXMF(string, string, string, string, int,int,int,int, char**, char**, float**, float*, float*, float*, int**);

#endif

