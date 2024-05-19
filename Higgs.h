// PHYS 30762 Programming in C++
// Final Project - Higgs class
// Derived Classes from Boson Class: photon, weak, Higgs, gluon
#ifndef HIGGS_H
#define HIGGS_H

#include<iostream>
#include<string>
#include<memory>
#include "Boson.h"
#include "Particle.h"

// Beginning of Higgs class - derived class
class Higgs: public Boson
{
private:
  // vector to contain all possible decay products pairs
  std::vector<std::pair<std::unique_ptr<Particle>, std::unique_ptr<Particle>>> decay_product_pairs;

  // Private Function

  void add_decay_product_pair(std::unique_ptr<Particle> decay_product_1, std::unique_ptr<Particle> decay_product_2)
  {
    decay_product_pairs.push_back(std::make_pair(std::move(decay_product_1), std::move(decay_product_2)));
  }
  std::pair<std::string, std::string> generateRandomQuarkColor(); // Random fn to obtain a pair of colours

public:
  // Constructors
  Higgs() = default;  // Default constructor
  // Parameterised Constructor
  
  // Use particle_charge to determine wheather Z W- or W+
  Higgs(double particle_energy, double particle_px, double particle_py, double particle_pz) :
    // Call Parameterised Constructor for ChargedLepton
    Boson{0.0, 
          false, 
          126000.0, 
          "Higgs",      
          particle_energy, 
          particle_px, 
          particle_py, 
          particle_pz, 
          "Higgs Mechanism", 
          0}
  {
    decay_higgs();
  }

  // Destructor 
  ~Higgs(){std::cout<<this->get_name()<<" is destroyed."<<std::endl;}

  void decay_higgs(); 
  void print_data() const;
  void print_decay_products() override;

  // Code these setters to override from base class. Don't want to change these values directly in the photon, W, Z or H
  void set_rest_mass(double particle_mass) override; 
  void set_name(std::string particle_name) override;

};
#endif