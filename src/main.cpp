#include <iostream>
#include "capd/capdlib.h"

using namespace capd;

int main()
{
    std::cout.precision(17);
    
    try
    {
        // Defining vector field, ODE solver and Poincare map for the Rossler system.
        IMap vf("par:a,b;var:x,y,z;fun:-(y+z),x+b*y,b+z*(x-a);");
        vf.setParameter("a", interval(57)/interval(10));
        vf.setParameter("b", interval(2)/interval(10));

        int order = 30;
        IOdeSolver solver(vf, order);
        ICoordinateSection section(3, 0); // the Poincare section is x=0, i.e. index 0 of 3
        IPoincareMap poincare_map(solver, section, poincare::MinusPlus);

        // Point on a Poincare section to be evaluated
        IVector X(2);
        X[0] = -8.3809417428298;
        X[1] = 0.029590060630665;

        interval returnTime;

        // Point is 2-dimensional. Embed it into Poincare section, i.e. add first coordinate x=0.
        // Define a tripleton representation of the X of X.
        C0HOTripletonSet s1({interval(0.),X[0],X[1]});

        // Compute iteration of Poincare map at the X (3-dim object is returned).
        IVector y = poincare_map(s1,returnTime);

        // Project it onto 2-dim Poincare section, first coordinate is ignored.
        IVector imX(2,y.begin()+1);

        // Showing results
        std::cout << "Point X: " << X << '\n';
        std::cout << "Image of X under Poincare map: " << imX << '\n';
        std::cout << "Return time: " << returnTime << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "\n\nException caught: "<< e.what() << '\n';
    }

    return 0;
}
