#ifndef planet_H
#define planet_H

#include <armadillo>
#include <iostream>

using namespace arma;

class planet {
public:

double mass, potential, kinetic, angularMom;
vec position, velocity, F1, F2;
//vec <planet> planets;

// initializers
planet();
planet(double M, double x, double y, double z, double vx, double vy, double vz);

// functions
double distance(planet otherPlanet);
vec acceleration(planet otherPlanet, double G);
double kineticEnergy();
double potentialEnergy(double G, planet otherPlanet);
double angularMomentum(planet otherPlanet);
double angularMomentum(planet otherPlanet1, planet otherPlanet2);
vec newton(double G, planet otherPlanet1, planet otherPlanet2);
//vec planet::list(double G, vec planets)
};

#endif /*planet_H*/
