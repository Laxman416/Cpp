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

void  ChargedLepton::print_data()
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