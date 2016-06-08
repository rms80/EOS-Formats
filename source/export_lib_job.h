#ifndef EXPORT_LIB_JOB_H
#define EXPORT_LIB_JOB_H

#include "clJobFileInterpreter.h"

#define MAGIC_JOB ('J' | ('o'<<8) | ('B'<<16) | (255<24))

struct tyLibraryInterface
{
	int magic;
	clJobFileInterpreter * jobFile;
};


//---- DLL EXPORTS ------//
#define DllExport extern "C" __declspec(dllexport)

// store handle in 64-bit int, so that 32 and 64-bit versions 
// have same interface (avoids mess in C# wrapper)
typedef unsigned long long int jf_handle;

DllExport jf_handle jf_initLib();
DllExport void	 jf_freeLib(jf_handle jobI);
DllExport int	 jf_readFromFile(jf_handle jobI, char * fileName);
DllExport int	 jf_printXML(jf_handle jobI);
DllExport char * jf_getKeyName(jf_handle jobI, int keyIndex);
DllExport int	 jf_getFirstKeyChild(jf_handle jobI, int keyIndex);
DllExport int	 jf_getNextKeyChild(jf_handle jobI, int keyIndex);
DllExport int	 jf_getFirstProperty(jf_handle jobI, int propertyIndex);
DllExport int	 jf_getNextProperty(jf_handle jobI, int propertyIndex);
DllExport char * jf_getPropertyName(jf_handle jobI, int propertyIndex);
DllExport char * jf_getPropertyValue(jf_handle jobI, int propertyIndex);
DllExport char * jf_getPropertyComment(jf_handle jobI, int propertyIndex);


#endif
