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
    if (particle_type != "electron" && particle_type != "positron" && particle_type != "muon" && particle_type != "antimuon")
    {
      std::cerr<<"Error: Invalid lepton type given. Lepton set to be electron"<<std::endl;
      type = "electron";
    }
    if (particle_velocity<0 || particle_velocity > light_speed)
    {
      std::cerr<<"Error: Velocity must be between 0 and the speed of light."<<std::endl;
      std::cerr<<"Setting velocity and beta to be 0."<<std::endl;
      velocity = 0.0;
      beta = 0.0;
    }
    if (particle_charge != -1 && particle_charge != 1)
    {
      std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
      if (type == "electron" || type == "muon") 
      {
      std::cerr<<"Charge of "<<type<<" set to -1."<<std::endl;
      charge = -1;
      }
      else if (type == "positron" || type == "antimuon") 
      {
      std::cerr<<"Charge of "<<type<<" set to +1."<<std::endl;
      charge = 1;
      }    
    }
    else if ((type == "electron" || type == "muon") && particle_charge != -1) 
    {
      std::cerr<<"Error: Invalid charge for "<<type<<". Charge must be -1."<<std::endl;
      std::cerr<<"Setting charge = -1."<<std::endl;
      charge = -1;
    }
    else if ((type == "positron" || type == "antimuon") && particle_charge != 1)
    { 
      std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
      std::cerr<<"Setting charge = +1."<<std::endl;
      charge = 1;
    } 
  }
  
  // Destructor 
  /***********************/
  ~particle()
  {
    std::cout<<"Destroying "<<type<<std::endl;
  }
  
  // Getter functions read only (accessors) to 
  // This should include function returning beta value
  std::string get_type() const 
  {
    return type;
  }

  double get_rest_mass() const 
  {
    return rest_mass;
  }

  int get_charge() const 
  {
    return charge;
  }

  double get_velocity() const 
  {
    return velocity;
  }

  double get_beta() const 
  {
    return beta;
  }

  // Setter functions, to change value of data members

  void set_type(std::string particle_type);

  void set_rest_mass(double particle_mass)
  {
    rest_mass = particle_mass;
  }

  void set_charge(int particle_charge);

  void set_velocity(int particle_velocity);
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

void particle::set_charge(int particle_charge)
  {
    if (particle_charge != -1 && particle_charge != 1)
    {
      std::cerr<<"Error: Charge must be either -1 or 1."<<std::endl;
      std::cerr<<"Error: Charge not updated."<<std::endl;
    } 
    else if ((type == "electron" || type == "muon") && particle_charge != -1) 
    {
    std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
    std::cerr<<"Error: Charge not updated. Reset type of particle if it is incorrect"<<std::endl;
    } 
    else if ((type == "positron" || type == "antimuon") && particle_charge != 1)
    { 
      std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
      std::cerr<<"Error: Charge not updated. Reset type of particle if it is incorrect."<<std::endl;
    }
    else
      charge = particle_charge;
  }

  void particle::set_type(std::string particle_type)
  {
    if (particle_type != "electron" || particle_type != "positron" || particle_type != "muon" || particle_type != "antimuon")
    {
      std::cerr<<"Error: Invalid lepton type given."<<std::endl;
      std::cerr<<"Error: Lepton type not updated."<<std::endl;
    }
    else if ((particle_type == "electron" || particle_type == "muon") && charge != -1)
    {
    std::cerr<<"Error: Invalid charge for electron/muon. Charge must be -1."<<std::endl;
    std::cerr<<"Error: Type of particle not updated. Reset charge of particle if it is incorrect"<<std::endl;
    }
    else if ((type == "positron" || type == "antimuon") && charge != 1)
    { 
      std::cerr<<"Error: Invalid charge for positron/antimuon. Charge must be 1."<<std::endl;
      std::cerr<<"Error: Type of particle not updated. Reset charge of particle if it is incorrect."<<std::endl;
    }  
    else
      type = particle_type;
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
  particle electron("electron", 0.511, 1, 2.5e8);
  std::cout<<"Attempting to set charge of electron = 1"<<std::endl;
  electron.set_charge(1);
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
