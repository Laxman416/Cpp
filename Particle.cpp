#include "Particle.h"
#include<iostream>

std::vector<double> operator+(const Particle& particle_called_1, const Particle& particle_called_2)
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector
  // // Sum the components of the four-momenta
  total_momentum[0] = particle_called_1.get_four_momentum_ptr()->get_E() + particle_called_2.get_four_momentum_ptr()->get_E();
  total_momentum[1] = particle_called_1.get_four_momentum_ptr()->get_px() + particle_called_2.get_four_momentum_ptr()->get_px();
  total_momentum[2] = particle_called_1.get_four_momentum_ptr()->get_py() + particle_called_2.get_four_momentum_ptr()->get_py();
  total_momentum[3] = particle_called_1.get_four_momentum_ptr()->get_pz() + particle_called_2.get_four_momentum_ptr()->get_pz();

  return total_momentum;
}

std::vector<double> operator-(const Particle& particle_called_1, const Particle& particle_called_2)
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector
  // // Subtract the components of the four-momenta
  total_momentum[0] = particle_called_1.get_four_momentum_ptr()->get_E() - particle_called_2.get_four_momentum_ptr()->get_E();
  total_momentum[1] = particle_called_1.get_four_momentum_ptr()->get_px() - particle_called_2.get_four_momentum_ptr()->get_px();
  total_momentum[2] = particle_called_1.get_four_momentum_ptr()->get_py() - particle_called_2.get_four_momentum_ptr()->get_py();
  total_momentum[3] = particle_called_1.get_four_momentum_ptr()->get_pz() - particle_called_2.get_four_momentum_ptr()->get_pz();

  return total_momentum;
}

double dotProduct(const Particle& particle_called_1, const Particle& particle_called_2) 
{

  // Sum the components of the four-momenta
  double dotted_momentum_0 = particle_called_1.get_four_momentum_ptr()->get_E() * particle_called_2.get_four_momentum_ptr()->get_E();
  double dotted_momentum_1 = (particle_called_1.get_four_momentum_ptr()->get_px() * particle_called_2.get_four_momentum_ptr()->get_px());
  double dotted_momentum_2 = (particle_called_1.get_four_momentum_ptr()->get_py() * particle_called_2.get_four_momentum_ptr()->get_py());
  double dotted_momentum_3 = (particle_called_1.get_four_momentum_ptr()->get_pz() * particle_called_2.get_four_momentum_ptr()->get_pz());
  
  double dotted_momentum = dotted_momentum_0 - dotted_momentum_1 - dotted_momentum_2 - dotted_momentum_3;
  return dotted_momentum;
}

void Particle::verify_input(bool is_antiparticle)
{
  if(is_antiparticle != true && is_antiparticle != false)
  {
    std::cout<<"Warning: Invalid value for 'is_antiparticle' parameter. Defaulting to false."<<std::endl;
    is_antiparticle = false;
  }
}

void Particle::set_rest_mass(double particle_mass)
{
  // particle mass must be positive
  if(particle_mass < 0)
  {
    std::cerr<<"\033[1;31mError\033[0m: Invalid value for rest mass. Mass must be positive."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
  }
  else
  {
    // Check if the FourMomentum object exists
    if(four_momentum_ptr != nullptr)
    {
      // Verify energy using new particle mass
      four_momentum_ptr->verify_energy(four_momentum_ptr->get_E(), four_momentum_ptr->get_px(), four_momentum_ptr->get_py(), four_momentum_ptr->get_pz(), particle_mass);
    }
    rest_mass = particle_mass;
  }
}

// Assignment Constructor to do Deep Copying
Particle& Particle::operator=(const Particle &particle_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&particle_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented

  this->name = particle_called.name;
  this->spin = particle_called.spin;
  this->charge = particle_called.spin;
  this->rest_mass = particle_called.rest_mass;
  this->m_is_antiparticle = particle_called.m_is_antiparticle;
  this->four_momentum_ptr = std::make_unique<FourMomentum>(*particle_called.four_momentum_ptr);

  return *this;
}

Particle::Particle(const Particle &particle_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  {
    // Copies all data members from lepton_called to current particle
    this->name = particle_called.name;
    this->spin = particle_called.spin;
    this->charge = particle_called.spin;
    this->rest_mass = particle_called.rest_mass;
    this->m_is_antiparticle = particle_called.m_is_antiparticle;
    this->four_momentum_ptr = std::make_unique<FourMomentum>(*particle_called.four_momentum_ptr);
  }
}

Particle& Particle::operator=(Particle &&particle_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &particle_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  // Move the data members
  charge = std::move(particle_called_to_move.charge);
  spin = std::move(particle_called_to_move.spin);
  name = std::move(particle_called_to_move.name);
  rest_mass = std::move(particle_called_to_move.rest_mass);
  m_is_antiparticle = std::move(particle_called_to_move.m_is_antiparticle);
  four_momentum_ptr = std::move(particle_called_to_move.four_momentum_ptr);
  
  return *this;
}

Particle::Particle(Particle &&particle_called_to_move)
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  {
    // Move the data members
    charge = std::move(particle_called_to_move.charge);
    spin = std::move(particle_called_to_move.spin);
    name = std::move(particle_called_to_move.name);
    rest_mass = std::move(particle_called_to_move.rest_mass);
    m_is_antiparticle = std::move(particle_called_to_move.m_is_antiparticle);
    four_momentum_ptr = std::move(particle_called_to_move.four_momentum_ptr);
  }
}


