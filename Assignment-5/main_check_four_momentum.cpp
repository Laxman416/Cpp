// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "four_momentum.h"

using std::string;

// Beginning of lepton class (hint: start from assignment 4 particle class)
class lepton
{
private:
  //...
public:
  //...
protected: 
  //...

};
// End of lepton class and associated member functions

// Derived classes for other particles, and four-momentum class go here

// Implementation of functions from a class should be done outside the class, preferably in another file

void create_particles(std::vector<four_momentum>& four_momentums) 
{
  // Reserve space for 8 elements to prevent reallocation
  four_momentums.reserve(8);

  // // Create particle objects
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
  four_momentums.emplace_back(10.0, 5.0, 4.0, 3.0);
}

void sum_four_momentum(std::vector<four_momentum>& four_momentums)
{
  // Sum the four-momenta
   std::vector<double> total_momentum = four_momentums[0] + four_momentums[1];

  // Print the summed four-momentum
  std::cout<<"Sum of four momenta's components:"<<std::endl;
  std::cout<<"\tEnergy: "<<total_momentum[0]<<" MeV/c"<<std::endl;
  std::cout<<"\tp_x: "<<total_momentum[1]<<" MeV/c"<<std::endl;
  std::cout<<"\tp_y: "<<total_momentum[2]<<" MeV/c"<<std::endl;
  std::cout<<"\tp_z: "<<total_momentum[3]<<" MeV/c"<<std::endl;
}

void dot_four_momentum(std::vector<four_momentum>& particles)
{
  double dotted_momentum = particles[2].dotProduct(particles[3]);

  std::cout<<"Dot Product of four momentum's of is "<<dotted_momentum<<std::endl;
  std::cout<<""<<std::endl;
}

void copy_object(const four_momentum& object_to_copy)
{
  // Using copy constructor

  std::cout<<"\tOriginal particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  object_to_copy.print_data();

  four_momentum new_object = object_to_copy;
  std::cout<<"Copied particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  new_object.print_data();
  std::cout<<"----------------------------------------------------------------------- "<<std::endl;
}

void copy_object_assignment_operator(four_momentum& new_object, const four_momentum& object_to_copy_using_assignment)
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

void move_object(four_momentum& object_to_move)
{
  // Using move constuctor
  std::cout<<"\tOriginal particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  object_to_move.print_data();
  
  four_momentum new_positron = std::move(object_to_move);
  std::cout<<"Moved particle:"<<std::endl;
  std::cout<<" "<<std::endl;
  new_positron.print_data();
  std::cout<<"----------------------------------------------------------------------- "<<std::endl;
}

// Main program
int main()
{
  std::vector<four_momentum> four_momentums_vector; // particle class vector

  // Call function to create particles
  create_particles(four_momentums_vector); 
  // To change set particles data members, need to use particles_class_vector[i].set_ ....

  // // Function to do sum and dot of four momentum
  sum_four_momentum(four_momentums_vector);
  dot_four_momentum(four_momentums_vector);

  // // Call Function which uses copy constructor to copy a muon to a new muon
  copy_object(four_momentums_vector[2]);

  // // Call Function which uses assignment operator to copy a electron to a new electron
  four_momentum new_electron;
  copy_object_assignment_operator(new_electron,four_momentums_vector[0]);

  // // Call Function which uses move constructor to move positron to new positron
  move_object(four_momentums_vector[6]);

  // // Move antimuon to another antimuon using moving assignment
  four_momentum new_antimuon;
  new_antimuon = std::move(four_momentums_vector[7]);
  new_antimuon.print_data();

  std::cout<<"Program is Finished."<<std::endl;
  return 0;
}