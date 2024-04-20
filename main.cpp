
#include<iostream>
#include<string>
#include "Lepton.h" 
#include "ChargedLepton.h" 
#include "Electron.h"
#include "CalorimeterLayers.h"


// Main program
int main()
{
  Lepton lepton;
  Electron electron(true, 5, 0, 0, 0);
  // electron.print_data();
  // electron.get_four_momentum_ptr()->set_E(120);
  electron.get_calorimeter_energies_ptr()->set_calorimeter_energy(10,20,0,0);
  // electron.get_calorimeter_energies_ptr()->print_calorimeter_info();
  electron.print_data();


  return 0;
}