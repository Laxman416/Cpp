// PHYS 30762 Programming in C++
// Assignment 3 - particle class

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
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
  bool is_antiparticle; // boolean: true if antiparticle


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
    verify_input(particle_type, particle_mass, particle_charge, particle_velocity);
  }
  
  // Destructor 
  ~particle(){std::cout<<"Destroying "<<type<<std::endl;}

  // Function to validate input of parameterised constructor
  void verify_input(std::string particle_type, double particle_mass, int particle_charge, double particle_velocity);

  // Getter functions read only (accessors) to the data members 
  std::string get_type() const {return type;}
  double get_rest_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  double get_velocity() const {return velocity;}
  double get_beta() const {return beta;}
  bool get_is_antiparticle() const {return is_antiparticle;}

  // Setter functions, to change value of data members and validate the input
  void set_type(std::string particle_type);
  void set_rest_mass(double particle_mass);
  void set_charge(int particle_charge);
  void set_velocity(double particle_velocity);
  void set_beta(double particle_beta);

  // Function to print info about a particle
  void print_data() const;
};

#endif
