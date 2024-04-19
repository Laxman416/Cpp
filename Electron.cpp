// PHYS 30762 Programming in C++
// Assignment 5
// Electron Class implementation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "Electron.h"

void Electron::verify_input(bool isAntiparticle) 
{
  if(isAntiparticle != true && isAntiparticle != false)
  {
    std::cout<<"Invalid input for if it is an antiparticle is given. Setting the object to be a particle"<<std::endl;
    isAntiparticle = false;
  }
}

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
}