
#include<iostream>
#include <iomanip>
#include<string>
#include "Electron.h"
#include "Muon.h"
#include "Lepton.h" 
#include "CalorimeterLayers.h"
#include "Particle.h"
#include "ParticleCatalogue.h"
#include "SafeSharedPtr.h"
#include<vector>
#include "Neutrino.h"
#include "Quark.h"
// #include "Tau.h"

template <class ParticleType>
void create_particles(ParticleCatalogue<ParticleType>& particle_catalogue) 
{
  // Preallocation isn't possible using std::multimap unlike vector which requires .reserve
  // Create null particle to use if index of container out of range
  particle_catalogue.add_particle(std::make_unique<Electron>(false, 1.0, 10, 10, 10));
  particle_catalogue.add_particle(std::make_unique<Electron>(false, 1.0, 10, 10, 10));
  particle_catalogue.add_particle(std::make_unique<Electron>(true, 1.0, 10, 10, 10));
  particle_catalogue.add_particle(std::make_unique<Neutrino>(true, 1.0, 0.1, 0.7, 0.3, false, 1));
  particle_catalogue.add_particle(std::make_unique<Quark>(true, 1.0, 0.1, 0.7, 0.3, 2, "red", true));

  // Create particle objects
  // particles.emplace_back(std::make_unique<Electron>(false, 1.0, 10, 10, 10));
  // particles.emplace_back(std::make_unique<Electron>(false, 1.0, 0.2, 0.2, 0.2));
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

// Main program
int main()
{
  // std::vector<std::unique_ptr<Particle>> particle_class_vector; // particle class vector
  ParticleCatalogue<Particle> catalogue;

  // Call function to create particles
  create_particles(catalogue); 
  // Print out data members for all particles
  catalogue.print_particles_with_key();

  std::cout<<"The total number of particles in the container: "<<catalogue.get_total_particles()<<std::endl;
  catalogue.print_particles_count_by_type();
  catalogue.print_all_particles();

  std::vector<double> sum_all_momentum = catalogue.sum_four_momentum();

  ParticleCatalogue new_catalogue = catalogue.get_container_of_a_type("Charged Lepton");
  SafeSharedPtr<Particle> pointer = nullptr;
  catalogue["Anticharm_1"]->print_data();

  Quark quark(true, 1.0, 0.1, 0.7, 0.3, 2, "red", true);
  std::cout<<std::setprecision(10)<<quark.get_baryon_number()<<std::endl;

  // new_catalogue.print_all_particles();
  // catalogue["Electron_21"]->print_data();

  // SafeSharedPtr<Particle> pointer = nullptr;
  // pointer->print_data();

    // if (pointer) {
  //   pointer->print_data();
  // } else {
  //     std::cerr << "Error: Safe pointer is null." << std::endl;
  // }

  // sum_four_momentum(leptons_class_vector);
  
  // dot_four_momentum(leptons_class_vector);

  return 0;
}