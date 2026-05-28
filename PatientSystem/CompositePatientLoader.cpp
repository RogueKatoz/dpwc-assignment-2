#include "CompositePatientLoader.h"

void CompositePatientLoader::addLoader(std::unique_ptr<AbstractPatientDatabaseLoader> loader)
{
	m_loaders.push_back(std::move(loader));
}

void CompositePatientLoader::initialiseConnection()
{
	for (const auto& loader : m_loaders)
	{
		loader->initialiseConnection();
	}
}

void CompositePatientLoader::loadPatients(std::vector<Patient*>& patientIn)
{
	for (const auto& loader : m_loaders)
	{
		loader->loadPatients(patientIn);
	}
}

void CompositePatientLoader::closeConnection()
{
	for (const auto& loader : m_loaders)
	{
		loader->closeConnection();
	}
}
	