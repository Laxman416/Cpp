// PHYS 30762 Programming in C++
// Assignment 5
// Electron Class implementation

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "Electron.h"

void Electron::verify_input(bool isAntiparticle) 
{
  if(isAntiparticle != true && isAntiparticle != false)
  {
    std::cout<<"Invalid input for if it is an antiparticle is given. Setting the object to be a particle"<<std::endl;
    is_antiparticle = false;
  }
  else
  {
    is_antiparticle = isAntiparticle;
  }
  charge = (is_antiparticle ? -1:1);
  particle_name = (is_antiparticle ? "Positron":"Electron");
  rest_mass = 0.511;
}

void Electron::print_data() const
{
  std::cout<<"Print Data for "<<particle_name<<": "<<std::endl;
  std::cout<<"\t Charge is: "<<charge<<std::endl;
  std::cout<<"\t Rest Mass is: "<<rest_mass<<" MeV"<<std::endl;
}