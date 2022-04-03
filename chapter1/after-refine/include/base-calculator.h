#ifndef __VIDEO_RENTAL_BASE_CALCULATOR__
#define __VIDEO_RENTAL_BASE_CALCULATOR__

#include "icalculator.h"

namespace VideoRental {

class BaseCalculator : public ICalculator
{
	public:
		BaseCalculator(Performance performance, Play play)
			: performance(performance), play(play)
		{};
		virtual ~BaseCalculator() {};

	public:
		virtual int CalculateAmount() = 0;
		int CalculateVolumeCredits();

	protected:
		Performance performance;
		Play play;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_BASE_CALCULATOR__
