
//void c_HDF::parWriteH5(){
//
//    MPI_Comm *p_comm;
//    p_comm = &_comm;
//    MPI_Info *p_info;
//    p_info = &_info;
//    writeParallelHDF5(p_info, p_comm);
//      hid_t       plist_id;
//    writeParallelHDF5(_info, _comm, plist_id);
//
//  //Creating data array
//
//  char* extension=".h5";
//  string fileFullName=string(_fileName)+string(extension);
//  H5std_string FILE_NAME( fileFullName );
//
//
//  _plist_id = H5Pcreate(H5P_FILE_ACCESS);
//  H5Pset_fapl_mpio(_plist_id, _comm, _info);
//
//  H5File* file = new H5File( FILE_NAME, H5F_ACC_TRUNC,  H5P_DEFAULT, _plist_id );
//
////  file_id = H5Fcreate(H5FILE_NAME, H5F_ACC_TRUNC, H5P_DEFAULT, plist_id);
//  H5Pclose(_plist_id);
//
//
////
////  /*
////   * Create dataspace for the dataset in the file.
////   */
////  IntType datatype(PredType::NATIVE_INT);
////  datatype.setOrder(H5T_ORDER_LE);
////  /*
////   * Create dataset and write it into the file.
////   */
////  // Write Node Locations
////  _createDatasetH5(file, _nodeNum, 1, 1, 1, "X", _x);
////  _createDatasetH5(file, _nodeNum, 1, 1, 1, "Y", _y);
////  _createDatasetH5(file, _nodeNum, 1, 1, 1, "Z", _z);
////  // Write Cell Connectivity
////  _createDatasetH5_INT(file, _cellNum, _nodePerCell, 1, 2, "Cells", _cellConMatrix);
//////  // Write Variables
////  for (int i=0; i<_varSize; i++){
////  _createDatasetH5(file, _varLength[i], 1, 1, 1, _varName[i], _varMatrix[i]);
////  }
//  delete file;
//  cout<< "H5 parallel method exited normally."<<'\n';
//}


