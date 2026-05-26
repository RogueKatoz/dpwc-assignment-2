#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        std::string line;

        while (std::getline(inFile, line))
        {
            //Initialise starting fields and grab them. uid is ignored as it is generated anyway.
            std:string uid, fullName, birthday, diagnosisStr, vitalsStr;
        
            std::stringstream lineStream(line);

            std::getline(lineStream, uid, '|');
            std::getline(lineStream, fullName, '|');
            std::getline(lineStream, birthday, '|');
            std::getline(lineStream, diagnosisStr, '|');
            std::getline(lineStream, vitalsStr, '|');

            // Split full name into first and last name.
		    std::string firstName, lastName;
			std::istringstream nameStream(fullName);
            std::getline(nameStream, lastName, ',');
            std::getline(nameStream, firstName, ',');

            // Get time from birthday, taken from database loader.
            std::tm t{ };
            std::istringstream ss(birthday);
            ss >> std::get_time(&t, "%d-%m-%Y");

            // Make new patient.
			Patient* p = new Patient(firstName, lastName, t);

            
    

        }
    }

    return patients;
}
