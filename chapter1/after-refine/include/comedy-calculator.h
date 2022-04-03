#ifndef __VIDEO_RENTAL_COMEDY_CALCULATOR__
#define __VIDEO_RENTAL_COMEDY_CALCULATOR__

#include "base-calculator.h"

namespace VideoRental {

class ComedyCalculator : public BaseCalculator
{
	public:
		ComedyCalculator(Performance performance, Play play)
			: BaseCalculator(performance, play)
		{};
		~ComedyCalculator() {};

	public:
		int CalculateAmount();
		int CalculateVolumeCredits();
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_COMEDY_CALCULATOR__
