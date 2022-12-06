#ifndef FORMULA_H
#define FORMULA_H
#include "Clause.h"
#include "Literal.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Formula
{
private:
	vector<Clause> clauses;
	map<Literal, bool> assignments;
public:
	Formula(){}

	void Add(Clause c) {
		clauses.push_back(c);
	}

	bool CointainsEmptyClause() {
		for (int i = 0; i < clauses.size(); i++) {
			if (clauses[i].IsEmpty()) return true;
		}
		return false;
	}

	vector<Literal> GetAllLiterals() {
		vector<Literal> allLiterals;
		for (int i = 0; i < clauses.size(); i++) {
			auto literals = clauses[i].GetLiterals();
			for (int j = 0; j < literals.size(); j++) {
				allLiterals.push_back(literals[j]);
			}
		}
		return allLiterals;
	}

	vector<Literal> GetPureLiterals() {
		vector<Literal> pureLiterals;
		vector<Literal> allLiterals = GetAllLiterals();
		for (int i = 0; i < allLiterals.size(); i++) {
			if (!count(pureLiterals.begin(), pureLiterals.end(), allLiterals[i])
				&& allLiterals[i].IsPure(allLiterals)) {
				pureLiterals.push_back(allLiterals[i]);
			}
		}
		return allLiterals;
	}

	void Simplify() {

	}

	void PropagateUnits() {

	}

	void EliminatePureLiterals() {

	}

};
#endif

