// PHYS 30762 Programming in C++
// Assignment 5 - Muon Neutrino class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef TAUNEUTRINO_H
#define TAUNEUTRINO_h
#include "NeutralLepton.h"
#include<iostream>

// Beginning of MuonNeutirno class - derived class
class TauNeutrino: public NeutralLepton
{
private:
  bool m_has_interacted;
public:
  // Constructors
  TauNeutrino() = default;  // Default constructor
  // Parameterised Constructor
  TauNeutrino(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, bool has_interacted) :
    // Call Parameterised Constructor for ChargedLepton
    NeutralLepton(is_antiparticle, 5e-7 ,is_antiparticle ? "Tau Neitrino":"Tau Antineutrino", particle_energy, particle_px, particle_py, particle_pz),
    m_has_interacted{has_interacted}
  {
  }

  // Destructor 
  ~TauNeutrino(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Getter Fn
  const bool get_has_interacted() const {return m_has_interacted;}  

  // Setter Fn
  void set_has_interacted(bool has_interacted){m_has_interacted = has_interacted;}
  // Overwrite virtual fn from base class
  void set_is_antiparticle(bool is_antiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass); 
  void set_name(std::string particle_name);
};

#endif
