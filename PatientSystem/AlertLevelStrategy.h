#pragma once

#include "PatientAlertLevels.h"

// forward declare, avoid circular dependencies
class Patient;
class Vitals;

class AlertLevelStrategy {
public:
	virtual ~AlertLevelStrategy() = default;

	// Virtual function for each strategy to implement.
	virtual AlertLevel calculateAlertLevel(const Patient & patient, const Vitals & vitals) const = 0;
};