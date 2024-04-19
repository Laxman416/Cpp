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
  ChargedLepton(const ChargedLepton &charged_lepton_called); // Copy Constructor
  ChargedLepton(ChargedLepton &&charged_lepton_called); // Move Constructor

  // Destructor 
  virtual ~ChargedLepton(){};

  virtual void print_data() const = 0; // virtual print_data fn that prints that relevent data of the object
  virtual void verify_input(bool isAntiparticle) = 0; // virutal verify_input fn that verifys is_antiparticle and assigns that correct values to the relevent data

  // Getter Function
  double get_charge() const {return charge;}

  // Assignment operator made to do deep copy assigning.
  ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // Move assignment operator using function overloading
  ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif