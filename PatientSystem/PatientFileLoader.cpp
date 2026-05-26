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
            std:string uid, fullName, birthday, diagnosis, vitals;
        
            std::istringstream lineStream(line);

            std::getline(lineStream, uid, '|');
            std::getline(lineStream, fullName, '|');
            std::getline(lineStream, birthday, '|');
            std::getline(lineStream, diagnosis, '|');
            std::getline(lineStream, vitals, '|');

            // Split full name into first and last name.
		    std::string firstName, lastName;
			std::istringstream nameStream(fullName);
            std::getline(nameStream, lastName, ',');
            std::getline(nameStream, firstName, ',');

            // Get time from birthday, taken from database loader.
            std::tm t{ };
            std::istringstream ss(birthday);
            ss >> std::get_time(&t, "%d-%m-%Y");

            // Make new patient and add diagnosis.
			Patient* p = new Patient(firstName, lastName, t);
            p->addDiagnosis(diagnosis);

            // Vitals records don't always exist.
            if (vitals != "")
            {
                // Split vitals records by ; then split again to get individual levels.
				std::istringstream vitalsStream(vitals);
				std::string vitalsRecord;
				while (std::getline(vitalsStream, vitalsRecord, ';'))
				{
					std::istringstream vitalsRecordStream(vitalsRecord);
					std::string bt, bp, hr, rr;
					std::getline(vitalsRecordStream, bt, ',');
					std::getline(vitalsRecordStream, bp, ',');
					std::getline(vitalsRecordStream, hr, ',');
					std::getline(vitalsRecordStream, rr, ',');
					
                    //Add this record to the patient.
                    Vitals* v = new Vitals(stof(bt), stoi(bp), stoi(hr), stoi(rr));
                    p->addVitals(v);
				}
            }

            //Push back patient into vector and go to next.
            patients.push_back(p);
        }
    }

    return patients;
}
