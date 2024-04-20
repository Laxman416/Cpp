// PHYS 30762 Programming in C++
// Assignment 5
// Electron Class implementation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "Electron.h"

void Electron::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  // Call print_data() function on the four_momentum_ptr object
  if(four_momentum_ptr != nullptr) 
  {
    four_momentum_ptr->print_data();
  } 
  else 
  {
    std::cout<<"Four Momentum Data not available"<<std::endl;
  }
  if(calorimeter_energies_ptr != nullptr) 
  {
    calorimeter_energies_ptr->print_calorimeter_info();
  } 
  else 
  {
    std::cout<<"Calorimeter Data not available"<<std::endl;
  }
}

void Electron::set_charge(int particle_charge)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Electron has a charge and cannot be changed."<<std::endl;
  std::cerr<<"Modify the is_antiparticle data member if u want to change to electron to its antipariticle or vice versa."<<std::endl;
  std::cerr<<"Error: Charge of particle not updated."<<std::endl;    
}

void Electron::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Electron
  std::cerr<<"Error: Electron has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
}

void Electron::set_name(std::string particle_name)
{
  // Particle mass can't be changed in Electron
  std::cerr<<"Error: Electron particle can not be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"Error: Name of particle not updated."<<std::endl;    
}

void Electron::set_is_antiparticle(bool isAntiparticle)
{
  if(this->is_antiparticle == isAntiparticle)
  {
    std::cerr<<"Error: Electron is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->is_antiparticle = isAntiparticle;
    this->charge = is_antiparticle ? -1:1;
    this->name = is_antiparticle ? "Antielectron":"Electron";
    std::cerr<<"Particle updated. The name, charge and boolean data members are modified."<<std::endl;    
  }
}
