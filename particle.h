// PHYS 30762 Programming in C++
// Assignment 3 - particle class

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

#define light_speed 2.99792458e8

// Beginning of particle class
class particle
{
private:
  // data members
  std::string type;
  double rest_mass; // in MeV
  int charge; // +1 particle, -1 antiparticle
  std::vector<double>*  four_momentum; // Four-momentum P = (E/c, px, py, pz) [units: MeV]
  bool is_antiparticle; // boolean: true if antiparticle
  std::vector<std::string> P_index_names = {"E/c", "p_x", "p_y", "p_z"};   // Defines vector of P_index_names and P_index_units so that the can be iterated

public:
  // Constructors
  // default constructor
  particle() = default;
  //Parameterised constructor
  particle(std::string particle_type, double particle_mass, int particle_charge, std::vector<double>* particle_four_momentum ) :
    type{particle_type}, 
    rest_mass{particle_mass},
    charge{particle_charge},
    four_momentum{particle_four_momentum}
  { 
    verify_input(particle_type, particle_mass, particle_charge, particle_four_momentum);
  }
  
  // Destructor 
  ~particle()
  {
  // need to destroy any dynamically assigned variables
    delete four_momentum; // Deallocate
    four_momentum = nullptr; // Reset the pointer to nullptr to avoid dangling pointer

    std::cout<<"Freeing memory from the four momentum. "<<std::endl;
    std::cout<<"Destroying "<<type<<std::endl;
  }

  // Function to validate input of parameterised constructor
  void verify_input(std::string particle_type, double particle_mass, int particle_charge, std::vector<double>* particle_four_momentum);

  // Getter functions read only (accessors) to the data members 
  std::string get_type() const {return type;}
  double get_rest_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  // std::vector<double> get_P() const {return (*four_momentum);}
  bool get_is_antiparticle() const {return is_antiparticle;}
  double get_E() const {return (*four_momentum)[0];}
  double get_px() const {return (*four_momentum)[1];}
  double get_py() const {return (*four_momentum)[2];}
  double get_pz() const {return (*four_momentum)[3];}
  std::vector<std::string> get_index_names() const {return P_index_names;}

  // Setter functions, to change value of data members and validate the input
  void set_type(std::string particle_type);
  void set_rest_mass(double particle_mass);
  void set_charge(int particle_charge);
  void set_four_momentum(std::vector<double>* particle_four_momentum);

  // Function to print info about a particle
  void print_data() const;

  // overload +operator to sum four momentums
  std::vector<double> operator+(const particle& particle_called) const;
  double dotProduct(const particle& particle_called) const;

  // Assignment Constructor made to do deep copy assigning.
  particle& operator=(const particle &particle_called);
};

#endif