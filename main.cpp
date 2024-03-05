// PHYS 30762 Programming in C++
// Assignment 3

#include<iostream>
#include<string>
#include "particle.h" 
#include "detector.h"
#include<vector>

// Main program
int main()
{
  std::vector<particle> particles_class_vector; // particle class vector
  particles_class_vector.reserve(8); // Reserve space for 8 elements to prevent reallocation

  // Emplace new particle objects directly into the vector
  particles_class_vector.emplace_back("electron", 0.511, -1, 2.5e8);
  particles_class_vector.emplace_back("electron", 0.511, -1, 2.5e8);
  particles_class_vector.emplace_back("muon", 105.66, -1, 2.2e8);
  particles_class_vector.emplace_back("muon", 105.66, -1, 2.2e8);
  particles_class_vector.emplace_back("muon", 105.66, -1, 2.2e8);
  particles_class_vector.emplace_back("muon", 105.66, -1, 2.2e8);
  particles_class_vector.emplace_back("positron", 0.511, 1, 2.5e8);
  particles_class_vector.emplace_back("antimuon", 105.66, 1, 2.2e8);
  
  // Print out data for all particles
  for (const auto& particle_iterator : particles_class_vector) 
  {
    particle_iterator.print_data();
    std::cout<<""<<std::endl;
  }

  std::vector<detector> detectors_vector; 
  detectors_vector.reserve(3); // Reserve space for 8 elements to prevent reallocation

  // Create detector objects
  detectors_vector.emplace_back("tracker", true);
  detectors_vector.emplace_back("calorimeter", true);
  detectors_vector.emplace_back("muon chamber", true);

  for (const auto& detector : detectors_vector) 
  {
    // Print detector data
    detector.print_data();

    // Count particles detected by the current detector
    int detector_count = 0;
    for (const auto& particle : particles_class_vector) 
    {
      if (detector.check_particle_detected(particle)) 
      {
          detector_count = 1 + detector_count;
      }
    }
    std::cout<<"The number of particles detected by "<<detector.get_detector_type()<<" is "<<detector_count<<std::endl;
    std::cout<<""<<std::endl;

  }

  return 0;
}