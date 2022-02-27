#ifndef __VIDEO_RENTAL_PERFORMANCE__
#define __VIDEO_RENTAL_PERFORMANCE__

#include <string>

namespace VideoRental {

struct Performance
{
	Performance() {};
	Performance(std::string playID, int audience)
		: playID(playID), audience(audience)
	{}

	std::string playID;
	int audience = 0;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_PERFORMANCE__
