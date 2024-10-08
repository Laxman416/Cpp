// PHYS 30762 Programming in C++
// Assignment 5
// Electron Class implementation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "Electron.h"
#include "ChargedLepton.h"


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
  std::cerr<<"Modify the m_is_antiparticle data member if u want to change to electron to its antipariticle or vice versa."<<std::endl;
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

void Electron::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"Error: Electron is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->charge = m_is_antiparticle ? -1:1;
    this->name = m_is_antiparticle ? "Antielectron":"Electron";
    std::cerr<<"Particle updated. The name, charge and boolean data members are modified."<<std::endl;    
  }
}

// Assignment Constructor to do Deep Copying
Electron& Electron::operator=(const Electron &electron_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&electron_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  ChargedLepton::operator=(electron_called);
  calorimeter_energies_ptr = std::make_unique<CalorimeterEnergies>(*electron_called.calorimeter_energies_ptr);

  return *this;
}

Electron::Electron(const Electron &electron_called) : ChargedLepton(electron_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Check for self-copying
  if(this == &electron_called)
  {
    std::cout<<"Self-copy detected in Copy Constructor. Skipping copy."<<std::endl;
    return;
  }
  else
  {
    // Copies all data members from lepton_called to current particle

    this->calorimeter_energies_ptr = std::make_unique<CalorimeterEnergies>(*electron_called.calorimeter_energies_ptr);
  }
}

Electron& Electron::operator=(Electron &&electron_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &electron_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    ChargedLepton::operator=(std::move(electron_called_to_move));
    this->calorimeter_energies_ptr = std::move(electron_called_to_move.calorimeter_energies_ptr);
  }
    
  return *this;
}

Electron::Electron(Electron &&electron_called_to_move) : ChargedLepton(std::move(electron_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  // Check for self-moving
  if(this == &electron_called_to_move)
  {
    std::cout<<"Self-move detected in Move Constructor. Skipping move."<<std::endl;
    return;
  }
  else
  {
    // Move the data members
    calorimeter_energies_ptr = std::move(electron_called_to_move.calorimeter_energies_ptr);

  }
}


