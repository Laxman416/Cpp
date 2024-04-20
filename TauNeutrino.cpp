// PHYS 30762 Programming in C++
// Assignment 5
// TauNeutirno Class implementation

#include<iostream>
#include "TauNeutrino.h"

void TauNeutrino::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tThe particle "<<(m_has_interacted ? "has" : "has not")<<" interacted"<<std::endl;
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

void TauNeutrino::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Tau neutrino
  std::cerr<<"Error: Tau neutrino has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
}

void TauNeutrino::set_name(std::string particle_name)
{
  // Particle mass can't be changed in Tau neutrino
  std::cerr<<"Error: Tau neutrino particle can not be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"Error: Name of particle not updated."<<std::endl;    
}

void TauNeutrino::set_is_antiparticle(bool isAntiparticle)
{
  if(this->is_antiparticle == isAntiparticle)
  {
    std::cerr<<"Error: Tau neutrino is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->is_antiparticle = isAntiparticle;
    this->name = (is_antiparticle ? "Tau Antineutrino":"Tau neutrino");
    std::cerr<<"Particle updated. The name and boolean data members are modified."<<std::endl;    
  }
}
