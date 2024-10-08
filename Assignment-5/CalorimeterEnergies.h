#ifndef CALORIMETERENERGIES_H
#define CALORIMETERENERGIES_H

#include<iostream>
#include<vector>
#include "CalorimeterLayers.h"

class CalorimeterEnergies
{
private:
  std::vector<double> calorimeter_energies; // Vector to store energy deposited in each calorimeter layer
  std::shared_ptr<FourMomentum> four_momentum_ptr; // special shared pointer for the FourMomentum object

public:
  CalorimeterEnergies(double energy_EM_1, double energy_EM_2, double energy_HAD_1, double energy_HAD_2) :
  four_momentum_ptr(momentum_ptr),
  calorimeter_energies(4, 0.0)
  {
    // Set EM_1 and EM_2 to half of the energy
    calorimeter_energies[EM_1] = energy_EM_1;
    calorimeter_energies[EM_2] = energy_EM_2;

    // Set HAD_1 and HAD_2 to zero as electron does not deposit E here
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

  // Setter Fn
  void set_calorimeter_energy(double energy_EM_1, double energy_EM_2, double energy_HAD_1, double energy_HAD_2)
  {
    calorimeter_energies[EM_1] = energy_EM_1;
    calorimeter_energies[EM_2] = energy_EM_2;
    calorimeter_energies[HAD_1] = energy_HAD_1;
    calorimeter_energies[HAD_2] = energy_HAD_2;

    // Calculate total energy
    double total_energy = energy_EM_1 + energy_EM_2 + energy_HAD_1 + energy_HAD_2;
  }

  
};

#endif