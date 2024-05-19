#include<iostream>
#include<string>
#include "Higgs.h"
#include "Particle.h"
#include "Quark.h"
#include<random>
#include<ctime>
#include "Electron.h"
#include "Neutrino.h"
#include "Weak.h"
#include "Photon.h"

void Higgs::print_data() const
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

void Higgs::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Higgs::set_name(std::string particle_name)
{
  // Particle name can't be changed in Gluon
  std::cerr<<"\033[1;31mError\033[0m: Gluon particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

void Higgs::decay_higgs()
{
  std::pair<std::string, std::string>  colour_of_quarks = generateRandomQuarkColor(); // To get colour singlet pion
  if(this->charge == 0.0)
  {
    // Add all decay prodcuts from Higgs to the vector

    std::unique_ptr<Particle> H_decayed_Z_ptr_1 = std::make_unique<Weak>(3000.0, 200.1, 4000.7, 5000.3, 0.0); // Z boson
    std::unique_ptr<Particle> H_decayed_Z_ptr_2 = std::make_unique<Weak>(3000.0, 500.1, 600.7, 700.3, 0.0); // Z boson

    std::unique_ptr<Particle> H_decayed_W_ptr_1 = std::make_unique<Weak>(3000.0, 6000.1, 6000.7, 700.3, -1.0); // W- boson 
    std::unique_ptr<Particle> H_decayed_W_ptr_2 = std::make_unique<Weak>(3000.0, 6000.1, 700.7, 700.3, 1.0);  // W+ boson
    
    std::unique_ptr<Particle> H_decayed_photon_ptr_1 = std::make_unique<Photon>(3000.0 , 1000.0, 2000.0, 1000.0); // photon
    std::unique_ptr<Particle> H_decayed_photon_ptr_2 = std::make_unique<Photon>(3000.0 ,2000.0, 2000.0, 1000.0); // photon

    std::unique_ptr<Particle> H_decayed_quark_ptr_1 = std::make_unique<Quark>(true, 3000.0 ,3000.0, 1000.0, 1000.0, 3, colour_of_quarks.second, true); // antitop
    std::unique_ptr<Particle> H_decayed_quark_ptr_2 = std::make_unique<Quark>(false, 3000.0 ,4000.0, 4000.0, 1000.0, 3, colour_of_quarks.first, true); // top

    add_decay_product_pair(std::move(H_decayed_Z_ptr_1), std::move(H_decayed_Z_ptr_2)); // 2 up-type quarks
    add_decay_product_pair(std::move(H_decayed_W_ptr_1), std::move(H_decayed_W_ptr_2)); // 2 up-type quarks
    add_decay_product_pair(std::move(H_decayed_photon_ptr_1), std::move(H_decayed_photon_ptr_2)); // 2 leptons
    add_decay_product_pair(std::move(H_decayed_quark_ptr_1), std::move(H_decayed_quark_ptr_2)); // 2 neutrinos

  }
}

// Function to generate a random quark color singlet
std::pair<std::string, std::string> Higgs::generateRandomQuarkColor() 
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

void Higgs::print_decay_products() 
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
