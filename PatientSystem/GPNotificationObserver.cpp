#include "GPNotificationObserver.h"
#include "Patient.h"
void GPNotificationObserver::onPatientAlertLevelChanged(Patient* p)
{
	_gpNotificationSystem.sendGPNotificationForPatient(p);
}
