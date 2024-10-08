
#include<iostream>
#include<string>
#include "Lepton.h" 
#include "ChargedLepton.h"
#include "CalorimeterLayers.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "ElectronNeutrino.h"
#include "MuonNeutrino.h"
#include "TauNeutrino.h"
#include "Particle.h"
#include<vector>


void create_particles(std::vector<std::unique_ptr<Lepton>>& leptons) 
{
  // Reserve space for 8 elements to prevent reallocation
  leptons.reserve(12); 

  // Create particle objects
  leptons.emplace_back(std::make_unique<Electron>(false, 1.0, 0.1, 0.1, 0.1));  
  leptons.emplace_back(std::make_unique<Electron>(false, 1.0, 0.2, 0.2, 0.2));
  leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.15, 0.2, true));
  leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.3, 0.15, true));
  leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.2, 0.1, 0.3, true));
  leptons.emplace_back(std::make_unique<Muon>(false, 1.0, 0.1, 0.1, 0.3, false));
  leptons.emplace_back(std::make_unique<Electron>(true, 1.0, 0.5, 0.1, 0.3));
  leptons.emplace_back(std::make_unique<Muon>(true, 1.0, 0.1, 0.7, 0.3, true));
  leptons.emplace_back(std::make_unique<MuonNeutrino>(true, 1.0, 0.1, 0.7, 0.3, false));
  leptons.emplace_back(std::make_unique<ElectronNeutrino>(true, 1.0, 0.1, 0.7, 0.3, false));
  leptons.emplace_back(std::make_unique<Tau>(false, 1.0, 0.1, 0.7, 0.3, true));
  leptons.emplace_back(std::make_unique<Tau>(true, 1.0, 0.1, 0.7, 0.3, true));
}

void sum_four_momentum(std::vector<std::unique_ptr<Lepton>>& leptons)
{
  std::vector<double> momentum = *leptons[0] + *leptons[1];
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"Sum of four momentum's of "<<leptons[0]->get_name()<<" and "<<leptons[1]->get_name()<<": "<<std::endl;
  std::cout<<"E: "<<momentum[0]<<" MeV/c"<<std::endl;
  std::cout<<"px: "<<momentum[1]<<" MeV/c"<<std::endl;
  std::cout<<"py: "<<momentum[2]<<" MeV/c"<<std::endl;
  std::cout<<"pz: "<<momentum[3]<<" MeV/c"<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<""<<std::endl;

}


void dot_four_momentum(std::vector<std::unique_ptr<Lepton>>& leptons)
{
  double dotted_momentum = dotProduct(*leptons[7], *leptons[8]);
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"Dot Product of four momentum's of "<<leptons[2]->get_name()<<" and "<<leptons[3]->get_name()<<" is "<<dotted_momentum<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<""<<std::endl;
}

// Main program
int main()
{
  std::vector<std::unique_ptr<Lepton>> leptons_class_vector; // particle class vector

  // Call function to create particles
  create_particles(leptons_class_vector); 
  // Print out data members for all particles
  for(const auto& lepton_iterator : leptons_class_vector) 
  {
    lepton_iterator->print_data();
    std::cout<<""<<std::endl;
  }
  sum_four_momentum(leptons_class_vector);
  
  dot_four_momentum(leptons_class_vector);

  // Create a unique pointer for a new electron
  std::unique_ptr<Electron> electron1 = std::make_unique<Electron>(1, 5.0, 2, 5, 8);
  electron1->print_data();
  // Move its data to another electron using std::move
  Electron electron2 = std::move(*electron1);
  electron2.print_data();

  std::shared_ptr<Tau> tau_ptr = std::make_shared<Tau>(false, 1.0, 0.1, 0.2, 0.3, false);

  // Copying the pointer to multiple variables
  // Each detector can point to the same tau particle to say if it was detected in both
  std::shared_ptr<Tau> tau_particle_passed_detector_1 = tau_ptr;
  std::shared_ptr<Tau> tau_particle_passed_detector_2 = tau_ptr;
  return 0;
}