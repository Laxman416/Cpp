// PHYS 30762 Programming in C++
// Assignment 5 - Charged Lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef ELECTRON
#define ELECTRON

#include<iostream>
#include<string>
#include "ChargedLepton.h"

// Beginning of Electron class - derived class
class Electron: public ChargedLepton
{
private:
public:
  // Constructors
  Electron() = default;  // Default constructor
  // Parameterised Constructor
  Electron(bool isAntiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz) :
    ChargedLepton{is_antiparticle ? -1:1, isAntiparticle, 0.511 ,is_antiparticle ? "Positron":"Electron", particle_energy, particle_px, particle_py, particle_pz}
  {
    std::cout<<"Calling Parameterised Constructor for Electron"<<std::endl;
    verify_input(isAntiparticle);
  }

  // Destructor 
  ~Electron(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}
  void verify_input(bool isAntiparticle);
  void print_data() const;

  // Electron(const Electron &electron_called); // Copy Constructor
  // Electron(Electron &&electron_called); // Move Constructor

  // // Assignment operator made to do deep copy assigning.
  // ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // // Move assignment operator using function overloading
  // ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif