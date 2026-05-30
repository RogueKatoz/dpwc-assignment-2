#pragma once

#include "PatientAlertObserver.h"
#include "GPNotificationSystemFacade.h"

class GPNotificationObserver : public PatientAlertObserver {
public:
	GPNotificationObserver() = default;
	void onPatientAlertLevelChanged(Patient* p) override;

private:
	GPNotificationSystemFacade _gpNotificationSystem;
};
