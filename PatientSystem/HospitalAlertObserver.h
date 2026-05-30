#pragma once

#include "PatientAlertObserver.h"
#include "HospitalAlertSystemFacade.h"

class HospitalAlertObserver : public PatientAlertObserver {
public:
	HospitalAlertObserver() = default;
	void onPatientAlertLevelChanged(Patient* p) override;

private:
	HospitalAlertSystemFacade _hospitalAlertSystem;
};