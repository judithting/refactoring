#include "comedy-calculator.h"

namespace VideoRental {

int ComedyCalculator::CalculateAmount()
{
	int ret = 30000;
	if (this->performance.audience > 20) {
		ret += 10000 + 500 * (this->performance.audience - 20);
	}
	ret += 300 * this->performance.audience;

	return ret;
}

int ComedyCalculator::CalculateVolumeCredits()
{
	// add extra credit for every ten comedy attendees
	return BaseCalculator::CalculateVolumeCredits() + int(this->performance.audience / 5);
}

} // namespace VideoRental
