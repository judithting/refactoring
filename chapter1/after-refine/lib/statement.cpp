#include "statement.h"

#include <iostream>
#include <sstream>
#include <iomanip>  // std::setprecision
#include <map>
#include <algorithm>

#include "statement-data.h"

namespace VideoRental {

static std::string GetUsdString(const float amount)
{
	std::stringstream ss;
	ss.imbue(std::locale("en_US.UTF-8"));
	ss << "$" << std::fixed << std::setprecision(2) << (amount / 100);  // $1,234.56
	return ss.str();
}

static Play GetCorrelativePlay(const std::map<std::string, Play> &plays, const Performance &performance)
{
	if (plays.find(performance.playID) == plays.end()) {
		throw std::invalid_argument("unknown playID: " + performance.playID);
	}

	return plays.find(performance.playID)->second;
}

static int CalculateAmount(const std::map<std::string, Play> &plays, const Performance &performance)
{
	int ret = 0;

	switch (GetCorrelativePlay(plays, performance).type) {
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
			throw std::invalid_argument("unknown type: " + Drama::ToString((GetCorrelativePlay(plays, performance).type)));
	}

	return ret;
}

static int CalculateVolumeCredits(const std::map<std::string, Play> &plays, const Performance &performance)
{
	int ret = 0;
	ret += std::max(performance.audience - 30, 0);
	// add extra credit for every ten comedy attendees
	if (Drama::Type::COMEDY == GetCorrelativePlay(plays, performance).type) {
		ret += int(performance.audience / 5);
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

static int CalculateTotalAmount(const StatementData &data)
{
	int ret = 0;
	for (auto enrich_perf : data.enrich_performances) {
		ret += enrich_perf.amount;
	}

	return ret;
}

static std::string GetPlainTextStatement(const StatementData &data)
{
	std::string result = "Statement for " + data.customer + "\n";

	for (auto enrich_perf : data.enrich_performances) {
		const Play &play = enrich_perf.play;
		const int amount = enrich_perf.amount;
		const Performance perf = Performance(enrich_perf);
		// print line for this order
		// Format: "  ${play.name}: ${usd(amount)} (${perf.audience} seats)"
		std::stringstream ss;
		ss << "  ";
		ss << play.name << ": " << GetUsdString(amount);
		ss << " (" << perf.audience << " seats)";
		ss << "\n";
		result += ss.str();

	}

	result += "Amount owed is " + GetUsdString(data.total_amount) + "\n";
	result += "You earned " + std::to_string(data.total_volume_credits) + " credits" + "\n";
	return result;
}

static StatementData CreateStatementData(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	StatementData data;
	data.customer = invoice.customer;
	for (auto &perf : invoice.performances) {
		const Play play = GetCorrelativePlay(plays, perf);
		const int amount = CalculateAmount(plays, perf);
		const int volume_credits = CalculateVolumeCredits(plays, perf);
		data.enrich_performances.push_back(EnrichPerformance(perf, play, amount, volume_credits));
	}
	data.total_amount = CalculateTotalAmount(data);
	data.total_volume_credits = CalculateTotalVolumeCredits(data);
	return data;
}

std::string GetStatement(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	return GetPlainTextStatement(CreateStatementData(invoice, plays));
}

} // namespace VideoRental
