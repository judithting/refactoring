#ifndef __VIDEO_RENTAL_STATEMENT_DATA__
#define __VIDEO_RENTAL_STATEMENT_DATA__

#include <string>
#include <list>

#include "enrich-performance.h"

namespace VideoRental {

struct StatementData
{
	StatementData() {};
	StatementData(std::string customer)
		: customer(customer)
	{}

	std::string customer;
	std::list<EnrichPerformance> enrich_performances;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_STATEMENT_DATA__
