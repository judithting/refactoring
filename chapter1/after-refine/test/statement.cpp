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

TEST(StatementTestSuite, TestGetHtmlStatement) {
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
		"<h1>Statement for BigCo</h1>\n"
		"<table>\n"
		"<tr><th>play</th><th>seats</th><th>cost</th></tr>\n"
		"  <tr><td>Hamlet</td><td>55</td><td>$650.00</td></tr>\n"
		"  <tr><td>As You Like It</td><td>35</td><td>$580.00</td></tr>\n"
		"  <tr><td>Othello</td><td>40</td><td>$500.00</td></tr>\n"
		"</table>\n"
		"<p>Amount owed is <em>$1,730.00</em></p>\n"
		"<p>You earned <em>47</em> credits</p>\n"
		;
	ASSERT_EQ(GetHtmlStatement(invoice, plays), expected);
}
