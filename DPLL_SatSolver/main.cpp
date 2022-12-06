#include <iostream>
#include "Solver.h"
using namespace std;

int main()
{
    Literal l1(1, false);
    Literal l2(2, false);
    Literal l3(3, false);
    Clause c;
    c.Add(l1); 
    c.Add(l2);
    c.Add(l3);

    Clause c2;
    c2.Add(l1);
    c2.Add(l2);
    c2.Add(l3.Negate());

    Clause c3;
    c3.Add(l1);
    c3.Add(l2.Negate());
    c3.Add(l3);

    Clause c4;
    c4.Add(l1.Negate().Negate());
    Clause c5;
    c5.Add(l3.Negate());

    Formula f;
    f.Add(c);
    f.Add(c2);
    f.Add(c3);
    f.Add(c4);
    f.Add(c5);
    std::cout << f.ToString() << std::endl;
    Solver s(f);
    std::cout << s.ShowFullResult() << std::endl;
}
