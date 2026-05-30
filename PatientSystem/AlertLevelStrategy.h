#pragma once

#include "PatientAlertLevels.h"

// forward declare, avoid circular dependencies
class Patient;
class Vitals;

class AlertLevelStrategy {
public:
	virtual ~AlertLevelStrategy() = default;

	// Needs current vitals and patient age information.
	virtual AlertLevel calculateAlertLevel(const Patient & patient, const Vitals & vitals) const = 0;
};