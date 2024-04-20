// PHYS 30762 Programming in C++
// Assignment 5 - Charged Lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons

#ifndef CHARGEDLEPTON_H
#define CHARGEDLEPTON_H

#include<iostream>
#include "Lepton.h"

// Beginning of Charged lepton class - abstract class
class ChargedLepton: public Lepton
{
protected:
  int charge; // Charge of particle either 1 or -1
public:
  // Constructors
  ChargedLepton() = default;  // default constructor

  // Parameterised Constructor
  ChargedLepton(int particle_charge, bool isAntiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz) : 
  charge{particle_charge},
  Lepton{isAntiparticle, particle_mass, particle_name, particle_energy, particle_px, particle_py, particle_pz}
  {    
    verify_input(isAntiparticle);
  }

  // Destructor 
  virtual ~ChargedLepton(){std::cout<<"Charged Lepton is destroyed."<<std::endl;};

  //print_data fn that prints that relevent data of the object
  virtual void print_data();

  // Getter Function
  double get_charge() const {return charge;}

  // Setter Function
  // Function to set charge with logical checks
  virtual void set_charge(int particle_charge);

  // Copy Constructor
  ChargedLepton(const ChargedLepton &charged_lepton_called); 

  // Move Constructor
  ChargedLepton(ChargedLepton &&charged_lepton_called); 

  // Assignment operator made to do deep copy assigning.
  ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // Move assignment operator using function overloading
  ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif