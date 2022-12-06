#ifndef SOLVER_H
#define SOLVER_H
#include "Formula.h"
class Solver
{
private:
	Formula formula;
protected:
	Formula Simplify(Formula f);
	Literal ChooseLiteral(Formula f);
	bool IsSatisfiable(Formula f);
public:
	Solver(Formula formula);
	string ShowResult();
	string ShowFullResult();
};
#endif

