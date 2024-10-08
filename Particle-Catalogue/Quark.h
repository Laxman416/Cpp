// PHYS 30762 Programming in C++
// Final Project - Quark Class
// Derived Classes from Particle Class: Leptons and Quarks
#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<string>
#include<memory>
#include "FourMomentum.h"
#include "Particle.h"

#include<stdexcept>


// Beginning of quark class 
class Quark : public Particle
{
private:
  // User doesnt need access to these functions
  std::string get_particle_name_from_flavour(bool is_antiparticle, int particle_flavour, bool is_up_type) const; 
  double get_particle_mass_from_flavour(bool is_up_type, int particle_flavour) const; 
  double get_particle_charge_from_up_type(bool is_antiparticle, bool is_up_type) const; 
  double verify_input(bool is_antiparticle);//returns baryon number as well
  std::string verify_input_color_charge(const std::string& particle_colour_charge) const;


  // Data Members
  double baryon_number;
  std::string colour_charge;
  bool m_is_up_type; // boolean to use for Weak Decays: In weak quark decays, only coupling between up-type and down-type
  int flavour; 

public:
  // Constructors
  Quark() = default;  // default constructor

  // Parameterised Constructor for Lepton
  Quark(bool is_antiparticle, double particle_energy, double particle_px, double particle_py, double particle_pz, int particle_flavour, std::string particle_colour_charge, bool particle_is_up_type) :  
    flavour{particle_flavour},
    m_is_up_type{particle_is_up_type},

    Particle(get_particle_charge_from_up_type(is_antiparticle , particle_is_up_type), 
            is_antiparticle, 
            get_particle_mass_from_flavour(particle_is_up_type, particle_flavour), 
            get_particle_name_from_flavour(is_antiparticle, particle_flavour, particle_is_up_type), 
            particle_energy, 
            particle_px, 
            particle_py, 
            particle_pz, 
            0.5)
  {
    colour_charge = verify_input_color_charge(particle_colour_charge);
    baryon_number = verify_input(is_antiparticle);

  } 

  // Destructor 
  virtual ~Quark(){std::cout<<"Quark is destroyed."<<std::endl;};

  virtual void print_data() const;

  // Getter Function
  const double get_baryon_number() const {return baryon_number;}
  std::string get_type() const override;
  const std::string get_colour_charge() const {return colour_charge;}
  bool get_is_up_type() const {return m_is_up_type;}
  const bool get_quark_flavour() const{return flavour;} 

  // Setter Fn  
  void set_baryon_number(double particle_lepton_number);
  void set_is_antiparticle(bool is_antiparticle);
  void set_colour_charge(std::string particle_colour_charge);
  void set_is_up_type(bool is_up_type);

  // Code these setters to override from base class. Don't want to change these values directly in the tau, electron or muon classses.
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Quark(const Quark &quark_called); // Copy Constructor
  Quark(Quark &&quark_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Quark& operator=(const Quark &quark_called_to_move);

  // Move assignment operator using function overloading
  Quark& operator=(Quark&& quark_called_to_move);
};

#endif