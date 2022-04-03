#include "calculator-factory.h"

#include <stdexcept>

#include "tragedy-calculator.h"
#include "comedy-calculator.h"

namespace VideoRental {
namespace CalculatorFactory {

std::unique_ptr<ICalculator> CreatePerformanceCalculator(const Performance &performance, const Play &play)
{
	switch (play.type) {
		case Drama::Type::TRAGEDY:
			return std::unique_ptr<ICalculator>(new TragedyCalculator(performance, play));
		case Drama::Type::COMEDY:
			return std::unique_ptr<ICalculator>(new ComedyCalculator(performance, play));
		default:
			throw std::invalid_argument("unknown type: " + Drama::ToString(play.type));
	}
}

} // namespace CalculatorFactory
} // namespace VideoRental
