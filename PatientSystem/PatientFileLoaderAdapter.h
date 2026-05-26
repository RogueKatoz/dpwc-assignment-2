#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

#include <string>

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
	PatientFileLoaderAdapter(const std::string& file);

	void loadPatients(std::vector<Patient*>& patientIn) override;

protected:
	std::string _filePath;
	PatientFileLoader _fileLoader;
};

