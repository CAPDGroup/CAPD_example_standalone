#include <iostream>
#include "capd/capdlib.h"

using namespace capd;

using Node = capd::autodiff::Node;

void vector_field_builder(Node, Node in[], int, Node out[], int, Node param[], int)
{
    Node & x = in[0];
    Node & y = in[1];

    Node & epsilon = param[0];

    out[0] = epsilon * x;
    out[1] = epsilon;
}


int main()
{
    IMap vector_field(vector_field_builder, 2, 2, 1);
    vector_field.setParameter(0, 1e-7);

    IVector arg = { 0.1, 0 };

    const int order = 20;

    IOdeSolver solver(vector_field, order);
    ICoordinateSection section(2, 1, 1.0); // coordinate section y == 1.0
    IPoincareMap poincare_map(solver, section, poincare::MinusPlus);

    interval return_time {};
    C1Rect2Set set(arg);
    IVector img = poincare_map(set, return_time);

    std::cout.precision(17);
    std::cout << img << '\n';
    std::cout << return_time << '\n';
    return 0;
}
