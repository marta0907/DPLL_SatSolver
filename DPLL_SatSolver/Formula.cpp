#include "Formula.h"
Formula::Formula() {}

void Formula::Add(Clause c) {
	clauses.push_back(c);
}

bool Formula::CointainsEmptyClause() {
	for (int i = 0; i < clauses.size(); i++) {
		if (clauses[i].IsEmpty()) return true;
	}
	return false;
}

bool Formula::IsConsistent() {
	return GetAllLiterals().size() == GetPureLiterals().size();
}

bool Formula::IsEmpty() {
	return clauses.size() == 0;
}

vector<Literal> Formula::GetAllLiterals() {
	vector<Literal> allLiterals;
	for (int i = 0; i < clauses.size(); i++) {
		auto literals = clauses[i].GetLiterals();
		for (int j = 0; j < literals.size(); j++) {
			allLiterals.push_back(literals[j]);
		}
	}
	return allLiterals;
}

vector<Literal> Formula::GetPureLiterals() {
	vector<Literal> pureLiterals;
	vector<Literal> allLiterals = GetAllLiterals();
	for (int i = 0; i < allLiterals.size(); i++) {
		if (!count(pureLiterals.begin(), pureLiterals.end(), allLiterals[i])
			&& allLiterals[i].IsPure(allLiterals)) {
			pureLiterals.push_back(allLiterals[i]);
		}
	}
	return pureLiterals;
}


void Formula::PropagateUnits() {
	Literal literal;
	for (int i = 0; i < clauses.size(); i++) {
		if (clauses[i].IsUnit()) {
			literal = clauses[i].GetLiterals()[0];
			break;
		}
	}
	if (literal.GetId() == -1) return;
	assignments.insert({ literal.GetId(), !literal.IsNegated() });

	vector<Clause> clausesToRemove;
	for (int i = 0; i < clauses.size(); i++) {
		if (clauses[i].Contains(literal.GetId(), literal.IsNegated()))
			clausesToRemove.push_back(clauses[i]);
		if (clauses[i].Contains(literal.GetId(), !literal.IsNegated()))
			clauses[i].Remove(literal.Negate());
	}
	for (int i = 0; i < clausesToRemove.size(); i++)
		Remove(clausesToRemove[i]);
	PropagateUnits();
}

void Formula::EliminatePureLiterals() {
	vector<Literal> pureLtrs = GetPureLiterals();
	vector<Clause> clausesToRemove;
	if (pureLtrs.size() == 0) return;
	for (int i = 0; i < pureLtrs.size(); i++) {
		Literal ltr = pureLtrs[i];
		for (int j = 0; j < clauses.size(); j++) {
			Clause cls = clauses[j];
			if (cls.Contains(ltr.GetId(), ltr.IsNegated()))
				clausesToRemove.push_back(cls);
		}
		assignments.insert({ ltr.GetId(),!ltr.IsNegated() });
	}
	for (int i = 0; i < clausesToRemove.size(); i++)
		Remove(clausesToRemove[i]);
	if (clauses.size() != 0) 
		EliminatePureLiterals();
}

void Formula::Remove(Clause c) {
	auto clause = std::find(std::begin(clauses), std::end(clauses), c);
	if (clause != std::end(clauses)) clauses.erase(clause);
}

bool Formula::Equals(Formula f) {
	if (clauses.size() != f.clauses.size()) return false;
	for (int i = 0; i < clauses.size(); i++) {
		if (!(clauses[i]==f.clauses[i]))
			return false;
	}
	return true;
}

string Formula::ToString() {
	string res;
	for (int i = 0; i < clauses.size(); i++) {
		res += i == 0 ? clauses[i].ToString() :
			" * " + clauses[i].ToString();
	}
	return res;
}

void Formula::AssignToAll()
{
	vector<Literal> pureLtrs = GetPureLiterals();
	for (int i = 0; i < pureLtrs.size(); i++) {
		Literal ltr = pureLtrs[i];
		assignments.insert({ ltr.GetId(),!ltr.IsNegated() });
	}
}

string Formula::ShowAssignments()
{
	string res;
	for (std::map<int, bool>::iterator iter = assignments.begin(); iter != assignments.end(); ++iter)
	{
		int k = iter->first;
		bool v = iter->second;
		res += std::to_string(k) + ": " + std::to_string(v) + '\n';
	}
	res += "*if some variables are not displayed here, then their value does not affect the result.";
	return res;
}

