// PHYS 30762 Programming in C++
// Assignment 5 - Tau class
// Derived Classes from Particle Class: charged leptons and neutral leptons: electorns, muons, tau, electron neutrino, muon neutrino, tau neutrino

#ifndef TAU_H
#define TAU_h

#include<iostream>
#include<string>
#include<memory>
#include "ChargedLepton.h"
#include "Electron.h"
#include "Muon.h"


// Beginning of Tau class - derived class
class Tau: public ChargedLepton
{
private:
  bool m_is_decay_leptonic;
  // unique_ptr as the decayed lepton should only be accessed by the decayed Tau
  std::unique_ptr<Electron> m_decayed_electron_ptr;
  std::unique_ptr<Muon> m_decayed_muon_ptr;
  bool m_is_decay_to_electrons;

  // Private so no Access to Outside. Fn get_decayed_particle_ptr will decide which fn to use
  const std::unique_ptr<Electron>& get_decayed_electron_ptr() const;
  const std::unique_ptr<Muon>& get_decayed_muon_ptr() const;

public:
  Tau() = default;
  // Parameterised Constructor
  Tau(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, bool is_decay_leptonic):
    m_is_decay_leptonic{is_decay_leptonic},
    m_decayed_electron_ptr(nullptr),
    m_decayed_muon_ptr(nullptr),

    // Call Parameterised Constructor for ChargedLepton
    ChargedLepton{is_antiparticle ? -1:1, is_antiparticle, 105.7 ,(is_antiparticle ? "Antitau":"Tau"), particle_energy, particle_px, particle_py, particle_pz}
  {
    verify_input(is_antiparticle);
    decay_tau();
  }

  // Destructor 
  ~Tau(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Decays the tau and creates a Charged Lepton
  void decay_tau(); 
  // Getter Fn
  const bool get_is_deacay_leptonic() const {return m_is_decay_leptonic;}
  const bool get_is_decay_to_electrons() const {return m_is_decay_to_electrons;}
  const void get_decayed_particle_ptr() const;

  // Setter Fn
  void set_is_decay_leptonic(bool is_decay_leptonic){m_is_decay_leptonic = is_decay_leptonic;}
  void set_is_decay_to_electrons(bool is_decay_to_electrons){m_is_decay_to_electrons = is_decay_to_electrons;}
  void set_decayed_particle_ptr(std::unique_ptr<Electron> decayed_electron_ptr){m_decayed_electron_ptr = std::move(decayed_electron_ptr);}
  void set_decayed_particle_ptr(std::unique_ptr<Muon> decayed_muon_ptr){m_decayed_muon_ptr = std::move(decayed_muon_ptr);}
  void set_is_antiparticle(bool is_antiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass); 
  void set_name(std::string particle_name);
  void set_charge(int particle_charge);
};

#endif

