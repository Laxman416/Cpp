#include "Neutrino.h"
#include<iostream>

void Neutrino::print_data() const
{
  // // need to use getters from Particle class
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an anitparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
  std::cout<<"\tLepton Number: "<<(this->get_lepton_number())<<std::endl;
  std::cout<<"\tHas the neutrino interacted: "<<(this->get_has_interacted() ? "true" : "false")<<std::endl;

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

std::string Neutrino::get_particle_name_flavour(bool is_antiparticle, int particle_flavour) const 
{
  std::string particle_name;
  switch (particle_flavour) 
  {
    case 1:  // Electron neutrino
      particle_name = is_antiparticle ? "Antielectron Neutrino" : "Electron Neutrino";
      break;
    case 2:  // Muon neutrino
      particle_name = is_antiparticle ? "Antimuon Neutrino" : "Muon Neutrino";
      break;
    case 3:  // Tau neutrino
      particle_name = is_antiparticle ? "Antitau Neutrino" : "Tau Neutrino";
      break;
    default:
      particle_name = "Unknown Neutrino";
      break;
  }
  return particle_name;
}

void Neutrino::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Muon neutrino
  std::cerr<<"Error: Muon neutrino has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
}

void Neutrino::set_name(std::string particle_name)
{
  // Particle mass can't be changed in Muon neutrino
  std::cerr<<"Error: Muon neutrino particle can not be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"Error: Name of particle not updated."<<std::endl;    
}

void Neutrino::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"Error: Neutrino is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->name = get_particle_name_flavour(is_antiparticle, flavour);
    std::cerr<<"Particle updated. The name and boolean data members are modified."<<std::endl;    
  }
}

void Neutrino::set_neutrino_flavour(bool particle_flavour)
{
  if(this->flavour == particle_flavour)
  {
    std::cerr<<"Error: Neutrino is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->flavour = particle_flavour;
    this->name = get_particle_name_flavour(m_is_antiparticle, particle_flavour);
    std::cerr<<"Particle updated. The name and boolean data members are modified."<<std::endl;    
  }
}

// Assignment Constructor to do Deep Copying
Neutrino& Neutrino::operator=(const Neutrino &neutrino_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&neutrino_called == this)
  {
    return *this;
  } 
  // Assigns all data members from neutrino called to current particle
  // Deep Copying implemented
  Lepton::operator=(neutrino_called);
  m_has_interacted = (neutrino_called.m_has_interacted);
  flavour = (neutrino_called.flavour);

  return *this;
}

Neutrino::Neutrino(const Neutrino &neutrino_called) : Lepton(neutrino_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from neutrino_called to current particle

  this->m_has_interacted = (neutrino_called.m_has_interacted);
  this->flavour = (neutrino_called.flavour);

}

Neutrino& Neutrino::operator=(Neutrino &&neutrino_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &neutrino_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Lepton::operator=(std::move(neutrino_called_to_move));
    this->m_has_interacted = std::move(neutrino_called_to_move.m_has_interacted);
    this->flavour = std::move(neutrino_called_to_move.flavour);
  }
    
  return *this;
}

Neutrino::Neutrino(Neutrino &&neutrino_called_to_move) : Lepton(std::move(neutrino_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;
  
  this->m_has_interacted = std::move(neutrino_called_to_move.m_has_interacted);
  this->flavour = std::move(neutrino_called_to_move.flavour);
}



