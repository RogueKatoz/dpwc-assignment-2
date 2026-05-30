#include "KepralsAlertLevelStrategy.h"

#include "Patient.h"
#include "Vitals.h"

AlertLevel KepralsAlertLevelStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const
{
	if (patient.age() < 12 && vitals.HR() > 120) return AlertLevel::Red;
	else if (patient.age() >= 12 && vitals.HR() > 100) return AlertLevel::Red;
	else return AlertLevel::Green;
}