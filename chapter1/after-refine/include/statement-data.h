#ifndef __VIDEO_RENTAL_STATEMENT_DATA__
#define __VIDEO_RENTAL_STATEMENT_DATA__

#include <string>

namespace VideoRental {

struct StatementData
{
	StatementData() {};
	StatementData(std::string customer)
		: customer(customer)
	{}

	std::string customer;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_STATEMENT_DATA__
