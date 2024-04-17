// PHYS 30762 Programming in C++
// Assignment 5- four momentum class

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include "four_momentum.h"

#define light_speed 2.99792458e8

// Beginning of four_momentum class
class four_momentum
{
private:
  double E;
  double px;
  double py;
  double pz;

public:
  // Constructors
  four_momentum() = default;  // default constructor
  four_momentum(const four_momentum &four_momentum_called); // Copy Constructor
  four_momentum(four_momentum &&four_momentum_called); // Move Constructor
  //Parameterised constructor
  four_momentum(double particle_energy, double particle_px, double particle_py, double particle_pz) :
    E{particle_energy}, 
    px{particle_pz},
    py{particle_pz},
    pz{particle_pz}
  { 
    verify_input(particle_energy);
  }
  
  // Destructor 
  ~four_momentum()
  {
    std::cout<<"Destroying Object"<<std::endl;
  }

  // Function to validate input of parameterised constructor
  void verify_input(double& particle_energy);

  // Getter functions read only (accessors) to the data members
  double get_E() const {return E;}
  double get_px() const {return px;}
  double get_py() const {return py;}
  double get_pz() const {return pz;}

  // Setter functions, to change value of data members and validate the input
  void set_E(double particle_energy);
  void set_px(double particle_px);
  void set_py(double particle_py);
  void set_pz(double particle_pz);

  // Function to print info about a particle
  void print_data() const;

  // overload +operator to sum four momentums
  std::vector<double> operator+(const four_momentum& four_momentum_called) const;
  double dotProduct(const four_momentum& four_momentum_called) const;

  // Assignment operator made to do deep copy assigning.
  four_momentum& operator=(const four_momentum &four_momentum_called);

  // Move assignment operator using function overloading
  four_momentum& operator=(four_momentum&& four_momentum_to_move);
};

#endif