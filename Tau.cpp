// PHYS 30762 Programming in C++
// Assignment 5
// Tau Class implementation

#include<iostream>
#include "Tau.h"
#include<random>
#include<ctime>
#include "Electron.h"
#include "Muon.h"
#include "Neutrino.h"
#include "Quark.h"

// Function to generate a random quark color singlet
std::pair<std::string, std::string> Tau::generateRandomQuarkColor() 
{
  // Define a vector of possible pair of quark colors
  std::vector<std::pair<std::string, std::string>> quark_colors = {{"red", "antired"}, {"green", "antigreen"}, {"blue", "antiblue"}};

  // Seed the random number generator
  std::srand(std::time(0));
  // Generate a random index to select a quark color
  int randomIndex = std::rand() % quark_colors.size();

  // Return the randomly selected quark color
  return quark_colors[randomIndex];
}

void Tau::print_data() const
{
  // // need to use getters from Lepton and Charged Lepton
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tThe particle "<<(m_is_decay_leptonic ? "decays" : "does not decay")<<" leptonically."<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an anitparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
  std::cout<<"\tLepton Number: "<<(this->get_lepton_number())<<std::endl;
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
    std::cout<<"Decayed "<<(m_is_antiparticle ? "Positron":"Electron")<<" of "<<this->get_name()<<" :"<<std::endl;
    m_decayed_electron_ptr->print_data();
    m_decayed_neutrino_ptr->print_data();
    m_decayed_tau_neutrino_ptr->print_data();
  }
  else if(m_decayed_muon_ptr != nullptr)
  {
    std::cout<<"Decayed "<<(m_is_antiparticle ? "Antimuon":"Muon")<<" of "<<this->get_name()<<" :"<<std::endl;
    m_decayed_muon_ptr->print_data();
    m_decayed_neutrino_ptr->print_data();
    m_decayed_tau_neutrino_ptr->print_data();
  }
  else 
  {
    std::cout<<"Decayed "<<(m_is_antiparticle ? "pi^+" : "pi^⁻")<<" of "<<this->get_name()<<" :"<<std::endl;
    m_decayed_up_quark_ptr->print_data();
    m_decayed_down_quark_ptr->print_data();
    m_decayed_tau_neutrino_ptr->print_data();
  }
}

const bool Tau::determine_decay_leptonic()
{
  // Ratio of Branching Fraction of tau to hadronic or leptonic approx equal to 0.649
  srand(time(0)); // creates a seed for rand()
  int random_number = rand() % 1001; // creates a number between 0 and 1000
  bool is_decay_leptonic;
  if(random_number < 649)
    {
      is_decay_leptonic = false;
    }
  else
  {
    is_decay_leptonic = true;
  }
  return is_decay_leptonic;
}

void Tau::decay_tau_leptonically()
{
  // Ratio of Branching Fraction of tau to electron or muon approx equal to 0.506
  // Creates a Lepton: muon or electron depending on branching ratios
  std::cout<<"\033[1;32mCreating "<<(this->get_is_antiparticle() ? "positron/antimuon":"electron/muon")<<" the "<<this->get_name()<<" decays to using the branching fractions.\033[0m"<<std::endl;
  // Random number generator 
  srand(time(0)); // creates a seed for rand()
  // set seed to time(0): time since 1970
  int random_number = rand() % 1001; // creates a number between 0 and 1000
  if(random_number < 506)
  {
    // Decays to electron
    m_is_decay_to_electrons = true;
    std::cout<<"\033[1;32m"<<this->get_name()<<" decays to "<<(this->get_is_antiparticle() ? "Positron":"Electron")<<"\033[0m"<<std::endl;
    m_decayed_electron_ptr = std::make_unique<Electron>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0);
    m_decayed_neutrino_ptr = std::make_unique<Neutrino>((this->get_is_antiparticle() ? 0:1), 2 ,1.0, 1.0, 0.0, false, 1); // 0:1 to conserve flavour
    m_decayed_tau_neutrino_ptr = std::make_unique<Neutrino>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, false, 3); // 0:1 to conserve flavour

  }
  else
  {
    // Decays to muons
    m_is_decay_to_electrons = false;
    std::cout<<"\033[1;32m"<<this->get_name()<<" decays to "<<(this->get_is_antiparticle() ? "Antimuon":"Muon")<<"\033[0m"<<std::endl;      
    m_decayed_muon_ptr = std::make_unique<Muon>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, false);
    m_decayed_neutrino_ptr = std::make_unique<Neutrino>((this->get_is_antiparticle() ? 0:1), 2 ,1.0, 1.0, 0.0, false, 2); // 0:1 to conserve flavour
    m_decayed_tau_neutrino_ptr = std::make_unique<Neutrino>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, false, 3); // 0:1 to conserve flavour
  }
}

