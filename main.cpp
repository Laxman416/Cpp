// PHYS 30762 Programming in C++
// Assignment 3

#include<iostream>
#include<string>
#include "particle.h" 
#include<vector>

void create_particles(std::vector<particle>& particles) 
{
  // Reserve space for 8 elements to prevent reallocation
  particles.reserve(8);

  // // Dynamically allocate four-momentum vectors
  std::vector<double>* four_momentum_electron1 = new std::vector<double>{1, 0.0, 0.0, 0};
  std::vector<double>* four_momentum_electron2 = new std::vector<double>{1, 0.0, 0.0, 0};  
  std::vector<double>* four_momentum_muon1 = new std::vector<double>{1, 0.0, 0.0, 0};  
  std::vector<double>* four_momentum_muon2 = new std::vector<double>{1, 0.0, 0.0, 0};  
  std::vector<double>* four_momentum_muon3 = new std::vector<double>{1, 0.0, 0.0, 0};  
  std::vector<double>* four_momentum_muon4 = new std::vector<double>{1, 0.0, 0.0, 0};  
  std::vector<double>* four_momentum_antimuon = new std::vector<double>{1, 0.0, 0.0, 0}; 
  std::vector<double>* four_momentum_positron = new std::vector<double>{1, 2.0, 0.0, 0};  

  // // Create Particle objects
  // particles.emplace_back("positron", 0.511, 1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("electron", 0.511, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("electron", 0.511, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("muon", 105.66, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("muon", 105.66, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("muon", 105.66, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("muon", 105.66, -1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("positron", 0.511, 1, new std::vector<double>{1, 0.0, 0.0, 0});
  // particles.emplace_back("antimuon", 105.66, 1, new std::vector<double>{1, 0.0, 0.0, 0});

  // // Create particle objects
  particles.emplace_back("electron", 0.511, -1, four_momentum_electron1);
  particles.emplace_back("electron", 0.511, -1, four_momentum_electron2);
  particles.emplace_back("muon", 105.66, -1, four_momentum_muon1);
  particles.emplace_back("muon", 105.66, -1, four_momentum_muon2);
  particles.emplace_back("muon", 105.66, -1, four_momentum_muon3);
  particles.emplace_back("muon", 105.66, -1, four_momentum_muon4);
  particles.emplace_back("positron", 0.511, 1, four_momentum_positron);
  particles.emplace_back("antimuon", 105.66, 1, four_momentum_antimuon);
}

void sum_four_momentum(std::vector<particle>& particles)
{
  std::vector<double> momentum = particles[0].operator+(particles[1]);
  std::vector<std::string> index_names = particles[0].get_index_names(); // Get the component names

  std::cout<<"Sum of four momentum's of "<<particles[0].get_type()<<" and "<<particles[1].get_type()<<std::endl;
  for(size_t i = 0; i < (momentum).size(); ++i) 
  {
    std::cout<<index_names[i]<<": "<<momentum[i]<<" MeV/c"<<std::endl;
  }
  std::cout<<""<<std::endl;
}

void dot_four_momentum(std::vector<particle>& particles)
{
  double dotted_momentum = particles[0].dotProduct(particles[1]);
  std::vector<std::string> index_names = particles[0].get_index_names(); // Get the component names

  std::cout<<"Dot Product of four momentum's of "<<particles[0].get_type()<<" and "<<particles[1].get_type()<<" is "<<dotted_momentum<<std::endl;
  std::cout<<""<<std::endl;

}

// Main program
int main()
{
  std::vector<particle> particles_class_vector; // particle class vector

  // Call function to create particles
  create_particles(particles_class_vector); 

  // To change set particles data members, need to use particles_class_vector[i].set_ ....

  // Print out data members for all particles
  // for(const auto& particle_iterator : particles_class_vector) 
  // {
  //   particle_iterator.print_data();
  // }

  sum_four_momentum(particles_class_vector);
  dot_four_momentum(particles_class_vector);

  particles_class_vector[1].print_data();
  particles_class_vector[2].print_data();
  
  particles_class_vector[1] = particles_class_vector[2];

  particles_class_vector[1].print_data();
  particles_class_vector[2].print_data();
  return 0;
}

