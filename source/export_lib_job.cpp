#include "export_lib_job.h"

//---------------------------------------------------//
//-- library interface--//
//---------------------------------------------------//
jf_handle jf_initLib()
{

	tyLibraryInterface *libInt = new tyLibraryInterface;

	libInt->magic = MAGIC_JOB;
	libInt->jobFile = new clJobFileInterpreter();

	return (jf_handle)libInt;
}

//---------------------------------------------------//
void jf_freeLib(jf_handle jobI)
{
	if (jobI != NULL)
	{
		tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
		if (libInt->magic == MAGIC_JOB)
		{
			if (libInt->jobFile != NULL) delete libInt->jobFile;

			libInt->magic = 0;
			libInt->jobFile = NULL;
		}
	}
}

//---------------------------------------------------//
int jf_readFromFile(jf_handle jobI, char * fileName)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	if (libInt->jobFile->readFromFile(fileName)) return 1;
	return 0;


}

//---------------------------------------------------//
int jf_printXML(jf_handle jobI)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	if (libInt->jobFile->printXML()) return 1;
	return 0;
}


//---------------------------------------------------//
char * jf_getKeyName(jf_handle jobI, int keyIndex)
{
	if (jobI == NULL) return NULL;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return NULL;
	if (libInt->jobFile == NULL) return NULL;

	return libInt->jobFile->getKeyName(keyIndex);
}

//---------------------------------------------------//
int jf_getFirstKeyChild(jf_handle jobI, int keyIndex)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	return libInt->jobFile->getFirstChild(keyIndex);
}

//---------------------------------------------------//
int jf_getNextKeyChild(jf_handle jobI, int keyIndex)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	return libInt->jobFile->getNextChild(keyIndex);
}

//---------------------------------------------------//
int jf_getFirstProperty(jf_handle jobI, int propertyIndex)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	return libInt->jobFile->getFirstProperty(propertyIndex);
}

//---------------------------------------------------//
int jf_getNextProperty(jf_handle jobI, int propertyIndex)
{
	if (jobI == NULL) return -1;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return -2;
	if (libInt->jobFile == NULL) return -3;

	return libInt->jobFile->getNextProperty(propertyIndex);
}

//---------------------------------------------------//
char * jf_getPropertyName(jf_handle jobI, int propertyIndex)
{
	if (jobI == NULL) return NULL;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return NULL;
	if (libInt->jobFile == NULL) return NULL;

	return libInt->jobFile->getPropertyName(propertyIndex);
}

//---------------------------------------------------//
char * jf_getPropertyValue(jf_handle jobI, int propertyIndex)
{
	if (jobI == NULL) return NULL;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return NULL;
	if (libInt->jobFile == NULL) return NULL;

	return libInt->jobFile->getPropertyValue(propertyIndex);
}

//---------------------------------------------------//
char * jf_getPropertyComment(jf_handle jobI, int propertyIndex)
{
	if (jobI == NULL) return NULL;
	tyLibraryInterface * libInt = (tyLibraryInterface *) jobI;
	if (libInt->magic != MAGIC_JOB) return NULL;
	if (libInt->jobFile == NULL) return NULL;

	return libInt->jobFile->getPropertyComment(propertyIndex);
}

