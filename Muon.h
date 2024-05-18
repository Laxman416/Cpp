// PHYS 30762 Programming in C++
// Assignment 5 - Muon class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include<memory>
#include "Lepton.h"


class Muon: public Lepton
// Beginning of Electron class - derived class
{
private:
  bool is_isolated;

public:
  Muon() = default;
  // Parameterised Constructor
  Muon(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, bool is_isolated_particle):
    is_isolated{is_isolated_particle},
    Lepton{is_antiparticle ? 1.0 : -1.0, is_antiparticle, 0.511, is_antiparticle ? "Antimuon" : "Muon", particle_energy, particle_px, particle_py, particle_pz, is_antiparticle ? -1 : 1}
  {
    verify_input(is_antiparticle);
  }

  // Destructor 
  ~Muon(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Getter Fn
  const bool get_is_isolated() const {return is_isolated;}  
  std::string get_type() const override { return "Charged Lepton";}

  // Setter Fn
  void set_is_isolated(bool is_isolated_particle){is_isolated = is_isolated_particle;}
  void set_is_antiparticle(bool is_antiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Muon(const Muon &muon_called); // Copy Constructor
  Muon(Muon &&muon_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Muon& operator=(const Muon &muon_called);

  // Move assignment operator using function overloading
  Muon& operator=(Muon&& muon_called_to_move);
};


#endif

