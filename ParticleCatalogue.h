#ifndef PARTICLECATALOGUE_H
#define PARTICLECATALOGUE_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <array>
#include <sstream>
#include "SafeSharedPtr.h" // Include your SafeSharedPtr implementation
#include "Lepton.h"

class ParticleCatalogue 
{
private:
  // Using std::multimap to store particles categorized by number, with an additional label for the type of particle
  // particle_entry.first: Key , particle_entry.second.first: ptr to particle,  particle_entry.second.secpnd: label
  std::map<std::string, std::pair<SafeSharedPtr<Particle>, std::string>> particle_container;
  std::map<std::string, int> particle_count; // Map to store the count of particles with the same name, Required to assign a unique key

public:
  ParticleCatalogue() : particle_count{}{}

  // Add a particle to the catalogue
  void add_particle(const SafeSharedPtr<Particle>& particle); 

  // Overload the [] operator to retrieve a particle by key
  SafeSharedPtr<Particle> operator[](const std::string& key); 

  // Function to get the label from a ContainerType element
  std::string get_label(const std::pair<SafeSharedPtr<Particle>, std::string>& particle_entry) const;

  // Print all the Keys in the container
  void print_particles_with_key() const;

  // Get the total number of particles
  size_t get_total_particles() const {return particle_container.size();}

  void print_particles_count_by_type() const;

  int get_total_count_of_a_type(const std::string& particle_type) const;
  
  void print_all_particles() const;

  std::vector<double> sum_four_momentum() const;

  ParticleCatalogue get_container_of_a_type(const std::string& particle_type) const;
};


#endif
