#ifndef LIBERPARVISUVTK_H
#define LIBERPARVISUVTK_H

#include <iostream>
#include <string>

#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkTetra.h>
#include <vtkVoxel.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkXMLUnstructuredGridReader.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkXMLPUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPointData.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkDoubleArray.h>

#include "liberVisuOut.h"

using namespace std;

class c_ParVTK: public c_VTK{

protected:

    vtkSmartPointer<vtkXMLPUnstructuredGridWriter> _pwriter;
    int _mpi_rank;
    int _mpi_size;

protected:

    string getParallelFileName();
    void parallelWriteFile();
    void fileCreation();

public:
    c_ParVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, int varSize, float **varMatrix, int mpi_rank, int mpi_size);
    ~c_ParVTK();
    void doAll();

};

#endif
