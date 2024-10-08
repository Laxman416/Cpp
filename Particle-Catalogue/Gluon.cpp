#include<iostream>
#include<string>
#include "Gluon.h"
#include<random>
#include<ctime>

void Gluon::print_data() const
{
  // // need to use getters from Particle
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tCharge is: "<<colour_charge.first<<" and "<<colour_charge.second<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an anitparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
  std::cout<<"\tBoson is associated with the : "<<(this->get_associated_force())<<" Force"<<std::endl;

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


std::pair<std::string,std::string> Gluon::determine_gluon_colour_charge()
{
  // Define a vector of possible pair of quark colors
  // Total 8 gluons in QCD: I have only implemented 6
  std::vector<std::pair<std::string, std::string>> quark_colors = 
              {{"red", "antigreen"}, 
              {"red", "antinlue"}, 
              {"antired", "green"},
              {"antired", "blue"},
              {"green", "antiblue"},
              {"antigreen", "green"},
              };

  // Seed the random number generator
  std::srand(std::time(0));
  // Generate a random index to select a quark color
  int randomIndex = std::rand() % quark_colors.size();

  // Return the randomly selected quark color
  return quark_colors[randomIndex];
}

void Gluon::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Gluon::set_name(std::string particle_name)
{
  // Particle name can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

// Assignment Constructor to do Deep Copying
Gluon& Gluon::operator=(const Gluon &gluon_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&gluon_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Boson::operator=(gluon_called);
  this->colour_charge = gluon_called.colour_charge;


  return *this;
}

Gluon::Gluon(const Gluon &gluon_called) : Boson(gluon_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from gluon to current particle
    this->colour_charge = gluon_called.colour_charge;

}

Gluon& Gluon::operator=(Gluon &&gluon_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &gluon_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Boson::operator=(std::move(gluon_called_to_move));
    colour_charge = std::move(gluon_called_to_move.colour_charge);
  }
    
  return *this;
}

Gluon::Gluon(Gluon &&gluon_called_to_move) : Boson(std::move(gluon_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;
  colour_charge = std::move(gluon_called_to_move.colour_charge);

}

