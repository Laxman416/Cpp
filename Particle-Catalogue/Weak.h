// PHYS 30762 Programming in C++
// Final Project - Weak class
// Derived Classes from Boson Class: photon, weak, Higgs, gluon
#ifndef WEAK_H
#define WEAK_H

#include<iostream>
#include<string>
#include<memory>
#include "Boson.h"
#include "Particle.h"

// Beginning of Weak class - derived class
class Weak: public Boson
{
private:
  // vector to contain all possible decay products pairs
  std::vector<std::pair<std::unique_ptr<Particle>, std::unique_ptr<Particle>>> decay_product_pairs;

  // Private Function
  std::string get_particle_name_from_charge(double particle_charge) const;
  bool get_is_antiparticle_from_charge(double particle_charge);
  double get_particle_mass_from_flavour(double particle_charge) const; 

  void add_decay_product_pair(std::unique_ptr<Particle> decay_product_1, std::unique_ptr<Particle> decay_product_2)
  {
    decay_product_pairs.push_back(std::make_pair(std::move(decay_product_1), std::move(decay_product_2)));
  }
  std::pair<std::string, std::string> generateRandomQuarkColor(); // Random fn to obtain a pair of colours

public:
  // Constructors
  Weak() = default;  // Default constructor
  // Parameterised Constructor
  
  // Use particle_charge to determine wheather Z W- or W+
  Weak(double particle_energy, double particle_px, double particle_py, double particle_pz, double particle_charge) :
    // Call Parameterised Constructor for ChargedLepton
    Boson{particle_charge, 
          get_is_antiparticle_from_charge(particle_charge), 
          get_particle_mass_from_flavour(particle_charge), 
          get_particle_name_from_charge(particle_charge),      
          particle_energy, 
          particle_px, 
          particle_py, 
          particle_pz, 
          "Weak", 
          1}
  {
    input_check_charge(particle_charge);
    decay_weak();
  }

  // Destructor 
  ~Weak(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void decay_weak(); 
  void print_data() const;
  void print_decay_products() override;

  void input_check_charge(double particle_charge);


  // Code these setters to override from base class. Don't want to change these values directly in the photon, W, Z or H
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

  Weak(Weak &&photon_called); // Move Constructor
  
  // // Move assignment operator using function overloading
  Weak& operator=(Weak&& photon_called_to_move);

};
#endif