void Tau::decay_tau_hadronically()
{
  // Assuming all decays to pions (ud). Not true in real life as other process contribute a significate amount.
  // Need to conserve charge: so tau- decays to pi- and antitau decays to pi+.
  // Colour of quarks depends of 
  std::pair<std::string, std::string>  colour_of_quarks = generateRandomQuarkColor(); // To get colour singlet pion
  m_decayed_up_quark_ptr = std::make_unique<Quark>((this->get_is_antiparticle() ? 0:1), 2 ,1.0, 1.0, 0.0, 1, (this->get_is_antiparticle() ? colour_of_quarks.first:colour_of_quarks.second), true); // 0:1 conserves charge as creates u for antitau
  m_decayed_down_quark_ptr = std::make_unique<Quark>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, 1, (this->get_is_antiparticle() ? colour_of_quarks.second:colour_of_quarks.first) , false); 
  m_decayed_tau_neutrino_ptr = std::make_unique<Neutrino>((this->get_is_antiparticle() ? 1:0), 2 ,1.0, 1.0, 0.0, false, 3); // 1:0 to conserve flavour
}

void Tau::decay_tau() 
{
  // Random # Generator will allow to favour the electron more in the random decay
  if(m_is_decay_leptonic)
  {
    decay_tau_leptonically();
  }
  else
  {
   decay_tau_hadronically(); 
  }
}

const std::unique_ptr<Electron>& Tau::get_decayed_electron_ptr() const
{
  if(m_decayed_electron_ptr != nullptr) 
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
  if(m_decayed_muon_ptr != nullptr) 
  {
    return m_decayed_muon_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed particle pointer is null");
  }
}

const void Tau::get_decayed_lepton_ptr() const
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

const std::unique_ptr<Neutrino>& Tau::get_decayed_lepton_neutrino_ptr() const
{
  if(m_decayed_neutrino_ptr != nullptr) 
  {
    return m_decayed_neutrino_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed neutrino pointer is null");
  }
}

const std::unique_ptr<Neutrino>& Tau::get_decayed_tau_neutrino_ptr() const
{
  if(m_decayed_tau_neutrino_ptr != nullptr) 
  {
    return m_decayed_tau_neutrino_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed tau neutrino pointer is null");
  }
}

const std::unique_ptr<Quark>& Tau::get_decayed_up_quark_ptr() const
{
  if(m_decayed_up_quark_ptr != nullptr) 
  {
    return m_decayed_up_quark_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed up quark pointer is null");
  }
}

const std::unique_ptr<Quark>& Tau::get_decayed_down_quark_ptr() const
{
  if(m_decayed_down_quark_ptr != nullptr) 
  {
    return m_decayed_down_quark_ptr;
  } 
  else 
  {
    throw std::runtime_error("Decayed down quark pointer is null");
  }
}

void Tau::set_charge(int particle_charge)
{
  // Particle mass can't be changed in tau
  std::cerr<<"\033[1;31mError\033[0m: Tau has a charge and cannot be changed."<<std::endl;
  std::cerr<<"Modify the m_is_antiparticle data member if u want to change to tau to its antipariticle or vice versa."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Charge of particle not updated."<<std::endl;    
}

void Tau::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in tau
  std::cerr<<"\033[1;31mError\033[0m: Tau has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Tau::set_name(std::string particle_name)
{
  // Particle mass can't be changed in tau
  std::cerr<<"\033[1;31mError\033[0m: Tau particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

void Tau::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"\033[1;31mError\033[0m: Tau is already in desired state."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->charge = m_is_antiparticle ? -1:1;
    this->name = m_is_antiparticle ? "Antitau":"Tau";
    this->lepton_number = m_is_antiparticle ? -1:1;
    std::cerr<<"Particle updated. The name, charge and boolean data members are modified."<<std::endl;    
  }
}

