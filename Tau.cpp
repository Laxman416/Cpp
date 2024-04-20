// PHYS 30762 Programming in C++
// Assignment 5
// Tau Class implementation

#include<iostream>
#include "Tau.h"
#include<random>
#include<ctime>
#include "Electron.h"
#include "Muon.h"

void Tau::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tThe particle "<<(m_is_decay_leptonic ? "decays" : "does not decay")<<" leptonically."<<std::endl;
  // Call print_data() function on the four_momentum_ptr object
  if(four_momentum_ptr != nullptr) 
  {
    four_momentum_ptr->print_data();
  } 
  else 
  {
    std::cout<<"Four Momentum Data not available"<<std::endl;
  }
  if(m_decayed_electron_ptr != nullptr)
  {
    std::cout<<"Decayed "<<(is_antiparticle ? "Positron":"Electron")<<" of "<<this->get_name()<<" :"<<std::endl;
    m_decayed_electron_ptr->print_data();
  }
  else if(m_decayed_muon_ptr != nullptr)
  {
    std::cout<<"Decayed "<<(is_antiparticle ? "Antimuon":"Muon")<<" of "<<this->get_name()<<" :"<<std::endl;
    m_decayed_muon_ptr->print_data();
  }
  else 
  {
    std::cout<<"Decay Particle Data not available"<<std::endl;
  }
}

void Tau::decay_tau() 
{
  // Branching Fraction of tau to electron or muon approx equal to 0.506
  // Random # Generator will allow to favour the electron more in the random decay
  srand(time(0)); // creates a seed for rand()
  if(m_is_decay_leptonic)
  {
    // Creates a ChargedLepton
    std::cout<<"\033[1;32mCreating "<<(this->get_is_antiparticle() ? "positron/antimuon":"electron/muon")<<" the "<<this->get_name()<<" decays to using the branching fractions.\033[0m"<<std::endl;
    // Random number generator 
    // set seed to time(0): time since 1970
    int random_number = rand() % 1001; // creates a number between 0 and 100
    if(random_number < 506)
    {
      // Decays to electron
      m_is_decay_to_electrons = true;
      std::cout<<"\033[1;32m"<<this->get_name()<<" decays to "<<(this->get_is_antiparticle() ? "AntiMuon":"Muon")<<"\033[0m"<<std::endl;
      m_decayed_electron_ptr = std::make_unique<Electron>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0);
    }
    else
    {
      // Decays to muons
      m_is_decay_to_electrons = false;
      std::cout<<"\033[1;32m"<<this->get_name()<<" decays to "<<(this->get_is_antiparticle() ? "Positron":"Electron")<<"\033[0m"<<std::endl;      
      m_decayed_muon_ptr = std::make_unique<Muon>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, false);
    }
  }
}

const std::unique_ptr<Electron>& Tau::get_decayed_electron_ptr() const
{
  if (m_decayed_electron_ptr != nullptr) 
  {
    return m_decayed_electron_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed particle pointer is null");
  }
}

const std::unique_ptr<Muon>& Tau::get_decayed_muon_ptr() const
{
  if (m_decayed_muon_ptr != nullptr) 
  {
    return m_decayed_muon_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed particle pointer is null");
  }
}

const void Tau::get_decayed_particle_ptr() const
{
  if(m_is_decay_to_electrons)
  {
    get_decayed_electron_ptr();
  }
  else
  {
    get_decayed_muon_ptr();
  }
}

void Tau::set_charge(int particle_charge)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau has a charge and cannot be changed."<<std::endl;
  std::cerr<<"Modify the is_antiparticle data member if u want to change to tau to its antipariticle or vice versa."<<std::endl;
  std::cerr<<"Error: Charge of particle not updated."<<std::endl;    
}

void Tau::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with mass that can be modified"<<std::endl;
  std::cerr<<"Error: Rest mass of particle not updated."<<std::endl;    
}

void Tau::set_name(std::string particle_name)
{
  // Particle mass can't be changed in tau
  std::cerr<<"Error: Tau particle can not be changed."<<std::endl;
  std::cerr<<"Create a ChargedLepton object if u want an object with a name that can be modified"<<std::endl;
  std::cerr<<"Error: Name of particle not updated."<<std::endl;    
}

void Tau::set_is_antiparticle(bool isAntiparticle)
{
  if(this->is_antiparticle == isAntiparticle)
  {
    std::cerr<<"Error: Tau is already in desired state."<<std::endl;
    std::cerr<<"Error: Particle not updated."<<std::endl;    
  }
  else
  {
    this->is_antiparticle = isAntiparticle;
    this->charge = is_antiparticle ? -1:1;
    this->name = is_antiparticle ? "Antitau":"Tau";
    std::cerr<<"Particle updated. The name, charge and boolean data members are modified."<<std::endl;    
  }
}
