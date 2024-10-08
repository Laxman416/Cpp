#include<iostream>
#include "ChargedLepton.h"

void ChargedLepton::set_charge(int particle_charge)
{
  // Checks if charge is -1 or +1
  // If any errors charge is not updated
  if(particle_charge != -1 && particle_charge != 1)
  {
    std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
    std::cerr<<"Error: Charge not updated."<<std::endl;
  } 
  else
  {
    charge = particle_charge;
  }
}

void ChargedLepton::print_data()
{
// // need to use getters from Lepton and Charged Lepton
std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
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
ChargedLepton& ChargedLepton::operator=(const ChargedLepton &charged_lepton_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&charged_lepton_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Lepton::operator=(charged_lepton_called);
  this->charge = charged_lepton_called.charge;

  return *this;
}

ChargedLepton::ChargedLepton(const ChargedLepton &charged_lepton_called) : Lepton(charged_lepton_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Check for self-copying
  if(this == &charged_lepton_called)
  {
    std::cout<<"Self-copy detected in Copy Constructor. Skipping copy."<<std::endl;
    return;
  }
  else
  {
    // Copies all data members from lepton_called to current particle

    this->charge = charged_lepton_called.charge;
  }
}

ChargedLepton& ChargedLepton::operator=(ChargedLepton &&charged_lepton_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &charged_lepton_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Lepton::operator=(std::move(charged_lepton_called_to_move));
    charge = std::move(charged_lepton_called_to_move.charge);
  }
    
  return *this;
}

ChargedLepton::ChargedLepton(ChargedLepton &&charged_lepton_called_to_move) : Lepton(std::move(charged_lepton_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  // Check for self-moving
  if(this == &charged_lepton_called_to_move)
  {
    std::cout<<"Self-move detected in Move Constructor. Skipping move."<<std::endl;
    return;
  }
  else
  {
    // Move the data members
    charge = std::move(charged_lepton_called_to_move.charge);

  }
}
