#ifndef __VIDEO_RENTAL_STATEMENT__
#define __VIDEO_RENTAL_STATEMENT__

#include <map>

#include "invoice.h"
#include "play.h"

namespace VideoRental {

std::string GetStatement(const Invoice &invoice, const std::map<std::string, Play> &plays);
std::string GetHtmlStatement(const Invoice &invoice, const std::map<std::string, Play> &plays);

} // namespace VideoRental

#endif // __VIDEO_RENTAL_STATEMENT__
