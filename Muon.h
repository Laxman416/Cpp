// PHYS 30762 Programming in C++
// Assignment 5 - Muon class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include<memory>
#include "ChargedLepton.h"

// Beginning of Muon class - derived class
class Muon: public ChargedLepton
{
private:
  bool is_isolated;

public:
  Muon() = default;
  // Parameterised Constructor
  Muon(bool isAntiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, bool is_isolated_particle):
    is_isolated{is_isolated_particle},
    // Call Parameterised Constructor for ChargedLepton
    ChargedLepton{is_antiparticle ? -1:1, isAntiparticle, 105.7 ,is_antiparticle ? "Antimuon":"Muon", particle_energy, particle_px, particle_py, particle_pz}
  {
  }

  // Destructor 
  ~Muon(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;
  
  // Getter Fn
  const bool get_is_isolated() const {return is_isolated;}  

  // Setter Fn
  void set_is_isolated(bool is_isolated_particle){is_isolated = is_isolated_particle;}
  void set_is_antiparticle(bool isAntiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass); 
  void set_name(std::string particle_name);
  void set_charge(int particle_charge);
};

#endif

