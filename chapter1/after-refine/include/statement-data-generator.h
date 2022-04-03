#ifndef __VIDEO_RENTAL_STATEMENT_DATA_GENERATOR__
#define __VIDEO_RENTAL_STATEMENT_DATA_GENERATOR__

#include <map>

#include "statement-data.h"
#include "invoice.h"
#include "play.h"

namespace VideoRental {
namespace StatementDataGenerator {

StatementData CreateStatementData(const Invoice &invoice, const std::map<std::string, Play> &plays);

} // namespace StatementDataGenerator
} // namespace VideoRental

#endif // __VIDEO_RENTAL_STATEMENT_DATA_GENERATOR__
