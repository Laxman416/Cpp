// PHYS 30762 Programming in C++
// Assignment 5
// Practice with C++ classes and their interactions
// Implementation of four_momentum class

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "FourMomentum.h"

void FourMomentum::verify_input(double& particle_energy) 
{
  if(particle_energy >= 0) 
  {
    return;
  } 
  else 
  {
    std::cerr<<"Error: Invalid four momentum given. E must be positive. "<<std::endl;
    std::cerr<<"Setting the energy to 0."<<std::endl;
    particle_energy = 0; // Set E to 0
  }
}

void FourMomentum::print_data() const
{
  // Prints the data
  std::cout<<"\tPrinting Four momentum Elements:"<<std::endl;
  std::cout<<"\t\tEnergy: "<<E<<" MeV"<<std::endl;
  std::cout<<"\t\tpx: "<<px<<" MeV"<<std::endl;
  std::cout<<"\t\tpy: "<<py<<" MeV"<<std::endl;
  std::cout<<"\t\tpz: "<<pz<<" MeV"<<std::endl;
}

void FourMomentum::set_E(double energy)
{
  if(energy >= 0) 
  {
    E = energy;
  }
  else
  {
    std::cerr<<"Error: Invalid E given. E must be positive."<<std::endl;
    std::cerr<<"Energy of particle not updated."<<std::endl;
  }
}

void FourMomentum::set_px(double particle_px)
{
    px = particle_px;
}

void FourMomentum::set_py(double particle_py)
{
    py= particle_py;
}

void FourMomentum::set_pz(double particle_pz)
{
    pz = particle_pz;
}

std::vector<double> FourMomentum::operator+(const FourMomentum& four_momentum_called) const 
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector
  // Sum the components of the four-momenta
  total_momentum[0] = get_E() + four_momentum_called.get_E();
  total_momentum[1] = get_px() + four_momentum_called.get_px();
  total_momentum[2] = get_py() + four_momentum_called.get_py();
  total_momentum[3] = get_pz() + four_momentum_called.get_pz();

  return total_momentum;
}

std::vector<double> FourMomentum::operator-(const FourMomentum& four_momentum_called) const 
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector
  // Subtract the components of the four-momenta
  total_momentum[0] = get_E() - four_momentum_called.get_E();
  total_momentum[1] = get_px() - four_momentum_called.get_px();
  total_momentum[2] = get_py() - four_momentum_called.get_py();
  total_momentum[3] = get_pz() - four_momentum_called.get_pz();

  return total_momentum;
}

double FourMomentum::dotProduct(const FourMomentum& four_momentum_called) const 
{
  // Sum the components of the four-momenta
  double dotted_momentum_0 = (get_E() * four_momentum_called.get_E());
  double dotted_momentum_1 = (get_px() * four_momentum_called.get_px());
  double dotted_momentum_2 = (get_py() * four_momentum_called.get_py());
  double dotted_momentum_3 = (get_pz() * four_momentum_called.get_pz());
  
  double dotted_momentum = dotted_momentum_0 - dotted_momentum_1 - dotted_momentum_2 - dotted_momentum_3;
  return dotted_momentum;
}

FourMomentum& FourMomentum::operator=(const FourMomentum &four_momentum_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&four_momentum_called == this)
  {
    return *this;
  } 
  // Assigns all data members from particle_called to current particle
  // Deep Copying implemented

  this->E = four_momentum_called.E;
  this->px = four_momentum_called.px;
  this->py = four_momentum_called.py;
  this->pz = four_momentum_called.pz;

  return *this;
}

FourMomentum::FourMomentum(const FourMomentum &four_momentum_called) 
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  {
    // Copies all data members from particle_called to current particle
    this->E = four_momentum_called.E;
    this->px = four_momentum_called.px;
    this->py = four_momentum_called.py;
    this->pz = four_momentum_called.pz;
  }
}

FourMomentum& FourMomentum::operator=(FourMomentum &&four_momentum_to_move)
{
  std::cout<<"Calling move assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &four_momentum_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  
  // Move the data members
  E = std::move(four_momentum_to_move.E);
  px = std::move(four_momentum_to_move.px);
  py = std::move(four_momentum_to_move.py);
  pz = std::move(four_momentum_to_move.pz);

  return *this;
}

FourMomentum::FourMomentum(FourMomentum &&four_momentum_to_move)
{
  std::cout<<"Calling Move Constructor"<<std::endl;
  {
    E = std::move(four_momentum_to_move.E);
    px = std::move(four_momentum_to_move.px);
    py = std::move(four_momentum_to_move.py);
    pz = std::move(four_momentum_to_move.pz);
  }
}
