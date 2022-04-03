#ifndef __VIDEO_RENTAL_TRAGEDY_CALCULATOR__
#define __VIDEO_RENTAL_TRAGEDY_CALCULATOR__

#include "base-calculator.h"

namespace VideoRental {

class TragedyCalculator : public BaseCalculator
{
	public:
		TragedyCalculator(Performance performance, Play play)
			: BaseCalculator(performance, play)
		{};
		~TragedyCalculator() {};

	public:
		int CalculateAmount();
		int CalculateVolumeCredits();
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_TRAGEDY_CALCULATOR__
