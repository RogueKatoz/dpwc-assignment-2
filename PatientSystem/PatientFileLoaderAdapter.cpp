#include "PatientFileLoaderAdapter.h"

PatientFileLoaderAdapter::PatientFileLoaderAdapter(const std::string& filePath) :
	_filePath(filePath),
	_fileLoader{}
{
}

void PatientFileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
	// Take all patients from the file loader and add them to the abstract database loader vector.
	std::vector<Patient*> patients = _fileLoader.loadPatientFile(_filePath);
	for (Patient* p : patients)
	{
		patientIn.push_back(p);
	}
}
