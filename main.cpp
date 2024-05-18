
#include<iostream>
#include<string>
#include "Electron.h"
#include "Lepton.h" 
#include "CalorimeterLayers.h"
#include "Particle.h"
#include<vector>
// #include "Muon.h"
// #include "Tau.h"
// #include "ElectronNeutrino.h"
// #include "MuonNeutrino.h"
// #include "TauNeutrino.h"


void create_particles(std::vector<std::unique_ptr<Particle>>& particles) 
{
  // Reserve space for 8 elements to prevent reallocation
  particles.reserve(12); 

  // Create particle objects
  particles.emplace_back(std::make_unique<Electron>(false, 1.0, 0.1, 0.1, 0.1));  
  particles.emplace_back(std::make_unique<Electron>(false, 1.0, 0.2, 0.2, 0.2));
  // leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.15, 0.2, true));
  // leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.3, 0.15, true));
  // leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.1, 0.3, true));
  // leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.1, 0.1, 0.3, false));
  // leptons.emplace_back(std::make_unique<Electron>(true, 1.0, 0.5, 0.1, 0.3));
  // leptons.emplace_back(std::make_unique<Muon>(true, 1.0, 0.1, 0.7, 0.3, true));
  // leptons.emplace_back(std::make_unique<MuonNeutrino>(true, 1.0, 0.1, 0.7, 0.3, false));
  // leptons.emplace_back(std::make_unique<ElectronNeutrino>(true, 1.0, 0.1, 0.7, 0.3, false));
  // leptons.emplace_back(std::make_unique<Tau>(false, 1.0, 0.1, 0.7, 0.3, true));
  // leptons.emplace_back(std::make_unique<Tau>(true, 1.0, 0.1, 0.7, 0.3, true));
}

void sum_four_momentum(std::vector<std::unique_ptr<Particle>>& particles)
{
  std::vector<double> momentum = *particles[0] + *particles[1];
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"Sum of four momentum's of "<<particles[0]->get_name()<<" and "<<particles[1]->get_name()<<": "<<std::endl;
  std::cout<<"E: "<<momentum[0]<<" MeV/c"<<std::endl;
  std::cout<<"px: "<<momentum[1]<<" MeV/c"<<std::endl;
  std::cout<<"py: "<<momentum[2]<<" MeV/c"<<std::endl;
  std::cout<<"pz: "<<momentum[3]<<" MeV/c"<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<""<<std::endl;

}


void dot_four_momentum(std::vector<std::unique_ptr<Particle>>& particles)
{
  double dotted_momentum = dotProduct(*particles[7], *particles[8]);
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"Dot Product of four momentum's of "<<particles[2]->get_name()<<" and "<<particles[3]->get_name()<<" is "<<dotted_momentum<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<""<<std::endl;
}

// Main program
int main()
{
  std::vector<std::unique_ptr<Particle>> particle_class_vector; // particle class vector

  // Call function to create particles
  create_particles(particle_class_vector); 
  // Print out data members for all particles
  for(const auto& particle_iterator : particle_class_vector) 
  {
    particle_iterator->print_data();
    std::cout<<""<<std::endl;
  }
  // sum_four_momentum(leptons_class_vector);
  
  // dot_four_momentum(leptons_class_vector);

  return 0;
}