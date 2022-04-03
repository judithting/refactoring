#include "statement.h"

#include <iostream>
#include <sstream>
#include <iomanip>  // std::setprecision
#include <map>

#include "statement-data.h"
#include "statement-data-generator.h"

namespace VideoRental {

static std::string GetUsdString(const float amount)
{
	std::stringstream ss;
	ss.imbue(std::locale("en_US.UTF-8"));
	ss << "$" << std::fixed << std::setprecision(2) << (amount / 100);  // $1,234.56
	return ss.str();
}

static std::string GetPlainText(const StatementData &data)
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

static std::string GetHtml(const StatementData &data)
{
	std::string result = "<h1>Statement for " + data.customer + "</h1>" + "\n";
	result += "<table>\n";
	result += "<tr>"
		"<th>play</th>"
		"<th>seats</th>"
		"<th>cost</th>"
		"</tr>"
		"\n"
		;

	for (auto enrich_perf : data.enrich_performances) {
		const Play &play = enrich_perf.play;
		const int amount = enrich_perf.amount;
		const Performance perf = Performance(enrich_perf);
		// print line for this order
		// Format: "  <tr><td>${play.name}</td><td>${perf.audience}</td><td>${usd(amount)}</td></tr>"
		std::stringstream ss;
		ss << "  ";
		ss << "<tr>";
		ss << "<td>" << play.name << "</td>";
		ss << "<td>" << perf.audience << "</td>";
		ss << "<td>" << GetUsdString(amount) << "</td>";
		ss << "</tr>";
		ss << "\n";
		result += ss.str();

	}

	result += "</table>\n";
	result += "<p>Amount owed is <em>" + GetUsdString(data.total_amount) + "</em>" + "</p>\n";
	result += "<p>You earned <em>" + std::to_string(data.total_volume_credits) + "</em>" + " credits" + "</p>\n";
	return result;
}

std::string GetStatement(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	return GetPlainText(StatementDataGenerator::CreateStatementData(invoice, plays));
}

std::string GetHtmlStatement(const Invoice &invoice, const std::map<std::string, Play> &plays)
{
	return GetHtml(StatementDataGenerator::CreateStatementData(invoice, plays));
}

} // namespace VideoRental
