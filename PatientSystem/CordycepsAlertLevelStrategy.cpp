#include "CordycepsAlertLevelStrategy.h"

#include "Patient.h"
#include "Vitals.h"

AlertLevel CordycepsAlertLevelStrategy::calculateAlertLevel(const Patient& patient, const Vitals& vitals) const
{
	if (vitals.RR() > 40) return AlertLevel::Red;
	else if (vitals.RR() > 30) return AlertLevel::Orange;
	else if (vitals.RR() > 20) return AlertLevel::Yellow;
	else return AlertLevel::Green;
}
