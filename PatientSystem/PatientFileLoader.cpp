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
            //Initialise starting fields and grab them.
            std:string uid, firstName, lastName, birthday;
            std::stringstream lineStream(line);
            char delimiter = '|';

            std::getline(lineStream, uid, delimiter);
            std::getline(lineStream, lastName, delimiter);
            std::getline(lineStream, firstName, delimiter);
            std::getline(lineStream, birthday, delimiter);

            // Get time from birthday, taken from database loader.
            std::tm t{ };
            std::istringstream ss(birthday);
            ss >> std::get_time(&t, "%d-%m-%Y");

            // Make new patient from starting fields.
			Patient* p = new Patient(firstName, lastName, t);

        }
    }

    return patients;
}
