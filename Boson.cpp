#include<iostream>
#include<string>
#include "Boson.h"

void Boson::print_data() const
{
  // // need to use getters from Particle
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an anitparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
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

// Assignment Constructor to do Deep Copying
Boson& Boson::operator=(const Boson &boson_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&boson_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Particle::operator=(boson_called);
  this->associated_force = boson_called.associated_force;

  return *this;
}

Boson::Boson(const Boson &boson_called) : Particle(boson_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle
  this->associated_force = boson_called.associated_force;

}

Boson& Boson::operator=(Boson &&boson_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &boson_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Particle::operator=(std::move(boson_called_to_move));
    associated_force = std::move(boson_called_to_move.associated_force);
  }
    
  return *this;
}

Boson::Boson(Boson &&boson_called_to_move) : Particle(std::move(boson_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  associated_force = std::move(boson_called_to_move.associated_force);

}
