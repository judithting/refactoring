#include <gtest/gtest.h>
#include <string>
#include <map>

#include "drama.h"
#include "invoice.h"
#include "play.h"
#include "statement.h"

using namespace VideoRental;

TEST(StatementTestSuite, TestGetStatement) {
	Invoice invoice;
	invoice.customer = "BigCo";
	invoice.performances.push_back(Performance("hamlet", 55));
	invoice.performances.push_back(Performance("as-like", 35));
	invoice.performances.push_back(Performance("othello", 40));

	std::map<std::string, Play> plays;
	plays["hamlet"] = Play("Hamlet", Drama::Type::TRAGEDY);
	plays["as-like"] = Play("As You Like It", Drama::Type::COMEDY);
	plays["othello"] = Play("Othello", Drama::Type::TRAGEDY);

	const std::string expected =
		"Statement for BigCo\n"
		"  Hamlet: $650.00 (55 seats)\n"
		"  As You Like It: $580.00 (35 seats)\n"
		"  Othello: $500.00 (40 seats)\n"
		"Amount owed is $1,730.00\n"
		"You earned 47 credits\n"
		;
	ASSERT_EQ(GetStatement(invoice, plays), expected);
}
