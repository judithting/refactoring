#include "statement-data-generator.h"

#include <algorithm>

namespace VideoRental {
namespace StatementDataGenerator {

static Play GetCorrelativePlay(const std::map<std::string, Play> &plays, const Performance &performance)
{
	if (plays.find(performance.playID) == plays.end()) {
		throw std::invalid_argument("unknown playID: " + performance.playID);
	}

	return plays.find(performance.playID)->second;
}

static int CalculateAmount(const Play &play, const Performance &performance)
{
	int ret = 0;

	switch (play.type) {
		case Drama::Type::TRAGEDY:
			ret = 40000;
			if (performance.audience > 30) {
				ret += 1000 * (performance.audience - 30);
			}
			break;
		case Drama::Type::COMEDY:
			ret = 30000;
			if (performance.audience > 20) {
				ret += 10000 + 500 * (performance.audience - 20);
			}
			ret += 300 * performance.audience;
			break;
		default:
			throw std::invalid_argument("unknown type: " + Drama::ToString(play.type));
	}

	return ret;
}

static int CalculateVolumeCredits(const Play &play, const Performance &performance)
{
	int ret = 0;
	ret += std::max(performance.audience - 30, 0);
	// add extra credit for every ten comedy attendees
	if (Drama::Type::COMEDY == play.type) {
		ret += int(performance.audience / 5);
	}

	return ret;
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
		const int amount = CalculateAmount(play, perf);
		const int volume_credits = CalculateVolumeCredits(play, perf);
		data.enrich_performances.push_back(EnrichPerformance(perf, play, amount, volume_credits));
	}
	data.total_amount = CalculateTotalAmount(data);
	data.total_volume_credits = CalculateTotalVolumeCredits(data);
	return data;
}

} // namespace StatementDataGenerator
} // namespace VideoRental
