#ifndef __VIDEO_RENTAL_DRAMA__
#define __VIDEO_RENTAL_DRAMA__

#include <string>

namespace VideoRental {
namespace Drama {

enum class Type
{
	NONE = 0,
	TRAGEDY = 1,
	COMEDY = 2
};

std::string ToString(const Type type);

} // namespace Drama
} // namespace VideoRental

#endif // __VIDEO_RENTAL_DRAMA__
