#pragma once

#include "AlertLevelStrategy.h"

class AndromedaAlertLevelStrategy : public AlertLevelStrategy {
public:
	AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};