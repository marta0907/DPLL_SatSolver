#ifndef CLAUSE_H
#define CLAUSE_H
#include <vector>
#include "Literal.h"
using namespace std;

class Clause
{
private:
	vector<Literal> literals;
public:
	Clause() {}

	vector<Literal> GetLiterals() {
		return this->literals;
	}

	void Add(Literal l) {
		literals.push_back(l);
	}

	bool IsUnit() {
		return literals.size() == 1;
	}

	bool IsEmpty() {
		return literals.size() == 0;
	}

	void Remove(Literal l) {
		literals.erase(remove(literals.begin(), literals.end(), l),
			literals.end());
	}

	bool ContainsNegation(int id) {
		for (int i = 0; i < literals.size(); i++) {
			if (literals[i].GetId() == id
				&& literals[i].IsNegated())
				return true;
		}
		return false;
	}

	bool Contains(int id) {
		for (int i = 0; i < literals.size(); i++) {
			if (literals[i].GetId() == id
				&& !literals[i].IsNegated())
				return true;
		}
		return false;
	}

	string ToString() {
		string res;
		for (int i = 0; i < literals.size(); i++) {
			res += i == 0 ? literals[i].ToString() :
				"+ " + literals[i].ToString();
		}
		return res;
	}
};
#endif

