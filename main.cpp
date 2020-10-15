#include <iostream>
#include <vector>
#include "checkrel.h"
#include <utility>

int main() {


	std::vector<int> domain = getdomain();
	std::vector<std::pair<int, int> > relation = getrelation();

	checkifokay(relation, domain);

	postresults(relation, domain);


	return 0;
}