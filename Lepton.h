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


// Beginning of lepton class - abstract class
class Lepton : public Particle
{
protected:
  bool m_is_antiparticle; // boolean: true if antiparticle
  double rest_mass; // in MeV
  std::string name;
  std::shared_ptr<FourMomentum> four_momentum_ptr; // special shared pointer for the FourMomentum object

public:
  // Constructors
  Lepton() = default;  // default constructor

  // Parameterised Constructor for Lepton
  Lepton(bool is_antiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz) : 
    m_is_antiparticle{is_antiparticle},
    name{particle_name},
    rest_mass{particle_mass},
    four_momentum_ptr(std::make_shared<FourMomentum>(particle_energy, particle_px, particle_py, particle_pz))
    {
      verify_input(is_antiparticle);
    } 

  // Destructor 
  virtual ~Lepton(){std::cout<<"Lepton is destroyed."<<std::endl;};

  virtual void print_data() const;
  
  void verify_input(bool is_antiparticle);

  friend std::vector<double> operator+(const Lepton& lepton_called_1, const Lepton& lepton_called_2);

  friend double dotProduct(const Lepton& lepton_called_1, const Lepton& lepton_called_2);

  // Getter Function
  double get_rest_mass() const {return rest_mass;}
  bool get_is_antiparticle() const {return m_is_antiparticle;}
  std::string get_name() const {return name;}
  const std::shared_ptr<FourMomentum>& get_four_momentum_ptr() const {return four_momentum_ptr;}

  // Setter Fn  
  virtual void set_rest_mass(double particle_mass);
  virtual void set_name(std::string particle_name){name = particle_name;}
  void set_four_momentum_ptr(std::shared_ptr<FourMomentum> momentum_ptr){four_momentum_ptr = momentum_ptr;}
  virtual void set_is_antiparticle(bool is_antiparticle){m_is_antiparticle = is_antiparticle;}

  Lepton(const Lepton &lepton_called); // Copy Constructor
  Lepton(Lepton &&lepton_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Lepton& operator=(const Lepton &lepton_called);

  // Move assignment operator using function overloading
  Lepton& operator=(Lepton&& lepton_called_to_move);
};

#endif