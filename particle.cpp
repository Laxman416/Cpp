// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "particle.h"


// Implementation of print_data function

void particle::verify_input(std::string particle_type, double particle_mass, int particle_charge, double particle_velocity) 
{
  // Loop to validate particle mass
  if (particle_mass < 0)
  {
    std::cerr << "Error: Invalid mass given, mass must be positive." << std::endl;
    std::cerr << "Setting mass to 0." << std::endl;
    rest_mass = 0;
  }

  // Loop to validate particle type
  if (particle_type == "electron" || particle_type == "muon") 
  {
    is_antiparticle = false;
    type = particle_type;
  } 
  else if (particle_type == "positron" || particle_type == "antimuon") 
  {
    is_antiparticle = true;
    type = particle_type;
  } 
  else 
  {
    std::cerr << "Error: Invalid lepton type given. Lepton set to be electron" << std::endl;
    type = "electron";
    is_antiparticle = false;
  }

  // Loop to validate particle velocity
  if (particle_velocity < 0 || particle_velocity > light_speed) 
  {
    std::cerr << "Error: Velocity must be between 0 and the speed of light." << std::endl;
    std::cerr << "Setting velocity and beta to be 0." << std::endl;
    velocity = 0.0;
    beta = 0.0;
  }

  // Loop to validate particle charge
  if (particle_charge != -1 && particle_charge != 1) 
  {
    std::cerr << "Error: Charge must be either -1 or 1." << std::endl;
    if (!is_antiparticle) 
    {
      std::cerr << "Charge of " << type << " set to -1." << std::endl;
      charge = -1;
    } 
    else 
    {
      std::cerr << "Charge of " << type << " set to +1." << std::endl;
      charge = 1;
    }
  } 
  else if (!is_antiparticle && particle_charge != -1) 
  {
    std::cerr << "Error: Invalid charge for " << type << ". Charge must be -1." << std::endl;
    std::cerr << "Setting charge = -1." << std::endl;
    charge = -1;
  } 
  else if (is_antiparticle && particle_charge != 1) 
  {
    std::cerr << "Error: Invalid charge for " << type << ". Charge must be 1." << std::endl;
    std::cerr << "Setting charge = +1." << std::endl;
    charge = 1;
  }
}

void particle::print_data() const
{
  std::cout<<"Particle Type: "<<type<<std::endl;
  std::cout<<"Rest Mass: "<<rest_mass<<" MeV"<<std::endl;
  std::cout<<"Charge: "<<charge<<std::endl;
  std::cout<<"Velocity: "<<velocity<<" m/s"<<std::endl;
  std::cout<<"Beta: "<<beta<<std::endl;
}

// Function to set charge with logical checks
void particle::set_charge(int particle_charge)
{
  if (particle_charge != -1 && particle_charge != 1)
  {
    std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
    std::cerr<<"Error: Charge not updated."<<std::endl;
  } 
  else if (is_antiparticle = false && particle_charge != -1) 
  {
  std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
  std::cerr<<"Error: Charge not updated. Reset type of particle if it is incorrect"<<std::endl;
  } 
  else if (is_antiparticle = true && particle_charge != 1)
  { 
    std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
    std::cerr<<"Error: Charge not updated. Reset type of particle if it is incorrect."<<std::endl;
  }
  else
  {
    charge = particle_charge;
  }
}

// Function to set type with logical checks
void particle::set_type(std::string particle_type)
{
  // Don't want to rewrite original data member without checking charge of the atom.
  bool is_antiparticle_check; 
  if (particle_type == "electron" || particle_type == "muon")
  {
    is_antiparticle_check = false;
  }
  else if (particle_type == "positron" || particle_type == "antimuon")
  {
    is_antiparticle_check = true;
  }
  else
  {
    std::cerr<<"Error: Invalid lepton type given."<<std::endl;
    std::cerr<<"Error: Lepton type not updated."<<std::endl;
    return; // returns from function if invalid lepton type given
  }
  if (is_antiparticle_check == false && charge != -1)
  {
    std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
    std::cerr<<"Error: Type of particle not updated. Reset charge of particle if it is incorrect"<<std::endl;
  }
  else if (is_antiparticle_check == true && charge != 1)
  { 
    std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
    std::cerr<<"Error: Type of particle not updated. Reset charge of particle if it is incorrect."<<std::endl;
  }  
  else
  {
    type = particle_type;
    is_antiparticle = is_antiparticle_check;
  }
}

// Function to set velocity with logical checks, also updates beta.
void particle::set_velocity(double particle_velocity)
{
  if (particle_velocity<0 || particle_velocity > light_speed)
  {
    std::cerr<<"Error: Velocity must be between 0 and the speed of light."<<std::endl;
    std::cout<<"Error: Velocity of paritcle not updated"<<std::endl;
  }
  else
  {
    velocity = particle_velocity;
    beta = particle_velocity/light_speed;
    std::cout<<type<<"'s velocity and beta updated"<<std::endl;
  }
}

void particle::set_beta(double particle_beta)
{
  if (particle_beta < 0 || particle_beta > 1)
  {
    std::cerr<<"Error: Beta must be between 0 and 1."<<std::endl;
    std::cerr<<"Error: Beta of paritcle not updated"<<std::endl;
  }
  else
  {
    beta = particle_beta;
    velocity = beta * light_speed;
    std::cout<<type<<"'s velocity and beta updated"<<std::endl;
  }
}

void particle::set_rest_mass(double particle_mass)
{
  if (particle_mass < 0)
  {
    std::cerr<<"Error: Invalid value for rest mass. Mass must be positive."<<std::endl;
    std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
  }
  else
  {
    rest_mass = particle_mass;
  }
}

// End of particle class and associated member functions

// Beginning of detector class

// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// - write a function that takes a particle 
//   and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type
// - write a function (accessor) that prints how many particles passed through this detector

// End of detector class


