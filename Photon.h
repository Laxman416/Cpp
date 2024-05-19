// PHYS 30762 Programming in C++
// Final Project - Photon class
// Derived Classes from Boson Class: photon, weak, Higgs. gluon
#ifndef PHOTON_H
#define PHOTON_H

#include<iostream>
#include<string>
#include<memory>
#include "Boson.h"

// Beginning of Electron class - derived class
class Photon: public Boson
{
private:
public:
  // Constructors
  Photon() = default;  // Default constructor
  // Parameterised Constructor
  
  Photon(double particle_energy, double particle_px, double particle_py, double particle_pz) :
    // Call Parameterised Constructor for ChargedLepton
    Boson{0, 0, 0, "Photon", particle_energy, particle_px, particle_py, particle_pz, "EM", 1}
  {
  }

  // Destructor 
  ~Photon(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void print_data() const;

  // Code these setters to override from base class. Don't want to change these values directly in the photon, W, Z or H
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Photon(const Photon &photon_called); // Copy Constructor
  Photon(Photon &&photon_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Photon& operator=(const Photon &photon_called);

  // Move assignment operator using function overloading
  Photon& operator=(Photon&& photon_called_to_move);
};
#endif