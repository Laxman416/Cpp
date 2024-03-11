// PHYS 30762 Programming in C++
// Assignment 3

#include<iostream>
#include<string>
#include "particle.h" 
#include "detector.h"
#include<vector>

void create_particles(std::vector<particle>& particles) 
{
  // Reserve space for 8 elements to prevent reallocation
  particles.reserve(8);

  // Create particle objects
  particles.emplace_back("electron", 0.511, -1, 1.5e8);
  particles.emplace_back("electron", 0.511, -1, 2.9e8);
  particles.emplace_back("muon", 105.66, -1, 2.5e8);
  particles.emplace_back("muon", 105.66, -1, 2.3e8);
  particles.emplace_back("muon", 105.66, -1, 2.6e8);
  particles.emplace_back("muon", 105.66, -1, 2.7e8);
  particles.emplace_back("positron", 0.511, 1, 2.1e8);
  particles.emplace_back("antimuon", 105.66, 1, 2.2e8);
}

// Main program
int main()
{
  std::vector<particle> particles_class_vector; // particle class vector
  std::vector<detector> detectors_vector; //detector class vector

  // Call function to create particles and detectors
  create_particles(particles_class_vector); 
  create_detectors(detectors_vector);

  // To change set particles data members, need to use particles_class_vector[i].set_ ....

  // Print out data members for all particles
  for(const auto& particle_iterator : particles_class_vector) 
  {
    particle_iterator.print_data();
    std::cout<<""<<std::endl;
  }

  // Call function to turn on detector and pass particles through each detector and output result
  process_detectors(particles_class_vector, detectors_vector);
  return 0;
}