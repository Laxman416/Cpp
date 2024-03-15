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
  std::vector<double>* four_momentum_electron1 = new std::vector<double>{1, 0.1, 0.1, 0.1};
  std::vector<double>* four_momentum_electron2 = new std::vector<double>{1, 0.2, 0.2, 0.2};  
  std::vector<double>* four_momentum_muon1 = new std::vector<double>{1, 0.3, 0.3, 0.3};  
  std::vector<double>* four_momentum_muon2 = new std::vector<double>{1, 0.4, 0.4, 0.4};  
  std::vector<double>* four_momentum_muon3 = new std::vector<double>{1, 0.5, 0.5, 0.5};  
  std::vector<double>* four_momentum_muon4 = new std::vector<double>{1, 0.6, 0.6, 0.6};  
  std::vector<double>* four_momentum_antimuon = new std::vector<double>{1, 0.7, 0.7, 0.7}; 
  std::vector<double>* four_momentum_positron = new std::vector<double>{1, 2.1, 0.1, 0.1};  

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

  std::cout<<"Sum of four momentum's of "<<particles[0].get_type()<<" and "<<particles[1].get_type()<<": "<<std::endl;
  for(size_t i = 0; i < (momentum).size(); ++i) 
  {
    std::cout<<index_names[i]<<": "<<momentum[i]<<" MeV/c"<<std::endl;
  }
  std::cout<<""<<std::endl;
}

void dot_four_momentum(std::vector<particle>& particles)
{
  double dotted_momentum = particles[2].dotProduct(particles[3]);
  std::vector<std::string> index_names = particles[2].get_index_names(); // Get the component names

  std::cout<<"Dot Product of four momentum's of "<<particles[2].get_type()<<" and "<<particles[3].get_type()<<" is "<<dotted_momentum<<std::endl;
  std::cout<<""<<std::endl;
}

void copy_object(const particle& object_to_copy)
{
  // Using copy constructor

  std::cout<<"Copy first "<<object_to_copy.get_type()<<" to new "<<object_to_copy.get_type()<<": "<<std::endl;
  std::cout<<"\tOriginal particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  object_to_copy.print_data();

  particle new_object = object_to_copy;
  std::cout<<"Copied particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  new_object.print_data();
  std::cout<<"----------------------------------------------------------------------- "<<std::endl;
}

void copy_object_assignment_operator(particle& new_object, const particle& object_to_copy_using_assignment)
{
  // Using assignment operator

  std::cout<<"Copy electron to new electron using assignment operator."<<std::endl;
  std::cout<<"Original particle:"<<std::endl;  
  std::cout<<" "<<std::endl;
  object_to_copy_using_assignment.print_data();

  new_object = object_to_copy_using_assignment;
  std::cout<<"New particle after copy assignment opeator:"<<std::endl;  
  new_object.print_data();
  std::cout<<"----------------------------------------------------------------------- "<<std::endl;
}

void move_object(particle& object_to_move)
{
  // Using move constuctor
  std::cout<<"Move "<<object_to_move.get_type()<<" to new "<<object_to_move.get_type()<<": "<<std::endl;
  std::cout<<"\tOriginal particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  object_to_move.print_data();
  
  particle new_positron = std::move(object_to_move);
  std::cout<<"Moved particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  new_positron.print_data();
  std::cout<<"----------------------------------------------------------------------- "<<std::endl;
}

// Main program
int main()
{
  std::vector<particle> particles_class_vector; // particle class vector

  // Call function to create particles
  create_particles(particles_class_vector); 
  // To change set particles data members, need to use particles_class_vector[i].set_ ....

  // // Function to do sum and dot of four momentum
  // sum_four_momentum(particles_class_vector);
  // dot_four_momentum(particles_class_vector);

  // // Call Function which uses copy constructor to copy a muon to a new muon
  // copy_object(particles_class_vector[2]);

  // // Call Function which uses assignment operator to copy a electron to a new electron
  // particle new_electron;
  // copy_object_assignment_operator(new_electron,particles_class_vector[0]);

  // // Call Function which uses move constructor to move positron to new positron
  // move_object(particles_class_vector[6]);

  // // Move antimuon to another antimuon using moving assignment
  // particle new_antimuon;
  // new_antimuon = std::move(particles_class_vector[7]);
  // new_antimuon.print_data();

  std::cout<<"Program is Finished."<<std::endl;
}

