#include "statement.h"

#include <iostream>
#include <sstream>
#include <iomanip>  // std::setprecision
#include <map>
#include <algorithm>

namespace VideoRental {

static std::string GetCurrencyFormattedString(const float amount)
{
	std::stringstream ss;
	ss.imbue(std::locale("en_US.UTF-8"));
	ss << "$" << std::fixed << std::setprecision(2) << amount;  // $1,234.56
	return ss.str();
}

static int CalculateAmount(const Performance &performance, const Play &play)
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
			throw std::invalid_argument("unknown type: " + Drama::ToString((play.type)));
	}

	return ret;
}

std::string GetStatement(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	int total_amount = 0;
	int volume_credits = 0;
	std::string result = "Statement for " + invoice.customer + "\n";

	for (auto perf : invoice.performances) {
		if (plays.find(perf.playID) == plays.end()) {
			throw std::invalid_argument("unknown playID: " + perf.playID);
		}
		const Play play = plays.find(perf.playID)->second;
		const int this_amount = CalculateAmount(perf, play);

		// add volume credit
		volume_credits += std::max(perf.audience - 30, 0);
		// add extra credit for every ten comedy attendees
		if (Drama::Type::COMEDY == play.type) {
			volume_credits += int(perf.audience / 5);
		}

		// print line for this order
		// Format: "  ${play.name}: ${format(this_amount / 100)} (${perf.audience} seats)"
		std::stringstream ss;
		ss << "  ";
		ss << play.name << ": " << GetCurrencyFormattedString(this_amount / 100);
		ss << " (" << perf.audience << " seats)";
		ss << "\n";
		result += ss.str();
		total_amount += this_amount;
	}

	result += "Amount owed is " + GetCurrencyFormattedString(total_amount / 100) + "\n";
	result += "You earned " + std::to_string(volume_credits) + " credits" + "\n";
	return result;
}

} // namespace VideoRental
