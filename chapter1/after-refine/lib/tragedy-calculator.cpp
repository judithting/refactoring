#include "tragedy-calculator.h"

namespace VideoRental {

int TragedyCalculator::CalculateAmount()
{
	int ret = 40000;
	if (this->performance.audience > 30) {
		ret += 1000 * (this->performance.audience - 30);
	}
	return ret;
}

int TragedyCalculator::CalculateVolumeCredits()
{
	return BaseCalculator::CalculateVolumeCredits();
}

} // namespace VideoRental
