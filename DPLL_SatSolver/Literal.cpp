#include "Literal.h"

Literal::Literal() {
	id = -1;
	negated = false;
}
Literal::Literal(int idVal, bool negate) {
	id = idVal;
	negated = negate;
}
Literal Literal::Negate() {
	return Literal(id, !negated);
}

int Literal::GetId() {
	return this->id;
}

bool Literal::IsNegated() {
	return this->negated;
}

bool Literal::IsPure(std::vector<Literal> literals) {
	for (int i = 0; i < literals.size(); i++) {
		if (id == literals[i].id
			&& negated != literals[i].negated) {
			return false;
		}
	}
	return true;
}

bool Literal::Equals(Literal l) {
	return id == l.id && negated == l.negated;
}

bool Literal::operator < (Literal& l)
{
	if (id < l.id && negated == l.negated) return true;
	else return false;
}

std::string Literal::ToString() {
	return IsNegated() ? "-" + std::to_string(this->id) : std::to_string(this->id);
}

bool operator==(const Literal& l1, const Literal& l2)
{
	if (l1.id == l2.id && l1.negated == l2.negated) return true;
	else return false;
}
