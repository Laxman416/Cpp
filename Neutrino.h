// PHYS 30762 Programming in C++
// Assignment 5 - Neutrino class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include<memory>
#include "Lepton.h"


class Neutrino: public Lepton
// Beginning of Electron class - derived class
{
private:
  bool m_has_interacted;
  int flavour; 
public:
  Neutrino() = default;
  // Parameterised Constructor
  Neutrino(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, bool has_interacted, int particle_flavour):
    m_has_interacted{has_interacted},
    flavour{particle_flavour},
    Lepton{is_antiparticle ? 1.0 : -1.0, 
           is_antiparticle, 
           0.511, 
           get_particle_name_flavour(is_antiparticle, particle_flavour), 
           particle_energy, 
           particle_px, 
           particle_py, 
           particle_pz, 
           is_antiparticle ? -1 : 1}
  {
    verify_input(is_antiparticle);
  }

  // Destructor 
  ~Neutrino(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Getter Fn
  const bool get_has_interacted() const {return m_has_interacted;}
  const bool get_neutrino_flavour() const{return flavour;} 
  
  std::string get_particle_name_flavour(bool is_antiparticle, int particle_flavour) const; 
  std::string get_type() const override {return "Neutrino";} // used for Container

  // Setter Fn
  void set_has_interacted(bool has_interacted){m_has_interacted = has_interacted;}
  // Overwrite virtual fn from base class
  void set_is_antiparticle(bool is_antiparticle);
  void set_neutrino_flavour(bool particle_flavour);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass); 
  void set_name(std::string particle_name);


  Neutrino(const Neutrino &neutrino_called); // Copy Constructor
  Neutrino(Neutrino &&neutrino_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Neutrino& operator=(const Neutrino &neutrino_called);

  // Move assignment operator using function overloading
  Neutrino& operator=(Neutrino&& neutrino_called_to_move);
};
#endif