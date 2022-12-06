#ifndef LIT_H
#define LIT_H
#include <string>
#include <vector>
class Literal
{
private:
	int id;
	bool negated;
public:
	Literal();
	Literal(int idVal, bool negate);
	Literal Negate();
	int GetId();
	bool IsNegated();
	bool IsPure(std::vector<Literal> literals);
	bool Equals(Literal l);
	bool friend operator == (const Literal& l1,const Literal& l2);
	bool operator < (Literal& l);
	std::string ToString();
};
#endif
