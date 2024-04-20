// PHYS 30762 Programming in C++
// Assignment 5 - neutral lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons

#ifndef NEUTRAL_LEPTON_H
#define NEUTRAL_LEPTON_H

#include<iostream>
#include "Lepton.h"

// Beginning of Neutral lepton class - abstract class
class NeutralLepton : public Lepton
{
protected:
  const int charge = 0; // Charge of neutral lepton

public:
  // Constructors
  NeutralLepton() = default;  // default constructor
  
  // Parameterised Constructor
  NeutralLepton(bool isAntiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz) : 
  Lepton{isAntiparticle, particle_mass, particle_name, particle_energy, particle_px, particle_py, particle_pz}
  {    
    std::cout<<"Calling Parameterised Constructor for Neutral Lepton"<<std::endl;
  }
  // Destructor 
  virtual ~NeutralLepton(){std::cout<<"Neutral Lepton is destroyed."<<std::endl;};

  virtual void print_data();

  // Getter Function
  double get_charge() const {return charge;}

  // Setter Fn not required as charge cannot be set on NeutralLepton

  // // Copy Constructor
  // NeutralLepton(const NeutralLepton &neutral_lepton_called); 
  // // Move Constructor
  // NeutralLepton(NeutralLepton &&neutral_lepton_called); 
  // // Assignment operator made to do deep copy assigning.
  // NeutralLepton& operator=(const NeutralLepton &neutral_lepton_called);

  // // Move assignment operator using function overloading
  // NeutralLepton& operator=(NeutralLepton&& neutral_lepton_called_to_move);
};
#endif