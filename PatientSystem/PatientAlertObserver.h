#pragma once

class Patient;

class PatientAlertObserver {
public:
	virtual ~PatientAlertObserver() = default;
	virtual void onPatientAlertLevelChanged(Patient* p) = 0;
};