// Assignment Constructor to do Deep Copying
Tau& Tau::operator=(const Tau &tau_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&tau_called == this)
  {
    return *this;
  } 
  // Assigns all data members from tau_called to current particle
  // Deep Copying implemented
  Lepton::operator=(tau_called);
  this->m_is_decay_leptonic = tau_called.m_is_decay_leptonic;
  this->m_is_decay_to_electrons = tau_called.m_is_decay_to_electrons;

  if(m_decayed_down_quark_ptr){ this->m_decayed_down_quark_ptr = std::make_unique<Quark>(*tau_called.m_decayed_down_quark_ptr);}
  if(m_decayed_electron_ptr){ this->m_decayed_electron_ptr = std::make_unique<Electron>(*tau_called.m_decayed_electron_ptr);}
  if(m_decayed_muon_ptr){ this->m_decayed_muon_ptr = std::make_unique<Muon>(*tau_called.m_decayed_muon_ptr);}
  if(m_decayed_neutrino_ptr){ this->m_decayed_neutrino_ptr = std::make_unique<Neutrino>(*tau_called.m_decayed_neutrino_ptr);}
  if(m_decayed_tau_neutrino_ptr){ this->m_decayed_tau_neutrino_ptr = std::make_unique<Neutrino>(*tau_called.m_decayed_tau_neutrino_ptr);}
  if(m_decayed_up_quark_ptr){ this->m_decayed_up_quark_ptr = std::make_unique<Quark>(*tau_called.m_decayed_up_quark_ptr);}

  return *this;
}

Tau::Tau(const Tau &tau_called) : Lepton(tau_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle

  this->m_is_decay_leptonic = tau_called.m_is_decay_leptonic;
  this->m_is_decay_to_electrons = tau_called.m_is_decay_to_electrons;

  if(m_decayed_down_quark_ptr){ this->m_decayed_down_quark_ptr = std::make_unique<Quark>(*tau_called.m_decayed_down_quark_ptr);}
  if(m_decayed_electron_ptr){ this->m_decayed_electron_ptr = std::make_unique<Electron>(*tau_called.m_decayed_electron_ptr);}
  if(m_decayed_muon_ptr){ this->m_decayed_muon_ptr = std::make_unique<Muon>(*tau_called.m_decayed_muon_ptr);}
  if(m_decayed_neutrino_ptr){ this->m_decayed_neutrino_ptr = std::make_unique<Neutrino>(*tau_called.m_decayed_neutrino_ptr);}
  if(m_decayed_tau_neutrino_ptr){ this->m_decayed_tau_neutrino_ptr = std::make_unique<Neutrino>(*tau_called.m_decayed_tau_neutrino_ptr);}
  if(m_decayed_up_quark_ptr){ this->m_decayed_up_quark_ptr = std::make_unique<Quark>(*tau_called.m_decayed_up_quark_ptr);}
}

Tau& Tau::operator=(Tau &&tau_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &tau_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Lepton::operator=(std::move(tau_called_to_move));

    m_is_decay_leptonic = std::move(tau_called_to_move.m_is_antiparticle);
    m_is_decay_to_electrons = std::move(tau_called_to_move.m_is_antiparticle);

    if(m_decayed_down_quark_ptr){m_decayed_down_quark_ptr = std::move(tau_called_to_move.m_decayed_down_quark_ptr);}
    if(m_decayed_electron_ptr){m_decayed_electron_ptr = std::move(tau_called_to_move.m_decayed_electron_ptr);}
    if(m_decayed_muon_ptr){m_decayed_muon_ptr = std::move(tau_called_to_move.m_decayed_muon_ptr);}
    if(m_decayed_neutrino_ptr){m_decayed_neutrino_ptr = std::move(tau_called_to_move.m_decayed_neutrino_ptr);}
    if(m_decayed_tau_neutrino_ptr){m_decayed_tau_neutrino_ptr = std::move(tau_called_to_move.m_decayed_tau_neutrino_ptr);}
    if(m_decayed_up_quark_ptr){m_decayed_up_quark_ptr = std::move(tau_called_to_move.m_decayed_up_quark_ptr);}
  }
    
  return *this;
}

Tau::Tau(Tau &&tau_called_to_move) : Lepton(std::move(tau_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  m_is_decay_leptonic = std::move(tau_called_to_move.m_is_antiparticle);
  m_is_decay_to_electrons = std::move(tau_called_to_move.m_is_antiparticle);

  if(m_decayed_down_quark_ptr){m_decayed_down_quark_ptr = std::move(tau_called_to_move.m_decayed_down_quark_ptr);}
  if(m_decayed_electron_ptr){m_decayed_electron_ptr = std::move(tau_called_to_move.m_decayed_electron_ptr);}
  if(m_decayed_muon_ptr){m_decayed_muon_ptr = std::move(tau_called_to_move.m_decayed_muon_ptr);}
  if(m_decayed_neutrino_ptr){m_decayed_neutrino_ptr = std::move(tau_called_to_move.m_decayed_neutrino_ptr);}
  if(m_decayed_tau_neutrino_ptr){m_decayed_tau_neutrino_ptr = std::move(tau_called_to_move.m_decayed_tau_neutrino_ptr);}
  if(m_decayed_up_quark_ptr){m_decayed_up_quark_ptr = std::move(tau_called_to_move.m_decayed_up_quark_ptr);}
}



