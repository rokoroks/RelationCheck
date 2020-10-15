#pragma once
#include <vector>


std::vector<int> getdomain();

std::vector<std::pair<int, int> > getrelation();

void checkifokay(std::vector<std::pair<int, int> > relation, std::vector<int> domain);

int checkref(std::vector<std::pair<int, int> > relation, std::vector<int> domain);
int checkiref(std::vector<std::pair<int, int> > relation);
int checksym(std::vector<std::pair<int, int> > relation);
int checkantisym(std::vector<std::pair<int, int> > relation);
int checktranz(std::vector<std::pair<int, int> > relation);

void postresults(std::vector<std::pair<int, int> > relation, std::vector<int> domain);