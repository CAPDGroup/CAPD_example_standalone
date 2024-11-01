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
    DMap vector_field(vector_field_builder, 2, 2, 1);
    vector_field.setParameter(0, 1e-7);

    DVector arg = { 0.1, 0 };

    const int order = 20;

    DOdeSolver solver(vector_field, order);
    DCoordinateSection section(2, 1, 1.0); // coordinate section y == 1.0
    DPoincareMap poincare_map(solver, section, poincare::MinusPlus);

    poincare_map.setMaxReturnTime(1e8);

    double return_time {};
    DVector img = poincare_map(arg, return_time);

    std::cout.precision(17);
    std::cout << img << '\n';
    std::cout << return_time << '\n';
    return 0;
}
