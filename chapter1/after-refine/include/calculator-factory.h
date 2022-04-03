#ifndef __VIDEO_RENTAL_CALCULATOR_FACTORY__
#define __VIDEO_RENTAL_CALCULATOR_FACTORY__

#include <memory>

#include "icalculator.h"
#include "performance.h"
#include "play.h"

namespace VideoRental {
namespace CalculatorFactory {

std::unique_ptr<ICalculator> CreatePerformanceCalculator(const Performance &performance, const Play &play);

} // namespace CalculatorFactory
} // namespace VideoRental

#endif // __VIDEO_RENTAL_CALCULATOR_FACTORY__
