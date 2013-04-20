#ifndef LIBERPARVISUVTK_H
#define LIBERPARVISUVTK_H

#include <iostream>
#include <string>
#include <sstream>

#include <vtkXMLPUnstructuredGridWriter.h>

#include "liberVisu.h"

using namespace std;

class c_ParVTK: public c_VTK{

protected:

    vtkSmartPointer<vtkXMLPUnstructuredGridWriter> _pwriter;
    int _mpi_rank;
    int _mpi_size;

protected:

    string getIndividualFileName();
    string getParallelFileName();
    void writeIndividualFile();
    void parallelWriteFile();
    void fileCreation();

public:
    c_ParVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, int varSize, float **varMatrix, int mpi_rank, int mpi_size);
    ~c_ParVTK();
    void doAll();

};

#endif
