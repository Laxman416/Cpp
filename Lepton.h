// PHYS 30762 Programming in C++
// Assignment 3 - Lepton class
// Derived Classes from Lepton Class: charged leptons and neutral leptons

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<memory>
#include "FourMomentum.h"

// Beginning of lepton class - abstract class
class Lepton
{
protected:
  bool is_antiparticle; // boolean: true if antiparticle
  double rest_mass; // in MeV
  std::string name;
  std::unique_ptr<FourMomentum> four_momentum_ptr;

public:
  // Constructors
  Lepton() = default;  // default constructor

  Lepton(bool isAntiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz) : 
    is_antiparticle{isAntiparticle},
    name{particle_name},
    rest_mass{particle_mass},
    four_momentum_ptr(std::make_unique<FourMomentum>(particle_energy, particle_px, particle_py, particle_pz))

    {
      verify_input(isAntiparticle);
      std::cout<<"Calling Parameterised Constructor for Lepton"<<std::endl;
    } 

  // Destructor 
  virtual ~Lepton(){std::cout<<"Lepton is destroyed."<<std::endl;};

  virtual void print_data() const = 0; // virtual print_data fn that prints that relevent data of the object
  void verify_input(bool isAntiparticle)
  {
    if(isAntiparticle != true && isAntiparticle != false)
    {
      std::cout<<"Invalid input for if it is an antiparticle is given. Setting the object to be a particle"<<std::endl;
      isAntiparticle = false;
    }
  }
 

  // Getter Function
  double get_rest_mass() const {return rest_mass;}
  bool get_is_antiparticle() const {return is_antiparticle;}
  std::string get_name() const {return name;}
  const std::unique_ptr<FourMomentum>& get_four_momentum_ptr() const { return four_momentum_ptr;}

  // Lepton(const Lepton &lepton_called); // Copy Constructor
  // Lepton(Lepton &&lepton_called); // Move Constructor

  // // Assignment operator made to do deep copy assigning.
  // Lepton& operator=(const Lepton &lepton_called);

  // // Move assignment operator using function overloading
  // Lepton& operator=(Lepton&& lepton_called_to_move);
};
#endif