// PHYS 30762 Programming in C++
// Assignment 3 - detector class

#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream>
#include<string>
#include "particle.h"

// Beginning of detector class
class detector
{
private:
  // data members
  std::string detector_type; // a tracker, a calorimeter, a muon chamber
  bool status; // On or Off
  int particles_passed;

public:
  // Constructors
  // default constructor
  detector() = default;
  //Parameterised constructor
  detector(std::string new_detector_type, bool new_status) :
    detector_type(new_detector_type),
    status(new_status) 
    {
      verify_input_constructor(new_detector_type, new_status);
    }
  
  // Destructor 
  ~detector(){std::cout<<"Destroying "<<detector_type<<std::endl;}

  // Validate input of paramterised constructor
  void verify_input_constructor(std::string new_detector_type, bool new_status);

  // Getter functions read only (accessors) to the data members 
  std::string get_detector_type() const {return detector_type;}
  bool get_status() const {return status;}

  // Setter functions, to change value of data members and validate the input
  void set_detector_type(std::string new_detector_type);
  void turn_on() {status = true;}
  void turn_off() {status = false;} 

  // Function to check if particle is detected
  int check_particle_detected(const particle& p) const; // keeps detector and particle const

  // Function to print info about a detector
  void print_data() const;

};

#endif