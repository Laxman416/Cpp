// PHYS 30762 Programming in C++
// Assignment 3 - Lepton class
// Derived Classes from Lepton Class: charged leptons and neutral leptons

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<memory>
#include "FourMomentum.h"


// Beginning of lepton class - abstract class
class Lepton
{
protected:
  bool is_antiparticle; // boolean: true if antiparticle
  double rest_mass; // in MeV
  std::string particle_name;
  std::unique_ptr<FourMomentum> four_momentum;

public:
  // Constructors
  Lepton() = default;  // default constructor
  Lepton(const Lepton &lepton_called); // Copy Constructor
  Lepton(Lepton &&lepton_called); // Move Constructor
  //Parameterised constructor - don't need as the mass is dependent on the derived class

  // Destructor 
  virtual ~Lepton()
  {std::cout<<"Particle destructor called"<<std::endl;};

  virtual void print_data() const = 0; // virtual print_data fn that prints that relevent data of the object
  virtual void verify_input(bool isAntiparticle) = 0; // virutal verify_input fn that verifys is_antiparticle and assigns that correct values to the relevent data

  // Getter Function
  double get_rest_mass() const {return rest_mass;}
  bool get_is_antiparticle() const {return is_antiparticle;}

  // Assignment operator made to do deep copy assigning.
  Lepton& operator=(const Lepton &lepton_called);

  // Move assignment operator using function overloading
  Lepton& operator=(Lepton&& lepton_called_to_move);
};
#endif