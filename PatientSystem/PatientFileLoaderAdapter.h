#pragma once

#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

#include <string>

class PatientFileLoaderAdapter : public AbstractPatientDatabaseLoader
{
public:
	PatientFileLoaderAdapter(const std::string& filePath);

	void initialiseConnection() override;
	void loadPatients(std::vector<Patient*>& patientIn) override;
	void closeConnection() override;

protected:
	std::string _filePath;
	PatientFileLoader _fileLoader;
};

