#include<iostream>
#include<string>
#include "Weak.h"
#include "Particle.h"
#include "Quark.h"
#include<random>
#include<ctime>
#include "Electron.h"
#include "Neutrino.h"

void Weak::print_data() const
{
  // // need to use getters from Particle
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
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


double Weak::get_particle_mass_from_flavour(double particle_charge) const 
{
  double particle_mass;
  if(particle_charge == 0)
  {
    particle_mass = 91200;
  }
  else
  {
    particle_mass = 80400;
  }

  return particle_mass;
}

bool Weak::get_is_antiparticle_from_charge(double particle_charge)
{
  bool is_antiparticle;
  if(particle_charge == -1.0)
  {
    is_antiparticle = true;
  }
  else
  {
    is_antiparticle = false;
  }
  return is_antiparticle;
}

std::string Weak::get_particle_name_from_charge(double particle_charge) const
{
  std::string particle_name;
  if(particle_charge == -1.0)
  {
    particle_name = "W^-";
  }
  else if(particle_charge == 0.0)
  {
    particle_name = "Z";
  }
  else if(particle_charge == 1.0)
  {
    particle_name = "W^+";
  }
  return particle_name;
}

void Weak::input_check_charge(double particle_charge)
{
  if(particle_charge != -1 && particle_charge != 0 && particle_charge != 1) 
  {
    std::cerr << "Invalid particle charge: must be -1, 0, or 1. Setting charge to 1 by default." << std::endl;
    particle_charge = 1;
  }
}

void Weak::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Weak::set_name(std::string particle_name)
{
  // Particle name can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

void Weak::decay_weak()
{
  std::pair<std::string, std::string>  colour_of_quarks = generateRandomQuarkColor(); // To get colour singlet pion
  if(this->charge == 0.0)
  {
    // Add all decay prodcuts from Z to the vector

    std::unique_ptr<Particle> Z_decayed_up_quark_ptr_1 = std::make_unique<Quark>(true, 2 ,1.0, 1.0, 0.0, 1, colour_of_quarks.second, true); 
    std::unique_ptr<Particle> Z_decayed_up_quark_ptr_2 = std::make_unique<Quark>(false, 2 ,1.0, 1.0, 0.0, 1, colour_of_quarks.first, true); 
    
    std::unique_ptr<Particle> Z_decayed_down_quark_ptr_1 = std::make_unique<Quark>(true, 2 ,1.0, 1.0, 0.0, 1, colour_of_quarks.second, false); 
    std::unique_ptr<Particle> Z_decayed_down_quark_ptr_2 = std::make_unique<Quark>(false, 2 ,1.0, 1.0, 0.0, 1, colour_of_quarks.first, false); 
    
    std::unique_ptr<Particle> Z_decayed_lepton_quark_ptr_1 = std::make_unique<Electron>(true, 2 ,1.0, 1.0, 0.0); // muon and tau possible not implented
    std::unique_ptr<Particle> Z_decayed_lepton_quark_ptr_2 = std::make_unique<Electron>(false, 2 ,1.0, 1.0, 0.0); // muon and tau possible not implented

    std::unique_ptr<Particle> Z_decayed_neutrino_quark_ptr_1 = std::make_unique<Neutrino>(true, 2 ,1.0, 1.0, 0.0, false, 1); // muon and tau possible not implented
    std::unique_ptr<Particle> Z_decayed_neutrino_quark_ptr_2 = std::make_unique<Neutrino>(false, 2 ,1.0, 1.0, 0.0, false, 1); // muon and tau possible not implented


    add_decay_product_pair(std::move(Z_decayed_up_quark_ptr_1), std::move(Z_decayed_up_quark_ptr_2)); // 2 up-type quarks
    add_decay_product_pair(std::move(Z_decayed_down_quark_ptr_1), std::move(Z_decayed_down_quark_ptr_2)); // 2 up-type quarks
    add_decay_product_pair(std::move(Z_decayed_lepton_quark_ptr_1), std::move(Z_decayed_lepton_quark_ptr_2)); // 2 leptons
    add_decay_product_pair(std::move(Z_decayed_neutrino_quark_ptr_1), std::move(Z_decayed_neutrino_quark_ptr_2)); // 2 neutrinos

  }
  else
  {
    // Add all decay prodcuts from W to the vector
    // Depends if its W+ or W-

    std::unique_ptr<Particle> W_decayed_up_type_quark_ptr = std::make_unique<Quark>((m_is_antiparticle ? 1:0), 2 ,1.0, 1.0, 0.0, 1, (m_is_antiparticle ? colour_of_quarks.first:colour_of_quarks.second), true); // 0:1 conserves charge
    std::unique_ptr<Particle> W_decayed_down_type_quark_ptr = std::make_unique<Quark>((m_is_antiparticle ? 0:1), 2 ,1.0, 1.0, 0.0, 1, (this->get_is_antiparticle() ? colour_of_quarks.second:colour_of_quarks.first) , false); 

    std::unique_ptr<Particle> W_decayed_lepton_quark_ptr_1 = std::make_unique<Electron>((m_is_antiparticle ? 0:1), 2 ,1.0, 1.0, 0.0); // muon and tau possible not implented
    std::unique_ptr<Particle> W_decayed_neutrino_quark_ptr_1 = std::make_unique<Neutrino>((m_is_antiparticle ? 1:0), 2 ,1.0, 1.0, 0.0, false, 1); // muon and tau possible not implented

    add_decay_product_pair(std::move(W_decayed_up_type_quark_ptr), std::move(W_decayed_down_type_quark_ptr)); // hadronic
    add_decay_product_pair(std::move(W_decayed_lepton_quark_ptr_1), std::move(W_decayed_neutrino_quark_ptr_1)); // leptonic
  }
}

// Function to generate a random quark color singlet
std::pair<std::string, std::string> Weak::generateRandomQuarkColor() 
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

void Weak::print_decay_products() 
{
  for(auto it = decay_product_pairs.begin(); it != decay_product_pairs.end(); ++it) 
  {
    auto pair_index = std::distance(decay_product_pairs.begin(), it) + 1;
        
    std::cout<<"Decay Product Pair "<<pair_index<<" for "<<this->get_name()<<":"<<std::endl;
    std::cout<<"Particle 1:"<<std::endl;
    it->first->print_data();   
    std::cout<<"Particle 2:"<<std::endl;
    it->second->print_data();   
  }
}


Weak& Weak::operator=(Weak &&weak_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &weak_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Boson::operator=(std::move(weak_called_to_move));
  decay_product_pairs = std::move(weak_called_to_move.decay_product_pairs);

    return *this;
  }
}

Weak::Weak(Weak &&weak_called_to_move) : Boson(std::move(weak_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;
  
  decay_product_pairs = std::move(weak_called_to_move.decay_product_pairs);

}