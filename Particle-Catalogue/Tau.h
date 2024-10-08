// PHYS 30762 Programming in C++
// Assignment 5 - Tau class
// Derived Classes from Particle Class: : electorns, muons, tau, neutrino

#ifndef TAU_H
#define TAU_h

#include<iostream>
#include<string>
#include<memory>
#include "Lepton.h"
#include "Electron.h"
#include "Muon.h"
#include "Neutrino.h"
#include "Quark.h"


// Beginning of Tau class - derived class
class Tau: public Lepton
{
private:
  bool m_is_decay_leptonic;
  bool m_is_decay_to_electrons;

  // unique_ptr as the decayed lepton should only be accessed by the decayed Tau
  std::unique_ptr<Electron> m_decayed_electron_ptr;
  std::unique_ptr<Muon> m_decayed_muon_ptr;
  std::unique_ptr<Neutrino> m_decayed_neutrino_ptr;
  std::unique_ptr<Neutrino> m_decayed_tau_neutrino_ptr;
  std::unique_ptr<Quark> m_decayed_up_quark_ptr;
  std::unique_ptr<Quark> m_decayed_down_quark_ptr;

  // Private Functions
  
  // Private so no Access to Outside. Fn get_decayed_particle_ptr will decide which fn to use
  const std::unique_ptr<Electron>& get_decayed_electron_ptr() const;
  const std::unique_ptr<Muon>& get_decayed_muon_ptr() const;

  // Public version: decay_tau()
  void decay_tau_leptonically(); // fn to process leptonic decay
  void decay_tau_hadronically(); // fn to process tau deacy 

  const bool determine_decay_leptonic(); // Random fn to determine if decay is leptonic
  std::pair<std::string, std::string> generateRandomQuarkColor(); // Random fn to obtain a pair of colours

public:
  Tau() = default;
  // Parameterised Constructor
  Tau(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz):
    m_decayed_electron_ptr(nullptr),
    m_decayed_muon_ptr(nullptr),

    // Call Parameterised Constructor for Lepton
    Lepton{is_antiparticle ? 1.0 : -1.0, is_antiparticle, 1778, is_antiparticle ? "Antitau" : "Tau", particle_energy, particle_px, particle_py, particle_pz, is_antiparticle ? -1 : 1}
  {
    verify_input(is_antiparticle);
    m_is_decay_leptonic = determine_decay_leptonic();// use branching ratios to randomise if decay is leptonic or hadronic
    decay_tau();
  }

  // Destructor 
  ~Tau(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Decays the tau via Leptonic decay or Hadronic decay
  void decay_tau(); 
  // Getter Fn
  const bool get_is_decay_leptonic() const {return m_is_decay_leptonic;}
  const bool get_is_decay_to_electrons() const {return m_is_decay_to_electrons;}
  const void get_decayed_lepton_ptr() const;
  const std::unique_ptr<Neutrino>& get_decayed_lepton_neutrino_ptr() const;
  const std::unique_ptr<Neutrino>& get_decayed_tau_neutrino_ptr() const;
  const std::unique_ptr<Quark>&get_decayed_up_quark_ptr() const;
  const std::unique_ptr<Quark>& get_decayed_down_quark_ptr() const;
  std::string get_type() const override { return "Charged Lepton";}

  // Setter Fn
  void set_is_decay_leptonic(bool is_decay_leptonic){m_is_decay_leptonic = is_decay_leptonic;}
  void set_is_decay_to_electrons(bool is_decay_to_electrons){m_is_decay_to_electrons = is_decay_to_electrons;}
  void set_decayed_particle_ptr(std::unique_ptr<Electron> decayed_electron_ptr){m_decayed_electron_ptr = std::move(decayed_electron_ptr);}
  void set_decayed_particle_ptr(std::unique_ptr<Muon> decayed_muon_ptr){m_decayed_muon_ptr = std::move(decayed_muon_ptr);}
  void set_neutrino_particle_ptr(std::unique_ptr<Neutrino> decayed_neutrino_ptr){m_decayed_neutrino_ptr = std::move(decayed_neutrino_ptr);}
  void set_tau_neutrino_particle_ptr(std::unique_ptr<Neutrino> decayed_tau_neutrino_ptr){m_decayed_tau_neutrino_ptr = std::move(decayed_tau_neutrino_ptr);}
  void set_up_quark_particle_ptr(std::unique_ptr<Quark> decayed_up_quark_ptr){m_decayed_up_quark_ptr = std::move(decayed_up_quark_ptr);}
  void set_down_quark_particle_ptr(std::unique_ptr<Quark> decayed_down_quark_ptr){m_decayed_down_quark_ptr = std::move(decayed_down_quark_ptr);}


  void set_is_antiparticle(bool is_antiparticle);
  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass); 
  void set_name(std::string particle_name);
  void set_charge(int particle_charge);

  Tau(const Tau &tau_called); // Copy Constructor
  Tau(Tau &&tau_called_to_move); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Tau& operator=(const Tau &tau_called);

  // Move assignment operator using function overloading
  Tau& operator=(Tau&& tau_called_to_move);
};

#endif

