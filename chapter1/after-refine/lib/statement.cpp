#include "statement.h"

#include <iostream>
#include <sstream>
#include <iomanip>  // std::setprecision
#include <map>
#include <algorithm>

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

static int CalculateTotalVolumeCredits(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	int ret = 0;
	for (auto perf : invoice.performances) {
		ret += CalculateVolumeCredits(plays, perf);
	}

	return ret;
}

std::string GetStatement(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	int total_amount = 0;
	std::string result = "Statement for " + invoice.customer + "\n";

	for (auto perf : invoice.performances) {
		// print line for this order
		// Format: "  ${play.name}: ${usd(CalculateAmount(plays, perf))} (${perf.audience} seats)"
		std::stringstream ss;
		ss << "  ";
		ss << GetCorrelativePlay(plays, perf).name << ": " << GetUsdString(CalculateAmount(plays, perf));
		ss << " (" << perf.audience << " seats)";
		ss << "\n";
		result += ss.str();
		total_amount += CalculateAmount(plays, perf);
	}

	result += "Amount owed is " + GetUsdString(total_amount) + "\n";
	result += "You earned " + std::to_string(CalculateTotalVolumeCredits(invoice, plays)) + " credits" + "\n";
	return result;
}

} // namespace VideoRental
