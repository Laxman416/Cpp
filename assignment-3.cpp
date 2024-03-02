// PHYS 30762 Programming in C++
// Assignment 3
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#define light_speed 2.99792458e8

// Beginning of particle class
class particle
{
private:
  // data members
  std::string type;
  double rest_mass; // in MeV
  int charge; // +1 particle, -1 antiparticle
  double velocity; // in m/s
  double beta; // = v/c

public:
  // Constructors
  // default constructor
  particle() = default;
  //Parameterised constructor
  particle(std::string particle_type, double particle_mass, int particle_charge, double particle_velocity) :
    type{particle_type}, 
    rest_mass{particle_mass},
    charge{particle_charge},
    velocity{particle_velocity},
    beta{particle_velocity/light_speed}
  {
    if (particle_velocity<0 || particle_velocity > light_speed)
    {
      std::cerr<<"Error: Velocity must be between 0 and the speed of light."<<std::endl;
      std::cerr<<"Error: Setting velocity and beta to be 0."<<std::endl;
      velocity = 0.0;
      beta = 0.0;
    }
  }
  
  // Destructor 
  /***********************/
  ~particle()
  {
    std::cout<<"Destroying "<<type<<std::endl;
  }
  
  // Getter functions (accessors) to 
  // This should include function returning beta value 

  // Setter functions, to change value of data members
  // Make sure you check input validity before changing something
  // Hint: you can use the input checking functions you used in assignment 1

  // Function to print info about a particle
  void print_data();
};

// Implementation of print_data function goes here
void particle::print_data()
{
  std::cout<<"Particle Type: "<<type<<std::endl;
  std::cout<<"Rest Mass: "<<rest_mass<<" MeV"<<std::endl;
  std::cout<<"Charge: "<<charge<<std::endl;
  std::cout<<"Velocity: "<<velocity<<" m/s"<<std::endl;
  std::cout<<"Beta: "<<beta<<std::endl;
}
// End of particle class and associated member functions

// Beginning of detector class

// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// - write a function that takes a particle 
//   and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular detector, 
//   and of which type
// - write a function (accessor) that prints how many particles passed through this detector

// End of detector class

// Main program
int main()
{
  particle electron("electron", 0.511, -1, 4.5e8);
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
