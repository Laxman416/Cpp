// PHYS 30762 Programming in C++
// Assignment 5
// Practice with C++ classes and their interactions
// Implementation of four_momentum class

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "FourMomentum.h"

void FourMomentum::verify_energy(double particle_energy, double particle_px, double particle_py, double particle_pz, double particle_mass) 
{
  double invariant_mass = get_invariant_mass_from_four_momentum();
  
  if(std::abs(invariant_mass - particle_mass) > 1e-6 || E * E < (particle_px * particle_px + particle_py * particle_py + particle_pz * particle_pz))
    {
      if(std::abs(invariant_mass - particle_mass) > 1e-6)
      {
        std::cerr<<"\033[1;31mError\033[0m:  Inconsistent invariant mass and particle mass."<<std::endl;
      } 
      else
      {
        std::cerr<<"\033[1;31mError\033[0m:  Inconsistent momentum and energy as invariant mass is an imaginary number."<<std::endl;
      }
      std::cout<<"\tModifying four momentum to be valid"<<std::endl;
      std::cout<<"\tAssuming momentum correct and modifying Energy."<<std::endl;
   
      // Calculate E using rest mass of particle: E^2 = m^2 + (pc)^2
      double scaled_energy = std::sqrt(particle_mass * particle_mass + particle_px * particle_px + particle_py * particle_py + particle_pz * particle_pz);

      E = scaled_energy;
      px = particle_px;  
      py = particle_py;
      pz = particle_pz;
      rest_mass = particle_mass;
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

void FourMomentum::set_E(double E)
{
  // Verify energy and sets it
  verify_energy(E, this->get_px(), this->get_py(), this->get_pz(), rest_mass);
}

void FourMomentum::set_px(double particle_px)
{
  // Verify energy using new particle_px and sets it
  verify_energy(this->get_E(), particle_px, this->get_py(), this->get_pz(), rest_mass);
}

void FourMomentum::set_py(double particle_py)
{
  // Verify energy using new particle_py and sets it
  verify_energy(this->get_E(), this->get_px(), particle_py, this->get_pz(), rest_mass);
  py = particle_py;
}

void FourMomentum::set_pz(double particle_pz)
{
  // Verify energy using new particle_py and sets it
  verify_energy(this->get_E(), this->get_px(), this->get_py(), particle_pz, rest_mass);
  pz = particle_pz;
}

void FourMomentum::set_rest_mass(double particle_mass)
{
  // Only modify if not associated with a Particle object
  if(m_is_particle == false)
  {
    // Verify energy using new particle mass and sets it
    verify_energy(this->get_E(), this->get_px(), this->get_py(), this->get_pz(), particle_mass);
    rest_mass = particle_mass;
  }
  else
  {
    std::cerr<<"\033[1;31mError\033[0m: Cannot modify rest_mass when FourMomentum is associated with a Particle object."<<std::endl;
  }
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
