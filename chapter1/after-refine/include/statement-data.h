#ifndef __VIDEO_RENTAL_STATEMENT_DATA__
#define __VIDEO_RENTAL_STATEMENT_DATA__

#include <string>
#include <list>

namespace VideoRental {

struct StatementData
{
	StatementData() {};
	StatementData(std::string customer)
		: customer(customer)
	{}

	std::string customer;
	std::list<Performance> performances;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_STATEMENT_DATA__
