#ifndef __VIDEO_RENTAL_ENRICH_PERFORMANCE__
#define __VIDEO_RENTAL_ENRICH_PERFORMANCE__

#include "performance.h"
#include "play.h"

namespace VideoRental {

struct EnrichPerformance : public Performance
{
	EnrichPerformance() {};
	EnrichPerformance(Performance performance, Play play, int amount, int volume_credits)
		: Performance(performance), play(play), amount(amount), volume_credits(volume_credits)
	{}

	Play play;
	int amount;
	int volume_credits;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_ENRICH_PERFORMANCE__
