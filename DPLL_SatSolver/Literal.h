#ifndef LIT_H
#define LIT_H
#include <string>
#include <vector>

using namespace std;
class Literal
{
private:
	int id;
	bool negated;
public:
	Literal(int idVal, bool negate = false) {
		id = idVal;
		negated = negate;
	}
	Literal Negate() {
		return Literal(this->id, !this->negated);
	}

	int GetId() {
		return this->id;
	}

	bool IsNegated() {
		return this->negated;
	}

	bool IsPure(vector<Literal> literals) {
		for (int i = 0; i < literals.size(); i++) {
			if (this->id == literals[i].id
				&& this->negated != literals[i].negated) {
				return false;
			}
		}
		return true;
	}

	string ToString() {
		return IsNegated() ? "! " + to_string(this->id): to_string(this->id);
	}
};
#endif
