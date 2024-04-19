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
  ChargedLepton(int q, bool isAntiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz) : 
  charge{q},
  Lepton{isAntiparticle, particle_mass, particle_name, particle_energy, particle_px, particle_py, particle_pz}
  {    
    std::cout<<"Calling Parameterised Constructor for Charged Lepton"<<std::endl;
  }
  // Destructor 
  virtual ~ChargedLepton(){std::cout<<"Charged Lepton is destroyed."<<std::endl;};

  virtual void print_data() const = 0; // virtual print_data fn that prints that relevent data of the object
  virtual void verify_input(bool isAntiparticle) = 0; // virutal verify_input fn that verifys is_antiparticle and assigns that correct values to the relevent data

  // Getter Function
  double get_charge() const {return charge;}

  // ChargedLepton(const ChargedLepton &charged_lepton_called); // Copy Constructor
  // ChargedLepton(ChargedLepton &&charged_lepton_called); // Move Constructor

  // // Assignment operator made to do deep copy assigning.
  // ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // // Move assignment operator using function overloading
  // ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif