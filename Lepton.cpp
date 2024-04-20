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

  this->name = lepton_called.name;
  this->rest_mass = lepton_called.rest_mass;
  this->is_antiparticle = lepton_called.is_antiparticle;
  this->four_momentum_ptr = std::make_shared<FourMomentum>(*lepton_called.four_momentum_ptr);

  return *this;
}

Lepton::Lepton(const Lepton &lepton_called) 
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Check for self-copying
  if(this == &lepton_called)
  {
    std::cout<<"Self-copy detected in Copy Constructor. Skipping copy."<<std::endl;
    return;
  }
  else
  {
    // Copies all data members from lepton_called to current particle
    this->name = lepton_called.name;
    this->rest_mass = lepton_called.rest_mass;
    this->is_antiparticle = lepton_called.is_antiparticle;
    this->four_momentum_ptr = std::make_shared<FourMomentum>(*lepton_called.four_momentum_ptr);
  }
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
  // Move the data members
  name = std::move(lepton_called_to_move.name);
  rest_mass = std::move(lepton_called_to_move.rest_mass);
  is_antiparticle = std::move(lepton_called_to_move.is_antiparticle);
  four_momentum_ptr = std::move(lepton_called_to_move.four_momentum_ptr);
  
  return *this;
}

Lepton::Lepton(Lepton &&lepton_called_to_move)
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  // Check for self-moving
  if(this == &lepton_called_to_move)
  {
    std::cout<<"Self-move detected in Move Constructor. Skipping move."<<std::endl;
    return;
  }
  else
  {
    // Move the data members
    name = std::move(lepton_called_to_move.name);
    rest_mass = std::move(lepton_called_to_move.rest_mass);
    is_antiparticle = std::move(lepton_called_to_move.is_antiparticle);
    four_momentum_ptr = std::move(lepton_called_to_move.four_momentum_ptr);
  }
}

std::vector<double> operator+(const Lepton& lepton_called_1, const Lepton& lepton_called_2)
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector
  // // Sum the components of the four-momenta
  total_momentum[0] = lepton_called_1.get_four_momentum_ptr()->get_E() + lepton_called_2.get_four_momentum_ptr()->get_E();
  total_momentum[1] = lepton_called_1.get_four_momentum_ptr()->get_px() + lepton_called_2.get_four_momentum_ptr()->get_px();
  total_momentum[2] = lepton_called_1.get_four_momentum_ptr()->get_py() + lepton_called_2.get_four_momentum_ptr()->get_py();
  total_momentum[3] = lepton_called_1.get_four_momentum_ptr()->get_pz() + lepton_called_2.get_four_momentum_ptr()->get_pz();

  return total_momentum;
}

double dotProduct(const Lepton& lepton_called_1, const Lepton& lepton_called_2) 
{

  // Sum the components of the four-momenta
  double dotted_momentum_0 = lepton_called_1.get_four_momentum_ptr()->get_E() * lepton_called_2.get_four_momentum_ptr()->get_E();
  double dotted_momentum_1 = (lepton_called_1.get_four_momentum_ptr()->get_px() * lepton_called_2.get_four_momentum_ptr()->get_px());
  double dotted_momentum_2 = (lepton_called_1.get_four_momentum_ptr()->get_py() * lepton_called_2.get_four_momentum_ptr()->get_py());
  double dotted_momentum_3 = (lepton_called_1.get_four_momentum_ptr()->get_pz() * lepton_called_2.get_four_momentum_ptr()->get_pz());
  
  double dotted_momentum = dotted_momentum_0 - dotted_momentum_1 - dotted_momentum_2 - dotted_momentum_3;
  return dotted_momentum;
}