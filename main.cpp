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
  particles.emplace_back("electron", 0.511, -1, 3.0e8);
  particles.emplace_back("muon", 105.66, -1, 2.5e8);
  particles.emplace_back("muon", 105.66, -1, 2.3e8);
  particles.emplace_back("muon", 105.66, -1, 2.6e8);
  particles.emplace_back("muon", 105.66, -1, 2.7e8);
  particles.emplace_back("positron", 0.511, 1, 2.1e8);
  particles.emplace_back("antimuon", 105.66, 1, 2.2e8);
}

void create_detectors(std::vector<detector>& detectors_vector)
{
  // Reserve space for 3 elements to prevent reallocation
  detectors_vector.reserve(3); 

  // Create detector objects
  detectors_vector.emplace_back("tracker", false);
  detectors_vector.emplace_back("calorimeter", false);
  detectors_vector.emplace_back("muon chamber", false);
}

void process_detectors(std::vector<particle>& particles_class_vector, std::vector<detector>& detectors_vector)
{
  for (auto& detector : detectors_vector) 
  {
    // Print detector data
    std::cout<<"Turning "<<detector.get_detector_type()<<" detector on."<<std::endl;
    detector.turn_on();
    detector.print_data();

    // Count particles detected by the current detector
    int detector_count = 0;
    for (const auto& particle_in_detector : particles_class_vector) 
    {
      if (detector.check_particle_detected(particle_in_detector)) 
      {
        detector_count = 1 + detector_count;
      }
    }
    std::cout<<"The number of particles detected by "<<detector.get_detector_type()<<" is "<<detector_count<<std::endl;
    std::cout<<"Turning "<<detector.get_detector_type()<<" detector off."<<std::endl;
    std::cout<<""<<std::endl;
    detector.turn_off();
  }  
}

// Main program
int main()
{
  std::vector<particle> particles_class_vector; // particle class vector
  std::vector<detector> detectors_vector; //detector class vector 
  
  // Call function to create particles and detectors
  create_particles(particles_class_vector); 
  create_detectors(detectors_vector);

  // Print out data members for all particles
  for (const auto& particle_iterator : particles_class_vector) 
  {
    particle_iterator.print_data();
    std::cout<<""<<std::endl;
  }

  // Call function to pass particles through each detector and output result
  process_detectors(particles_class_vector, detectors_vector);
  return 0;
}