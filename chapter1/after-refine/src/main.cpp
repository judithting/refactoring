#include <iostream>
#include <map>

#include "drama.h"
#include "invoice.h"
#include "play.h"
#include "statement.h"

using namespace VideoRental;

int main(void)
{
	Invoice invoice;
	invoice.customer = "BigCo";
	invoice.performances.push_back(Performance("hamlet", 55));
	invoice.performances.push_back(Performance("as-like", 35));
	invoice.performances.push_back(Performance("othello", 40));

	std::map<std::string, Play> plays;
	plays["hamlet"] = Play("Hamlet", Drama::Type::TRAGEDY);
	plays["as-like"] = Play("As You Like It", Drama::Type::COMEDY);
	plays["othello"] = Play("Othello", Drama::Type::TRAGEDY);

	const std::string statement = GetStatement(invoice, plays);
	std::cout << statement;

	return 0;
}
