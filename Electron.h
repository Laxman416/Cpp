// PHYS 30762 Programming in C++
// Assignment 5 - Charged Lepton class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef ELECTRON
#define ELECTRON

#include<iostream>
#include<string>
#include<memory>
#include "ChargedLepton.h"
#include "CalorimeterLayers.h"
#include "CalorimeterEnergies.h"

// Beginning of Electron class - derived class
class Electron: public ChargedLepton
{
private:
  std::unique_ptr<CalorimeterEnergies> calorimeter_energies_ptr; // special unique pointer for the CalorimeterEnergies object

public:
  // Constructors
  Electron() = default;  // Default constructor
  // Parameterised Constructor
  Electron(bool isAntiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz) :
    calorimeter_energies_ptr(std::make_unique<CalorimeterEnergies>(particle_energy/2, particle_energy/2, 0.0, 0.0, four_momentum_ptr)),
    // Call Parameterised Constructor for ChargedLepton
    ChargedLepton{is_antiparticle ? -1:1, isAntiparticle, 0.511 ,is_antiparticle ? "Electron":"Positron", particle_energy, particle_px, particle_py, particle_pz}
  {
    std::cout<<"Calling Parameterised Constructor for Electron"<<std::endl;
  }

  // Destructor 
  ~Electron(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Getter Fn
  const std::unique_ptr<CalorimeterEnergies>& get_calorimeter_energies_ptr() const {return calorimeter_energies_ptr;}  

  // Electron(const Electron &electron_called); // Copy Constructor
  // Electron(Electron &&electron_called); // Move Constructor

  // // Assignment operator made to do deep copy assigning.
  // ChargedLepton& operator=(const ChargedLepton &charged_lepton_called);

  // // Move assignment operator using function overloading
  // ChargedLepton& operator=(ChargedLepton&& charged_lepton_called_to_move);
};
#endif