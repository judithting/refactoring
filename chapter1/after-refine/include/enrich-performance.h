#ifndef __VIDEO_RENTAL_ENRICH_PERFORMANCE__
#define __VIDEO_RENTAL_ENRICH_PERFORMANCE__

#include "performance.h"
#include "play.h"

namespace VideoRental {

struct EnrichPerformance : public Performance
{
	EnrichPerformance() {};
	EnrichPerformance(Performance performance, Play play)
		: Performance(performance), play(play)
	{}

	Play play;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_ENRICH_PERFORMANCE__
