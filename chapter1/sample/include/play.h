#ifndef __VIDEO_RENTAL_PLAY__
#define __VIDEO_RENTAL_PLAY__

#include "drama.h"

namespace VideoRental{

struct Play
{
	Play() {};
	Play(std::string name, Drama::Type type)
		: name(name), type(type)
	{}

	std::string name;
	Drama::Type type = Drama::Type::NONE;
};

} // namespace VideoRental

#endif // __VIDEO_RENTAL_PLAY__
