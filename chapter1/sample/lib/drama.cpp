#include "drama.h"

namespace VideoRental {
namespace Drama {

std::string ToString(const Type type)
{
	switch(type) {
		case Type::NONE:      return "None";
		case Type::TRAGEDY:   return "Tragedy";
		case Type::COMEDY:    return "Comedy";
		default:              return "Unknown";
	}
}

} // namespace Drama
} // namespace VideoRental
