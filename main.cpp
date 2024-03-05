// PHYS 30762 Programming in C++
// Assignment 3

#include<iostream>
#include<string>
#include "particle.h" 


// Main program
int main()
{
  particle electron("electron", 0.511, -1, 2.5e8);
  // std::cout<<"Attempting to set chbetaarge of electron = 0.5"<<std::endl;
  // electron.set_type("antimuon");
  std::cout<<"Outputing data members of particle class of electron"<<std::endl;
  electron.print_data();  
  // Create the following particles: 
  // two electrons, four muons, one antielectron, one antimuon
  // Use the parameterised constructor

  // Print out the data from all the particles (put them in a vector)

  // Create the following detectors: a tracker, a calorimeter, a muon chamber

  // Pass the list of particles into each detector

  // Print a summary of how many particles were detected

  return 0;
}