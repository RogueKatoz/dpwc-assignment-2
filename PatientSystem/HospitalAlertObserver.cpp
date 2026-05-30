#include "HospitalAlertObserver.h"
#include "Patient.h"

void HospitalAlertObserver::onPatientAlertLevelChanged(Patient* p)
{
	_hospitalAlertSystem.sendAlertForPatient(p);
}
