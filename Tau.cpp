// PHYS 30762 Programming in C++
// Assignment 5
// Tau Class implementation

#include<iostream>
#include "Tau.h"

void Tau::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tThe particle "<<(m_is_decay_leptonic ? "decays" : "does not decay")<<" leptonically."<<std::endl;
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

void Tau::decay_tau() 
{
  if(m_is_decay_leptonic)
  {
    // Creates a ChargedLepton
    std::cout<<"Creating Charged Lepton the tau decays to."<<std::endl;
    m_decayed_particle_ptr = std::make_unique<ChargedLepton>(this->get_is_antiparticle() ? -1:1, this->get_is_antiparticle(), 0.511, "Decayed Lepton", 2 ,0.0, 0.0, 0.0);
  }
}

const std::unique_ptr<ChargedLepton>& Tau::get_decayed_particle_ptr() const
{
  if (m_decayed_particle_ptr != nullptr) 
  {
    return m_decayed_particle_ptr;
  } 
  else 
  {

    throw std::runtime_error("Decayed particle pointer is null");
  }
}

void Tau::set_charge(int particle_charge)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau has a charge and cannot be changed."<<std::endl;
  std::cerr<<"Modify the is_antiparticle data member if u want to change to tau to its antipariticle or vice versa."<<std::endl;
  std::cerr<<"Error: Charge of particle not updated."<<std::endl;    
}

void Tau::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
}

void Tau::set_name(std::string particle_name)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau particle can not be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"Error: Name of particle not updated."<<std::endl;    
}

void Tau::set_is_antiparticle(bool isAntiparticle)
{
  if(this->is_antiparticle == isAntiparticle)
  {
    std::cerr<<"Error: Tau is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->is_antiparticle = isAntiparticle;
    this->charge = is_antiparticle ? -1:1;
    this->name = is_antiparticle ? "Antitau":"Tau";
    std::cerr<<"Particle updated. The name, charge and boolean data members are modified."<<std::endl;    
  }
}
