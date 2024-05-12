#ifndef CALORIMETERENERGIES_H
#define CALORIMETERENERGIES_H

#include<iostream>
#include<vector>
#include "CalorimeterLayers.h"

class CalorimeterEnergies
{
private:
  std::vector<double> calorimeter_energies; // Vector to store energy deposited in each calorimeter layer

public:
  CalorimeterEnergies(double energy_EM_1, double energy_EM_2, double energy_HAD_1, double energy_HAD_2) :
  calorimeter_energies(4, 0.0)
  {
    // Set EM_1 and EM_2 to half of the energy
    calorimeter_energies[EM_1] = energy_EM_1;
    calorimeter_energies[EM_2] = energy_EM_2;
    calorimeter_energies[HAD_1] = energy_HAD_1;
    calorimeter_energies[HAD_2] = energy_HAD_2; 
  }

  void print_calorimeter_info() const 
  {
    std::cout<<"\tCalorimeter Information:"<<std::endl;
    std::cout<<"\t\tEM_1 Energy: "<<calorimeter_energies[EM_1]<<std::endl;
    std::cout<<"\t\tEM_2 Energy: "<<calorimeter_energies[EM_2]<<std::endl;
    std::cout<<"\t\tHAD_1 Energy: "<<calorimeter_energies[HAD_1]<<std::endl;
    std::cout<<"\t\tHAD_2 Energy: "<<calorimeter_energies[HAD_2]<<std::endl;
  }

  // Getter Fn
  const std::vector<double>& getCalorimeterEnergies() const {return calorimeter_energies;}

};

#endif