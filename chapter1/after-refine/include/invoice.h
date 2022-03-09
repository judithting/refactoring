#ifndef __VIDEO_RENTAL_INVOICE__
#define __VIDEO_RENTAL_INVOICE__

#include <list>
#include <string>

#include "performance.h"

namespace VideoRental {

struct Invoice
{
	Invoice() {};
	Invoice(std::string customer, std::list<Performance> performances)
		: customer(customer), performances(performances)
	{}

	std::string customer;
	std::list<Performance> performances;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_INVOICE__
