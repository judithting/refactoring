#ifndef __VIDEO_RENTAL_ICALCULATOR__
#define __VIDEO_RENTAL_ICALCULATOR__

#include "play.h"
#include "performance.h"

namespace VideoRental {

class ICalculator
{
	public:
		ICalculator() {};
		virtual ~ICalculator() {};

	public:
		virtual int CalculateAmount() = 0;
		virtual int CalculateVolumeCredits() = 0;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_ICALCULATOR__
