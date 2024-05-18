// PHYS 30762 Programming in C++
// Assignment 5
// Electron Class implementation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "Electron.h"


void Electron::set_calorimeter_energy(double energy_EM_1, double energy_EM_2)
{
  // Check if the total energy deposited in calorimeter layers is equal to the energy of the electron from the Four Momentum
  double total_energy = energy_EM_1 + energy_EM_2;

  if(total_energy != this->get_four_momentum_ptr()->get_E())
  {
    // Adjust energies to ensure consistency
    double energy_difference = this->get_four_momentum_ptr()->get_E() - total_energy;
    if(energy_difference > 0)
    {
      energy_EM_1 += energy_difference / 2;
      energy_EM_2 += energy_difference / 2;
    }
    else
    {
      // Distribute the excess energy proportionally
      double factor = four_momentum_ptr->get_E() / total_energy;
      energy_EM_1 = energy_EM_1 * factor;
      energy_EM_2 = energy_EM_1 * factor;
    }
  }
    calorimeter_energies_ptr->set_calorimeter_energy(energy_EM_1, energy_EM_2, 0, 0);
}



void Electron::print_data() const
{
  // // need to use getters from Particle class
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
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
  if(calorimeter_energies_ptr != nullptr) 
  {
    calorimeter_energies_ptr->print_calorimeter_info();
  } 
  else 
  {
    std::cout<<"Calorimeter Data not available"<<std::endl;
  }
}


void Electron::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Electron has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a Lepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Electron::set_name(std::string particle_name)
{
  // Particle name can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Electron particle can not be changed."<<std::endl;
  std::cerr<<"Create a Lepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}


void Electron::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"\033[1;31mError\033[0m: Electron is already in desired state."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->charge = m_is_antiparticle ? -1:1;
    this->name = m_is_antiparticle ? "Antielectron":"Electron";
    this->lepton_number = m_is_antiparticle ? -1:1;
    std::cerr<<"Particle updated. The name, charge, boolean and lepton number data members are modified."<<std::endl;    
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
  Lepton::operator=(electron_called);
  calorimeter_energies_ptr = std::make_unique<CalorimeterEnergies>(*electron_called.calorimeter_energies_ptr);

  return *this;
}

Electron::Electron(const Electron &electron_called) : Lepton(electron_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle

  this->calorimeter_energies_ptr = std::make_unique<CalorimeterEnergies>(*electron_called.calorimeter_energies_ptr);

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
    Lepton::operator=(std::move(electron_called_to_move));
    this->calorimeter_energies_ptr = std::move(electron_called_to_move.calorimeter_energies_ptr);
  }
    
  return *this;
}

Electron::Electron(Electron &&electron_called_to_move) : Lepton(std::move(electron_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  calorimeter_energies_ptr = std::move(electron_called_to_move.calorimeter_energies_ptr);

}



