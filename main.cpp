
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
#include "Tau.h"
#include "Boson.h"
#include "Photon.h"
#include "Gluon.h"
#include "Weak.h"
#include "Higgs.h"

template <class ParticleType>
void create_particles(ParticleCatalogue<ParticleType>& particle_catalogue) 
{
  // Preallocation isn't possible using std::multimap unlike vector which requires .reserve
  // Create null particle to use if index of container out of range
  // particle_catalogue.add_particle(std::make_unique<Electron>(false, 1.0, 10, 10, 10));
  // particle_catalogue.add_particle(std::make_unique<Electron>(true, 1.0, 10, 10, 10));
  // particle_catalogue.add_particle(std::make_unique<Muon>(false, 1.0, 10, 10, 10, true));
  // particle_catalogue.add_particle(std::make_unique<Muon>(true, 1.0, 10, 10, 10, true));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(true, 1.0, 0.1, 0.7, 0.3, false, 1));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(true, 1.0, 0.1, 0.7, 0.3, false, 2));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(true, 1.0, 0.1, 0.7, 0.3, false, 3));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(false, 1.0, 0.1, 0.7, 0.3, false, 1));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(false, 1.0, 0.1, 0.7, 0.3, false, 2));
  // particle_catalogue.add_particle(std::make_unique<Neutrino>(false, 1.0, 0.1, 0.7, 0.3, false, 3));
  // particle_catalogue.add_particle(std::make_unique<Quark>(true, 1.0, 0.1, 0.7, 0.3, 2, "red", true));
  // particle_catalogue.add_particle(std::make_unique<Tau>(true, 1.0, 0.1, 0.7, 0.3));
  // particle_catalogue.add_particle(std::make_unique<Tau>(false, 1.0, 0.1, 0.7, 0.3));
  particle_catalogue.add_particle(std::make_unique<Weak>(3000.0 ,2000.0, 2000.0, 1000.0, 0.0));
  particle_catalogue.add_particle(std::make_unique<Weak>(3000.0 ,2000.0, 2000.0, 1000.0, -1.0));
  particle_catalogue.add_particle(std::make_unique<Weak>(3000.0 ,2000.0, 2000.0, 1000.0, 1.0));
  particle_catalogue.add_particle(std::make_unique<Higgs>(3000.0 ,2000.0, 2000.0, 1000.0));

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

  // Printing all particles in catalogue
  catalogue.print_all_particles();

  std::cout<<"The total number of particles in the container: "<<catalogue.get_total_particles()<<std::endl;
  catalogue.print_particles_count_by_type();

  std::vector<double> sum_all_momentum = catalogue.sum_four_momentum();

  ParticleCatalogue new_catalogue = catalogue.get_container_of_a_type("Charged Lepton");

  // Printing possible Decay Products of Z, W and Higgs
  // catalogue["Z_1"]->print_decay_products();
  // catalogue["W^+_1"]->print_decay_products();
  // catalogue["W^-_1"]->print_decay_products();
  catalogue["Higgs_1"]->print_decay_products();


  // new_catalogue.print_all_particles();
  // catalogue["Electron_21"]->print_data();

  // sum_four_momentum(leptons_class_vector);
  
  // dot_four_momentum(leptons_class_vector);

  return 0;
}