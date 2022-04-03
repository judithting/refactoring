#include "statement-data-generator.h"

#include <algorithm>
#include <memory>

#include "calculator-factory.h"

namespace VideoRental {
namespace StatementDataGenerator {

static Play GetCorrelativePlay(const std::map<std::string, Play> &plays, const Performance &performance)
{
	if (plays.find(performance.playID) == plays.end()) {
		throw std::invalid_argument("unknown playID: " + performance.playID);
	}

	return plays.find(performance.playID)->second;
}

static int CalculateTotalAmount(const StatementData &data)
{
	int ret = 0;
	for (auto enrich_perf : data.enrich_performances) {
		ret += enrich_perf.amount;
	}

	return ret;
}

static int CalculateTotalVolumeCredits(const StatementData &data)
{
	int ret = 0;
	for (auto enrich_perf : data.enrich_performances) {
		ret += enrich_perf.volume_credits;
	}

	return ret;
}

StatementData CreateStatementData(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	StatementData data;
	data.customer = invoice.customer;
	for (auto &perf : invoice.performances) {
		const Play play = GetCorrelativePlay(plays, perf);

		std::unique_ptr<ICalculator> calculator = CalculatorFactory::CreatePerformanceCalculator(perf, play);
		const int amount = calculator->CalculateAmount();
		const int volume_credits = calculator->CalculateVolumeCredits();
		data.enrich_performances.push_back(EnrichPerformance(perf, play, amount, volume_credits));
	}
	data.total_amount = CalculateTotalAmount(data);
	data.total_volume_credits = CalculateTotalVolumeCredits(data);
	return data;
}

} // namespace StatementDataGenerator
} // namespace VideoRental
