// PHYS 30762 Programming in C++
// Assignment 3 - Lepton class
// Derived Classes from Lepton Class: charged leptons and neutral leptons

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<memory>
#include "FourMomentum.h"
#include "Particle.h"

#include<stdexcept>


// Beginning of lepton class
class Lepton : public Particle
{
protected:
  int lepton_number;

public:
  // Constructors
  Lepton() = default;  // default constructor

  // Parameterised Constructor for Lepton
  Lepton(double particle_charge, bool is_antiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz, int particle_lepton_number) : 
    lepton_number{particle_lepton_number},
    Particle(particle_charge, is_antiparticle, particle_mass, particle_name, particle_energy, particle_px, particle_py, particle_pz, 0.5)
  {
    verify_input(is_antiparticle);
  } 

  // Destructor 
  virtual ~Lepton(){std::cout<<"Lepton is destroyed."<<std::endl;};

  virtual void print_data() const;
  
  void verify_input(bool is_antiparticle);

  // Getter Function
  int get_lepton_number() const {return lepton_number;}
  std::string get_type() const override { return "Lepton";}

  // Setter Fn  
  virtual void set_lepton_number(int particle_lepton_number){lepton_number = particle_lepton_number;}

  Lepton(const Lepton &lepton_called); // Copy Constructor
  Lepton(Lepton &&lepton_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Lepton& operator=(const Lepton &lepton_called);

  // Move assignment operator using function overloading
  Lepton& operator=(Lepton&& lepton_called_to_move);
};

#endif