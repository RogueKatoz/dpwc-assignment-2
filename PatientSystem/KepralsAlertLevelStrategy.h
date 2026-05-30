#pragma once

#include "AlertLevelStrategy.h"

class KepralsAlertLevelStrategy : public AlertLevelStrategy {
public:
	AlertLevel calculateAlertLevel(const Patient& patient, const Vitals& vitals) const override;
};