// PHYS 30762 Programming in C++
// Final Project - Photon class
// Derived Classes from Boson Class: photon, weak, Higgs, gluon
#ifndef GLUON_H
#define GLUON_H

#include<iostream>
#include<string>
#include<memory>
#include "Boson.h"

// Beginning of Electron class - derived class
class Gluon: public Boson
{
private:
  std::pair<std::string,std::string> colour_charge;

  // Private Function
  std::pair<std::string,std::string> determine_gluon_colour_charge();
public:
  // Constructors
  Gluon() = default;  // Default constructor
  // Parameterised Constructor
  
  Gluon(double particle_energy, double particle_px, double particle_py, double particle_pz) :
    // Call Parameterised Constructor for ChargedLepton
    Boson{0, 0, 0, "Gluon", particle_energy, particle_px, particle_py, particle_pz, "Strong", 1}
  {
    colour_charge = determine_gluon_colour_charge();
  }

  // Destructor 
  ~Gluon(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Code these setters to override from base class. Don't want to change these values directly in the photon, W, Z or H
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Gluon(const Gluon &gluon_called); // Copy Constructor
  Gluon(Gluon &&gluon_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Gluon& operator=(const Gluon &gluon_called);

  // Move assignment operator using function overloading
  Gluon& operator=(Gluon&& gluon_called_to_move);
};
#endif