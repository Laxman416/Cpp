#include<iostream>
#include<string>
#include "Lepton.h"


void Lepton::verify_input(bool is_antiparticle)
{
  if(is_antiparticle != true && is_antiparticle != false)
  {
    std::cout<<"Warning: Invalid value for 'is_antiparticle' parameter. Defaulting to false."<<std::endl;
    is_antiparticle = false;
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

// Assignment Constructor to do Deep Copying
Lepton& Lepton::operator=(const Lepton &lepton_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&lepton_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Particle::operator=(lepton_called);
  this->lepton_number = lepton_called.lepton_number;

  return *this;
}

Lepton::Lepton(const Lepton &lepton_called) : Particle(lepton_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle
  this->lepton_number = lepton_called.lepton_number;

}

Lepton& Lepton::operator=(Lepton &&lepton_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &lepton_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Particle::operator=(std::move(lepton_called_to_move));
    lepton_number = std::move(lepton_called_to_move.lepton_number);
  }
    
  return *this;
}

Lepton::Lepton(Lepton &&lepton_called_to_move) : Particle(std::move(lepton_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  lepton_number = std::move(lepton_called_to_move.lepton_number);

}
