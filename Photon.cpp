#include<iostream>
#include<string>
#include "Photon.h"

void Photon::print_data() const
{
  // // need to use getters from Particle
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tBoson is associated with the : "<<(associated_force)<<" Force"<<std::endl;

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


void Photon::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Photon
  std::cerr<<"\033[1;31mError\033[0m: Photon has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Photon::set_name(std::string particle_name)
{
  // Particle name can't be changed in Photon
  std::cerr<<"\033[1;31mError\033[0m: Photon particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}


// Assignment Constructor to do Deep Copying
Photon& Photon::operator=(const Photon &photon_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&photon_called == this)
  {
    return *this;
  } 
  // Assigns all data members from photon to current particle
  // Deep Copying implemented
  Boson::operator=(photon_called);

  return *this;
}

Photon::Photon(const Photon &photon_called) : Boson(photon_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from photon to current particle
}

Photon& Photon::operator=(Photon &&photon_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &photon_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Boson::operator=(std::move(photon_called_to_move));
  }
    
  return *this;
}

Photon::Photon(Photon &&photon_called_to_move) : Boson(std::move(photon_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

}