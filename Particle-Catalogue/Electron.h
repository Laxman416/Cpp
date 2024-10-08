// PHYS 30762 Programming in C++
// Assignment 5 - Electron class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include<memory>
#include "CalorimeterLayers.h"
#include "CalorimeterEnergies.h"
#include "FourMomentum.h"
#include "Lepton.h"
#include "Particle.h"

// Beginning of Electron class - derived class
class Electron: public Lepton
{
private:
  std::unique_ptr<CalorimeterEnergies> calorimeter_energies_ptr; // special unique pointer for the CalorimeterEnergies object
public:
  // Constructors
  Electron() = default;  // Default constructor
  // Parameterised Constructor
  
  Electron(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz) :
    calorimeter_energies_ptr(std::make_unique<CalorimeterEnergies>(particle_energy/2, particle_energy/2, 0.0, 0.0)),
    // Call Parameterised Constructor for ChargedLepton
    Lepton{is_antiparticle ? 1.0 : -1.0, is_antiparticle, 0.511, is_antiparticle ? "Positron" : "Electron", particle_energy, particle_px, particle_py, particle_pz, is_antiparticle ? -1 : 1}
  {
    verify_input(is_antiparticle);
  }

  // Destructor 
  ~Electron(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Getter Fn
  const std::unique_ptr<CalorimeterEnergies>& get_calorimeter_energies_ptr() const {return calorimeter_energies_ptr;}  
  std::string get_type() const override { return "Charged Lepton";}

  // Setter Fn
  void set_calorimeter_energy(double energy_EM_1, double energy_EM_2);
  void set_is_antiparticle(bool is_antiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Electron(const Electron &electron_called); // Copy Constructor
  Electron(Electron &&electron_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Electron& operator=(const Electron &electron_called);

  // Move assignment operator using function overloading
  Electron& operator=(Electron&& electron_called_to_move);
};
#endif