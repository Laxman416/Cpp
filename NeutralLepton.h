// PHYS 30762 Programming in C++
// Assignment 3 - neutral lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons

#ifndef NEUTRAL_LEPTON_H
#define NEUTRAL_LEPTON_H

#include<iostream>

// Beginning of Neutral lepton class - abstract class
class NeutralLepton
{
protected:
  const int charge = 0; // Charge of lepton

public:
  // Constructors
  NeutralLepton() = default;  // default constructor
  NeutralLepton(const NeutralLepton &neutral_lepton_called); // Copy Constructor
  NeutralLepton(NeutralLepton &&neutral_lepton_called); // Move Constructor
  //Parameterised constructor - don't need as the charge is dependent on the derived class

  // Destructor 
  virtual ~NeutralLepton();

  virtual void print_data() const = 0;

  // Getter Function
  double get_charge() const {return charge;}

  // Assignment operator made to do deep copy assigning.
  NeutralLepton& operator=(const NeutralLepton &neutral_lepton_called);

  // Move assignment operator using function overloading
  NeutralLepton& operator=(NeutralLepton&& neutral_lepton_called_to_move);
};
#endif