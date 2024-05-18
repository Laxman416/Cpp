// PHYS 30762 Programming in C++
// Assignment 5
// Muon Class implementation

#include<iostream>
#include "Muon.h"

void Muon::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tThe particle "<<(is_isolated ? "is" : "is not")<<" detected"<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an anitparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
  std::cout<<"\tLepton Number: "<<(this->get_lepton_number())<<std::endl;
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

void Muon::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Muon
  std::cerr<<"\033[1;31mError\033[0m: Muon has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a Lepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Muon::set_name(std::string particle_name)
{
  // Particle name can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Muon particle can not be changed."<<std::endl;
  std::cerr<<"Create a Lepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

void Muon::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"\033[1;31mError\033[0m: Muon is already in desired state."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->charge = m_is_antiparticle ? -1:1;
    this->name = m_is_antiparticle ? "Antimuon":"Muon";
    this->lepton_number = m_is_antiparticle ? -1:1;
    std::cerr<<"Particle updated. The name, charge, boolean and lepton number data members are modified."<<std::endl;    
  }
}

// Assignment Constructor to do Deep Copying
Muon& Muon::operator=(const Muon &muon_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&muon_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Lepton::operator=(muon_called);
  is_isolated = (muon_called.is_isolated);

  return *this;
}

Muon::Muon(const Muon &muon_called) : Lepton(muon_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle

  this->is_isolated = (muon_called.is_isolated);

}

Muon& Muon::operator=(Muon &&muon_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &muon_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Lepton::operator=(std::move(muon_called_to_move));
    this->is_isolated = std::move(muon_called_to_move.is_isolated);
  }
    
  return *this;
}

Muon::Muon(Muon &&muon_called_to_move) : Lepton(std::move(muon_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  is_isolated = std::move(muon_called_to_move.is_isolated);
}



