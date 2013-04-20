#include "liberParVisuVTK.h"

#include <string>

c_ParVTK::c_ParVTK(string fileName, int nodeNum, float *x, float *y, float *z, int cellNum, int nodePerCell, int **cellConnectivity, char ** varName, int varSize, float **varMatrix, int mpi_rank, int mpi_size) : c_VTK(fileName, nodeNum, x, y, z, cellNum, nodePerCell, cellConnectivity, varName, varSize, varMatrix){

//  Related to MPI

     _mpi_rank = mpi_rank;
     _mpi_size = mpi_size;

}
//
c_ParVTK::~c_ParVTK(){

  
//    delete [] _x;
//    _x = NULL;
//
//    delete [] _y;
//    _y = NULL;
//
//    delete [] _z;
//    _z = NULL;

    for(int i=0; i<_cellNum; i++){
        delete []  _cellConnectivity[i];
        _cellConnectivity[i] = NULL;
    }
    delete [] _cellConnectivity;
    _cellConnectivity = NULL;

    delete [] _varName;
    _varName = NULL;

    for(int i=0; i<_varSize; i++){
        delete []  _varMatrix[i];
        _varMatrix[i] = NULL;
    }
    delete [] _varMatrix;
    _varMatrix = NULL;

}

void c_ParVTK::doAll(){

    fileCreation();

}

string c_ParVTK::getIndividualFileName(){

    string f1, f2, f3, f4, ff;

    f1 = _fileName;
    f2 = "_";
    stringstream ss;
    ss << _mpi_rank;
    f3 = ss.str();
//    f3 = to_string(_mpi_rank); // Cmake doesnt work with -std=c++11
    f4 = ".vtu";

    ff = f1 + f2 + f3 + f4;
    return ff;

}

void c_ParVTK::writeIndividualFile(){

    _writer = vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();

    string fileName = getIndividualFileName();
    _writer->SetFileName(fileName.c_str());

#if VTK_MAJOR_VERSION <= 5
  _writer->SetInput(_unstructuredGrid);
#else
  _writer->SetInputData(_unstructuredGrid);
#endif
  _writer->Write();

}

string c_ParVTK::getParallelFileName(){

    string f1, f2, ff;

    f1 = _fileName;
    f2 = ".pvtu";

    ff = f1 +f2;
    return ff;

}

void c_ParVTK::parallelWriteFile(){

  if(_mpi_rank==0){
    _pwriter = vtkSmartPointer<vtkXMLPUnstructuredGridWriter>::New();

    string fileName = getParallelFileName();
    _pwriter->SetFileName(fileName.c_str());
    _pwriter->SetNumberOfPieces(_mpi_size);
#if VTK_MAJOR_VERSION <= 5
    _pwriter->SetInput(_unstructuredGrid);
#else
    _pwriter->SetInputData(_unstructuredGrid);
#endif
    _pwriter->Write();
  }


}

void c_ParVTK::fileCreation(){

    createPoints();
    createCells();
    createCellCenterData();
    createGrid();
    writeIndividualFile();
    parallelWriteFile();

}
