#include<iostream>
#include<string>
#include "Lepton.h"

void Lepton::set_rest_mass(double particle_mass)
{
  // particle mass must be positive
  if(particle_mass < 0)
  {
    std::cerr<<"Error: Invalid value for rest mass. Mass must be positive."<<std::endl;
    std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
  }
  else
  {
    rest_mass = particle_mass;
  }
}

void Lepton::verify_input(bool isAntiparticle)
{
  if(isAntiparticle != true && isAntiparticle != false)
  {
    std::cout<<"Warning: Invalid value for 'isAntiparticle' parameter. Defaulting to false."<<std::endl;
    isAntiparticle = false;
  }
}

void Lepton::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRzest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  // Call print_data() function on the four_momentum_ptr object
  if(four_momentum_ptr != nullptr) 
  {
    four_momentum_ptr->print_data();
  } 
  else 
  {
    std::cout<<"Four Momentum Data not available"<<std::endl;
  }
};

