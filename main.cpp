
#include<iostream>
#include<string>
#include "Lepton.h" 
#include "ChargedLepton.h" 
#include "Electron.h" 

// Main program
int main()
{
  Electron electron(true, 1, 0, 0, 0);
  electron.print_data();
  // electron.get_four_momentum_ptr()->set_E(120);
  return 0;
}