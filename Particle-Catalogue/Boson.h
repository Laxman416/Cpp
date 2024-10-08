// PHYS 30762 Programming in C++
// Final Project - Boson Class
// Derived Classes from Particle Class: Bosons containing the force carriers
#ifndef BOSON_H
#define BOSON_H

#include<iostream>
#include<string>
#include<memory>
#include "FourMomentum.h"
#include "Particle.h"

#include<stdexcept>


// Beginning of Boson class 
class Boson : public Particle
{
protected:
  // Data Members
  std::string associated_force; // the force associated with the Boson. Higgs doesn't have one - contributes to Higgs mechanism which gives mass to W bosons.
public:
  // Constructors
  Boson() = default;  // default constructor

  // Parameterised Constructor for Lepton
  Boson(double particle_charge, bool is_antiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz, std::string particle_associated_force, double particle_spin) : 
    associated_force{particle_associated_force},
    Particle(particle_charge,
             is_antiparticle,
             particle_mass, 
             particle_name, 
             particle_energy, 
             particle_px, 
             particle_py, 
             particle_pz, 
             particle_spin)
  {
    verify_input(is_antiparticle);
  } 

  // Destructor 
  virtual ~Boson(){std::cout<<"Boson is destroyed."<<std::endl;};

  virtual void print_data() const;
  virtual void print_data(){};

  // Getter Function
  std::string get_associated_force() const {return associated_force;}
  std::string get_type() const override { return "Boson";}


  // Setter Fn  
  virtual void set_lepton_number(std::string particle_associated_force){associated_force = particle_associated_force;}

  Boson(const Boson &boson_called); // Copy Constructor
  Boson(Boson &&boson_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Boson& operator=(const Boson &boson_called_to_move);

  // Move assignment operator using function overloading
  Boson& operator=(Boson&& boson_called_to_move);
};

#endif