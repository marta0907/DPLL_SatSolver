#ifndef CLAUSE_H
#define CLAUSE_H
#include "Literal.h"
using namespace std;

class Clause
{
private:
	vector<Literal> literals;
public:
	Clause();
	vector<Literal> GetLiterals();
	void Add(Literal l);
	bool IsUnit();
	bool IsEmpty();
	void Remove(Literal l);
	bool Contains(int id, bool negated);
	bool Equals(Clause c);
	bool friend operator == (const Clause& c1, const Clause& c2);
	bool operator < (Clause& c);
	string ToString();
};
#endif

