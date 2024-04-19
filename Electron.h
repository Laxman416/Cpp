// PHYS 30762 Programming in C++
// Assignment 5 - Charged Lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef ELECTRON
#define ELECTRON

#include<iostream>
#include<string>
#include "ChargedLepton.h"
#include "FourMomentum.h"

// Beginning of Electron class - derived class
class Electron: public ChargedLepton
{
private:
public:
  // Constructors
  Electron() = default;  // Default constructor
  // Parameterised Constructor
  Electron(bool isAntiparticle)
  {
    verify_input(isAntiparticle);
  } // Set variable values based on isAntiparticle

  // Destructor 
  ~Electron(){std::cout<<particle_name<<" is destroyed."<<std::endl;}
  void verify_input(bool isAntiparticle);
  void print_data() const;

  // // Getter Function
  int get_charge() const {return charge;}
  double get_rest_mass() const {return rest_mass;}
  std::string get_particle_name() const {return particle_name;}

  // Electron(const Electron &electron_called); // Copy Constructor
  // Electron(Electron &&electron_called); // Move Constructor

  // // Assignment operator made to do deep copy assigning.
  // ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // // Move assignment operator using function overloading
  // ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif