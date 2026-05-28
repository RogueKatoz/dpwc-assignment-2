#pragma once

#include "AbstractPatientDatabaseLoader.h"

#include <memory>
#include <vector>

class CompositePatientLoader : public AbstractPatientDatabaseLoader {
public:
	CompositePatientLoader() = default;

	void addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader);
	void initialiseConnection() override;
	void loadPatients(std::vector<Patient*>& patientIn) override;
	void closeConnection() override;

private:
	std::vector<std::unique_ptr<AbstractPatientDatabaseLoader>> m_loaders;
};