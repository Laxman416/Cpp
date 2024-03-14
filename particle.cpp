// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "particle.h"

// Loop to veriy input of parameterised constructor
void particle::verify_input(std::string particle_type, double particle_mass, int particle_charge, std::vector<double>* particle_four_momentum) 
{
  // Loop to validate the four momentum energy
  if((*particle_four_momentum)[0] >= 0 && (*particle_four_momentum)[0] <= 1) 
  {
    four_momentum = particle_four_momentum;
  } 
  else 
  {
    std::cerr<<"Error: Invalid four momentum given. E must be positive and less than the speed of light. "<<std::endl;
    std::cerr<<"Setting the energy to 0."<<std::endl;
    (*particle_four_momentum)[0] = 0;
    four_momentum = particle_four_momentum;
  }
  // Loop to validate particle mass
  if(particle_mass < 0)
  {
    std::cerr<<"Error: Invalid mass given, mass must be positive."<<std::endl;
    std::cerr<<"Setting mass to 0."<<std::endl;
    rest_mass = 0;
  }

  // Loop to validate particle type
  if(particle_type == "electron" || particle_type == "muon") 
  {
    is_antiparticle = false;
    type = particle_type;
  } 
  else if(particle_type == "positron" || particle_type == "antimuon") 
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

  // Loop to validate particle charge
  if(particle_charge != -1 && particle_charge != 1) 
  {
    std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
    if(!is_antiparticle) 
    {
      std::cerr<<"Charge of " << type << " set to -1."<<std::endl;
      charge = -1;
    } 
    else 
    {
      std::cerr<<"Charge of " << type << " set to +1."<<std::endl;
      charge = 1;
    }
  } 
  else if(!is_antiparticle && particle_charge != -1) 
  {
    std::cerr<<"Error: Invalid charge for "<<type<<". Charge must be -1."<<std::endl;
    std::cerr<<"Setting charge = -1." << std::endl;
    charge = -1;
  } 
  else if(is_antiparticle && particle_charge != 1) 
  {
    std::cerr<< "Error: Invalid charge for "<<type<<". Charge must be 1."<<std::endl;
    std::cerr<< "Setting charge = +1."<<std::endl;
    charge = 1;
  }
}

void particle::print_data() const
{
  // Prints the data
  std::cout<<"Particle Type: "<<type<<std::endl;
  std::cout<<"Rest Mass: "<<rest_mass<<" MeV"<<std::endl;
  std::cout<<"Charge: "<<charge<<std::endl;
  std::cout<<"Four Momentum: [P = (E/c, px, py, pz)]"<<std::endl;
  // for loop to iterate. size_t makes sure counter is non negative
  for(size_t i = 0; i < (*four_momentum).size(); ++i) 
  {
    std::cout<<P_index_names[i]<<": "<<(*four_momentum)[i]<<" MeV/c"<<std::endl;
  }
  std::cout<<""<<std::endl;
}

// Function to set charge with logical checks
void particle::set_charge(int particle_charge)
{
  // Checks if charge is -1 or +1
  // Checks if particle charge must be - 1
  // Checks if antiparticle charge must be + 1
  // If any errors charge is not updated
  if(particle_charge != -1 && particle_charge != 1)
  {
    std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
    std::cerr<<"Error: Charge not updated."<<std::endl;
  } 
  else if(is_antiparticle = false && particle_charge != -1) 
  {
  std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
  std::cerr<<"Error: Charge not updated. Reset type of particle if it is incorrect"<<std::endl;
  } 
  else if(is_antiparticle = true && particle_charge != 1)
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
  // Checks if type is valid, if not returns from function
  // Checks if particle charge must be - 1
  // Checks if antiparticle charge must be + 1
  // If any errors, charge is updated as well
  if(particle_type == "electron" || particle_type == "muon")
  {
    is_antiparticle = false;
  }
  else if(particle_type == "positron" || particle_type == "antimuon")
  {
    is_antiparticle = true;
  }
  else
  {
    std::cerr<<"Error: Invalid lepton type given."<<std::endl;
    std::cerr<<"Error: Lepton type not updated."<<std::endl;
    return; // returns from function if invalid lepton type given
  }
  if(is_antiparticle == false && charge != -1)
  {
    std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
    std::cerr<<"Error: Type of particle is updated to "<<particle_type<<" and the charge is updated to -1"<<std::endl;
    type = particle_type;
    charge = -1;
  }
  else if(is_antiparticle == true && charge != 1)
  { 
    std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
    std::cerr<<"Error: Type of particle is updated to "<<particle_type<<" and the charge is updated to 1"<<std::endl;
    type = particle_type;
    charge = 1;
  }  
  else
  {
    type = particle_type;
  }
}

void particle::set_rest_mass(double particle_mass)
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

void particle::set_four_momentum(std::vector<double>* particle_four_momentum)
{
 // Verifying P before setting
if((*particle_four_momentum)[0] >= 0 && (*particle_four_momentum)[0] <= 1) 
 {
  (*four_momentum) = (*particle_four_momentum);
 }
 else
 {
  std::cerr<<"Error: Invalid four momentum given. E must be positive and less than the speed of light"<<std::endl;
  std::cerr<<"Four momentum of particle not updated."<<std::endl;
 }
}

std::vector<double> particle::operator+(const particle& particle_called) const 
{
  std::vector<double> total_momentum(4); // initialise total_momentum vector

  // Sum the components of the four-momenta
  total_momentum[0] = get_E() + particle_called.get_E();
  total_momentum[1] = get_px() + particle_called.get_px();
  total_momentum[2] = get_py() + particle_called.get_py();
  total_momentum[3] = get_pz() + particle_called.get_pz();

  return total_momentum;
}

double particle::dotProduct(const particle& particle_called) const 
{

  // Sum the components of the four-momenta
  double dotted_momentum_0 = get_E() * particle_called.get_E();
  double dotted_momentum_1 = (get_px() * particle_called.get_px());
  double dotted_momentum_2 = (get_py() * particle_called.get_py());
  double dotted_momentum_3 = (get_pz() * particle_called.get_pz());
  
  double dotted_momentum = dotted_momentum_0 - dotted_momentum_1 - dotted_momentum_2 - dotted_momentum_3;
  return dotted_momentum;
}

particle& particle::operator=(const particle &particle_called)
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
  else
  {
    // assigns all data members from particle_called to current particle
    this->type = particle_called.type;
    this->rest_mass = particle_called.rest_mass;
    this->charge = particle_called.charge;
    this->is_antiparticle = particle_called.is_antiparticle;
    this->P_index_names = particle_called.P_index_names;

    delete four_momentum; // Deallocate existing memory
    four_momentum = new std::vector<double>(*particle_called.four_momentum);
  }

  return *this;

}


