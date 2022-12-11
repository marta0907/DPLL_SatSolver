#include "Clause.h"
Clause::Clause() {}

vector<Literal> Clause::GetLiterals() {
	return literals;
}

void Clause::Add(Literal l) {
	literals.push_back(l);
}

bool Clause::IsUnit() {
	return literals.size() == 1;
}

bool Clause::IsEmpty() {
	return literals.size() == 0;
}

void Clause::Remove(Literal l) {
	auto literal = std::find(std::begin(literals), std::end(literals), l);
	if (literal != std::end(literals)) literals.erase(literal);
}

bool Clause::Contains(int id, bool negated)
{
	for (int i = 0; i < literals.size(); i++) {
		if (literals[i].GetId() == id
			&& literals[i].IsNegated() == negated)
			return true;
	}
	return false;
}

bool Clause::Equals(Clause c) {
	if (literals.size()
		!= c.literals.size())
		return false;
	else {
		for (int i = 0; i < literals.size(); i++) {
			if (!literals[i].Equals(c.literals[i]))
				return false;
		}
	}
	return true;
}

bool Clause::operator<(Clause& c)
{
	return literals.size() < c.literals.size();
}

string Clause::ToString() {
	string res = "(";
	for (int i = 0; i < literals.size(); i++) {
		res += i == 0 ? literals[i].ToString() :
			" + " + literals[i].ToString();
	}
	res += ")";
	return res;
}

bool operator==(const Clause& c1, const Clause& c2)
{
	if (c1.literals.size()
		!= c2.literals.size())
		return false;
	else {
		for (int i = 0; i < c1.literals.size(); i++) {
			if (!(c1.literals[i] == c2.literals[i]))
				return false;
		}
	}
	return true;

}
