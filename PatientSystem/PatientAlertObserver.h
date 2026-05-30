#pragma once

class Patient;

class PatientAlertObserver {
public:
	virtual ~PatientAlertObserver() = default;
	virtual void onPatientAlert(Patient* p) = 0;
};