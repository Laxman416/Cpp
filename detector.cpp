// PHYS 30762 Programming in C++
// Assignment 3 - Implementation of detector class
// Practice with C++ classes and their interactions

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "detector.h"
#include "particle.h" 

void detector::verify_input_constructor(std::string new_detector_type, bool new_status)
{
  // Validate and set detector type
  if (new_detector_type == "tracker" || new_detector_type == "calorimeter" || new_detector_type == "muon chamber") 
  {
    detector_type = new_detector_type;
  } 
  else 
  {
    // Invalid detector type, Settign detector type to be tracker
    std::cout<<"Invalid detector type."<<std::endl;
    std::cout<<"Setting detector type to be tracker."<<std::endl;
    detector_type = "tracker";
  }

  // Validate and set status
  if (new_status == true || new_status == false) 
  {
    status = new_status;
  } 
  else 
  {
    // Invalid status type, setting status false
    std::cout<<"Invalid status type."<<std::endl;
    std::cout<<"Setting status type to false (off)."<<std::endl;
    status = false;
  }
}

// Setter functions, to change value of data members and validate the input
void detector::set_detector_type(std::string new_detector_type)
{
 // Validate and set detector type
  if (new_detector_type == "tracker" || new_detector_type == "calorimeter" || new_detector_type == "muon chamber") 
  {
    detector_type = new_detector_type;
  } 
  else 
  {
    // Invalid detector type, Settign detector type to be tracker
    std::cerr<<"Error: Invalid detector type. Choose between 'tracker', 'calorimeter', 'muon chambers.'"<<std::endl;
    std::cerr<<"Error: Type of detector not updated."<<std::endl;
  }
}

// Function to print data 
void detector::print_data() const
{
  std::cout<<"Detector Type: "<<detector_type<<std::endl;
  std::cout<<"Status: "<<(status ? "On" : "Off")<<std::endl; // ternary conditional operator
}
    
int detector::check_particle_detected(const particle& particle_in_detector) const
{
  if (status == false)
  {
    std::cout<<"Detector is off. "<<particle_in_detector.get_type()<<" is not detected"<<std::endl;
    return 0;
  }
  else
  {
    std::string type_of_particle = particle_in_detector.get_type();
    if (detector_type == "tracker" && (type_of_particle == "muon" || type_of_particle == "antimuon" || type_of_particle == "electron" || type_of_particle == "positron")) 
    {
      std::cout<<particle_in_detector.get_type()<<" was detected."<<std::endl;
      return 1;
    }
    else if (detector_type == "calorimeter" && (type_of_particle == "electron" || type_of_particle == "positron"))
    {
      std::cout<<particle_in_detector.get_type()<<" was detected."<<std::endl;
      return 1;
    }
    else if (detector_type == "muon chamber" && (type_of_particle == "muon" || type_of_particle == "antimuon"))
    {
      std::cout<<particle_in_detector.get_type()<<" was detected."<<std::endl;
      return 1;
    }
    else
    {
      return 0;
    }    
  }
}
