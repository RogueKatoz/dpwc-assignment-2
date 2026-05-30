#include "AndromedaAlertLevelStrategy.h"

#include "Patient.h"
#include "Vitals.h"

AlertLevel AndromedaAlertLevelStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const
{
	if (vitals.BP() > 140) return AlertLevel::Red;
	else if (vitals.BP() > 130) return AlertLevel::Orange;
	else if (vitals.BP() > 110) return AlertLevel::Yellow;
	else return AlertLevel::Green;
}