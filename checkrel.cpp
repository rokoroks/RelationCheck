#include <iostream>
#include "checkrel.h"
#include <utility>

std::vector<int> getdomain()
{
	int enter, i;
	std::vector<int> domena;
	std::vector<int>::iterator i1;

	std::cout << "Enter domain. Repeat a number to stop." << std::endl;


	for (i = 0; 1; i++) 
	{
		int gr = 0;
		std::cin >> enter;	

		for (i1 = domena.begin(); i1 != domena.end(); i1++)
		{
			if ((*i1) == enter) gr = 1;
		}
		if (gr == 1) break;

		domena.push_back(enter);

	}

	return domena;
}

std::vector<std::pair<int, int> > getrelation()
{
	
	std::pair<int, int> add;
	std::vector<std::pair<int, int> > relation;
	std::vector<std::pair<int, int> >::iterator i1;
	int i;

	std::cout << "Enter relation. Repeat a pair to stop." << std::endl;

	for (i = 0; 1; i++)
	{
		int a, b;
		int gr = 0;

		std::cin >> a >> b;
		
		for (i1 = relation.begin(); i1 != relation.end(); i1++)
		{
			if (i1->first == a && i1->second == b) gr = 1;
		}
		if (gr == 1) break;

		std::cout << "(" << a << "," << b << ")" << std::endl;
		
		relation.push_back(std::make_pair(a, b));
	}

	return relation;

}

void checkifokay(std::vector<std::pair<int, int>> relation, std::vector<int> domain)
{
	std::vector<std::pair<int, int>> wrong;
	std::vector<std::pair<int, int> >::iterator ir;
	std::vector<int>::iterator id;

	for (ir = relation.begin(); ir != relation.end(); ir++)
	{
		int a = ir->first;
		int b = ir->second;
		int gr1 = 1;
		int gr2 = 1;

		for (id = domain.begin(); id != domain.end(); id++)
		{
			if ((*id) == ir->first) gr1 = 0;
			if ((*id) == ir->second) gr2 = 0;
		}
		if (gr1 == 1 || gr2 == 1) wrong.push_back(*ir);
		
	}

	if(!wrong.empty())
	{
		std::cout << "ERROR: relation doesnt fit the domain: " << std::endl;
		for (std::vector<std::pair<int, int>>::iterator iw = wrong.begin(); iw != wrong.end(); iw++)
		{
			std::cout << "(" << iw->first << ", " << iw->second << ") " << std::endl;
		}
		
		exit(-1);
	}

}

int checkref(std::vector<std::pair<int, int>> relation, std::vector<int> domain)
{
	std::vector<std::pair<int, int> >::iterator ir;
	std::vector<int>::iterator id;

	for (id = domain.begin(); id != domain.end(); id++)
	{
		int gr = 1;

		for (ir = relation.begin(); ir != relation.end(); ir++)
		{
			if (ir->first == (*id) && ir->second == (*id)) 
			{
				gr = 0;
				break;
			}
			
		}
		if (gr == 1) return 0;
	}

	return 1;
}

int checkiref(std::vector<std::pair<int, int>> relation)
{
	std::vector<std::pair<int, int>>::iterator ir;

	for (ir = relation.begin(); ir != relation.end(); ir++)
	{
		if (ir->first == ir->second) return 0;
	}

	return 1;
}

int checksym(std::vector<std::pair<int, int>> relation)
{
	std::vector<std::pair<int, int>>::iterator ir,is;

	for (ir = relation.begin(); ir != relation.end(); ir++)
	{
		int gr = 1;

		for (is = relation.begin(); is != relation.end(); is++)
		{
			if (is->first == ir->second && is->second == ir->first) gr = 0;
		}
		if (gr == 1) return 0;
	}

	return 1;
}

int checkantisym(std::vector<std::pair<int, int>> relation)
{
	std::vector<std::pair<int, int>>::iterator ir, is;

	for (ir = relation.begin(); ir != relation.end(); ir++)
	{
	
		for (is = relation.begin(); is != relation.end(); is++)
		{
			if (is->first == ir->second && is->second == ir->first && ir->first != ir->second) return 0;
		}
		
	}

	return 1;
}

int checktranz(std::vector<std::pair<int, int>> relation)
{
	std::vector<std::pair<int, int>>::iterator ir, is, it;

	for (ir = relation.begin(); ir != relation.end(); ir++)
	{

		for (is = relation.begin(); is != relation.end(); is++)
		{
			if (ir->second == is->first)
			{
				int gr = 1;

				for (it = relation.begin(); it != relation.end(); it++)
				{
					if (it->first == ir->first && it->second == is->second) gr = 0;
				}
				if (gr == 1) return 0;
			}
		}

	}

	return 1;
}

void postresults(std::vector<std::pair<int, int>> relation, std::vector<int> domain)
{
	if (checkref(relation, domain)) std::cout << "Relation is reflexive." << std::endl;
	if (checkiref(relation)) std::cout << "Relation is irreflexive." << std::endl;
	if (checksym(relation)) std::cout << "Relation is symmetric." << std::endl;
	if (checkantisym(relation)) std::cout << "Relation is antisymmetric." << std::endl;
	if (checktranz(relation)) std::cout << "Relation is transitive." << std::endl;

}