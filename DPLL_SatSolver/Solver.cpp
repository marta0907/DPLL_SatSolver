#include "Solver.h"

Formula Solver::Simplify(Formula f) {
	Formula previous, result = f;
	do {
		previous = result;
		result.PropagateUnits();
		result.EliminatePureLiterals();
	} while (!previous.Equals(result));
	return result;
}

Literal Solver::ChooseLiteral(Formula f) {
	return f.GetAllLiterals()[0];
}

Solver::Solver(Formula f)
{
	formula = f;
}

bool Solver::IsSatisfiable(Formula f) {
	formula = Simplify(f);
	if (formula.CointainsEmptyClause()) return false;
	if (formula.IsEmpty())  return true;
	if (formula.IsConsistent()) {
		formula.AssignToAll();
		return true; 
	}
	Literal literal = ChooseLiteral(f);
	Formula f1 = formula, f2 = formula;
	Clause c1, c2;
	c1.Add(literal);
	c2.Add(literal.Negate());
	f1.Add(c1);
	f2.Add(c2);
	return IsSatisfiable(f1) || IsSatisfiable(f2);
}

string Solver::ShowResult()
{
	return IsSatisfiable(formula) ? "sat": "unsat";
}

string Solver::ShowFullResult()
{
	string res = ShowResult();
	res += '\n';
	res += formula.ShowAssignments();
	return res;
}
