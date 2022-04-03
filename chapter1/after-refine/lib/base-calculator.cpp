#include "base-calculator.h"

#include <algorithm>

namespace VideoRental {

int BaseCalculator::CalculateVolumeCredits()
{
	return std::max(this->performance.audience - 30, 0);
}

} // namespace VideoRental
