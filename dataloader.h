#ifndef DATALOADER_H
#define DATALOADER_H

#include "voxelgrid.h"

#include <stdio.h>

class DataLoader
{
private:
  FILE *file;
  bool isLoaded;
  
  VoxelGrid *voxelGrid;
  
  int LoadHeaderData();
  
  int LoadSliceData(int sliceNumber);
  
public:  
  DataLoader();
  
  int LoadData(const char *filePath);
  
  int GetVoxelGridWidth() { return voxelGrid->GetWidth(); }  
  int GetVoxelGridHeight()  { return voxelGrid->GetHeight(); }  
  int GetVoxelGridDepth()  { return voxelGrid->GetDepth(); }
  
  unsigned char *GetAxialSlice() { return voxelGrid->axialData; }  
  unsigned char *GetCoronalSlice()  { return voxelGrid->coronalData; }  
  unsigned char *GetSagittalSlice()  { return voxelGrid->sagittalData; }
  
  unsigned GetAxialSliceSize() { return voxelGrid->axialDataLen; }  
  unsigned GetCoronalSliceSize()  { return voxelGrid->coronalDataLen; }  
  unsigned GetSagittalSliceSize()  { return voxelGrid->sagittalDataLen; }
  
  void UpdateAxialSlice(int sliceNum);  
  void UpdateCoronalSlice(int sliceNum);  
  void UpdateSagittalSlice(int sliceNum);
};

#endif // DATALOADER_H
