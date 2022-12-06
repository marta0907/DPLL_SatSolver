#ifndef FORMULA_H
#define FORMULA_H
#include "Clause.h"
#include <algorithm>
#include <map>
using namespace std;

class Formula
{
private:
	vector<Clause> clauses;
	map<int, bool> assignments;
public:
	Formula();
	void Add(Clause c);
	bool CointainsEmptyClause();
	bool IsConsistent();
	bool IsEmpty();
	vector<Literal> GetAllLiterals();
	vector<Literal> GetPureLiterals();
	void PropagateUnits();
	void EliminatePureLiterals();
	void Remove(Clause c);
	bool Equals(Formula f);
	string ToString();
	void AssignToAll();
	string ShowAssignments();
};
#endif

