#include "CrankNic.hpp"

void CNSolver(int n, double alpha, int tmax){
        vec u = zeros<vec>(n+2);  // Au = r
        vec r = zeros<vec>(n+2);  // vector for current time step of Crank-Nicolson

        // Boundary conditions (u(0)/r(0) set by zeros)
        u(n+1) = 1.0;
        r(n+1) = 1.0;

        // Matrix elements of tridiagonal matrix
        double e = -alpha;
        double d = 2.0 + 2.0*alpha;

        ofstream outfile;
        outfile.open("CrankNic.txt");

        // writing initial state to file
        for(int i = 0; i < n+2; i++) outfile << u(i) << " ";
        outfile << endl;

        for(int j = 1; j < tmax; j++) {
                for(int i = 1; i < n+1; i++) {
                        r(i) = alpha*u(i-1) + (2.0 - 2.0*alpha)*u(i) + alpha*u(i+1);
                }
                r(0) = 0.0;
                r(n+1) = 1.0;

                tridiagonal(d, e, u, r, n);

                // preserving boundary conditions
                u(0) = 0.0;
                u(n+1) = 1.0;

                r = u;  // Setting right hand side of equation to u, for all i

                // writing to file
                outfile << j << " ";
                for(int i = 0; i < n+2; i++) {
                        outfile << u(i) << " ";
                }
                outfile << endl;
        }
        outfile.close();
}
