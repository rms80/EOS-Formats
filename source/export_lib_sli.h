#ifndef EXPORT_LIB_SLI
#define EXPORT_LIB_SLI

#include "clSliFile.h"
#include "clSliceData.h"
#include "clJobSliceFile.h"

#define MAGIC_SLI ('S' | ('l'<<8) | ('i'<<16) | (254<24))

struct tyLibraryInterface
{
	int magic;
	abstractSliceFile * sliFile;
	clSliceData * sliceData;
};


//---- DLL EXPORTS ------//
#define DllExport extern "C" __declspec(dllexport)

// store handle in 64-bit int, so that 32 and 64-bit versions 
// have same interface (avoids mess in C# wrapper)
typedef unsigned long long int jf_handle;

DllExport jf_handle  sf_initLib();
DllExport void	 sf_freeLib(jf_handle sliI);
DllExport int    sf_readFromFile(jf_handle sliI, char * fileName);
DllExport int    sf_getLayerCount(jf_handle sliI, int partIndex);
DllExport int    sf_readSliceData(jf_handle sliI, int partIndex, int layerIndex);
DllExport int    sf_addRasterObject(jf_handle sliI, int * outFilledPicture, int * outLinePicture, int partIndex, clSliceData::tyMatrix matrix, int color, int width, int height);
DllExport int    sf_getPartCount(jf_handle sliI);
DllExport char * sf_getPartName(jf_handle sliI, int partIndex);
DllExport char * sf_getPartProperty(jf_handle sliI, int partIndex);
DllExport float  sf_getLayerPos(jf_handle sliI, int partIndex, int layerIndex);
DllExport int    sf_getLayerIndexByPos(jf_handle sliI, int partIndex, float layerPos);
DllExport char * sf_getLastError();
DllExport char * sf_getLastDebug();
DllExport float  sf_getMaxLayerPos(jf_handle sliI, int partIndex);
DllExport float  sf_getLayerThickness(jf_handle sliI);

#endif
