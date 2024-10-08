// Assignment 1

// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include <cmath>
#include<iomanip>
#include <string>
#include <tuple>

float energy_calculation(float atomic_number_local, int initial_principle_quantum_number_local, int final_principle_quantum_number_local, std::string output_units_local)   
{
  // This function uses the atomic number and both quantum numbers to give the energy in Joules or eV
  // Conversion factor to convert between eV to J.
  const float conversion_factor{1.602e-19};
  // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
  float energy_local = 13.6 * std::pow(atomic_number_local, 2) * (1.0 / std::pow(final_principle_quantum_number_local, 2)
   - 1.0 / std::pow(initial_principle_quantum_number_local, 2));

  // Convert energy if user wanted
  if(output_units_local == "J")
  {
    energy_local *= conversion_factor;
  }  

  return energy_local;
}

std::tuple<int, int, int, std::string> ask_for_input(int initial_principle_quantum_number_local, int final_principle_quantum_number_local,int  atomic_number_local, std::string output_units_local)
{
  // This function asks the user for the inputs and tests them if they are valid

  // Ask user to enter atomic number
  std::cout<<"What is the atomic number of the atom?: "<<std::endl;
  while(!(std::cin>>atomic_number_local) || atomic_number_local <= 0) // while atomic number gives an error or is less than 0 reruns
  {
    std::cout<<"Invalid input. Please enter a positive integer for atomic number: "<<std::endl;
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
  }

  // Ask user to enter initial and final principle quantum numbers
  std::cout<<"What is the initial principle quantum number of the electron?: "<<std::endl;
  // while initial principle quantum number gives an error or is less than 0 reruns
  while(!(std::cin>>initial_principle_quantum_number_local) || initial_principle_quantum_number_local <= 0) 
  {
    std::cout<< "Invalid input. Please enter a positive integer for initial principle quantum number: " << std::endl;
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
  }  

  std::cout<<"What is the final principle quantum number of the electron?: "<<std::endl;
  // while final principle quantum number gives an error, is less than 0, greater than initial principle quantum number reruns
  while(!(std::cin>>final_principle_quantum_number_local) || final_principle_quantum_number_local <= 0 || final_principle_quantum_number_local > initial_principle_quantum_number_local)
  {
    if(final_principle_quantum_number_local > initial_principle_quantum_number_local) 
    {
      std::cout<< "Invalid input. The final principle quantum number has to be lower than inital principle quantum number. \nPlease enter a valid final principle quantum number: " << std::endl;
      std::cin.clear();  // Clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
    }  
    else
    {
      std::cout<< "Invalid input. Please enter a positive integer for initial principle quantum number: " << std::endl;
      std::cin.clear();  // Clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
    }
  }  

  // Ask user if the output of energy is in joules or eV
  std::cout<<"Do you want the output to be in joules or eV? (J/eV): "<<std::endl;
  // while output_units gives an error is not in the desired format rerun 
  while(!(std::cin>>output_units_local) || output_units_local != "J" && output_units_local != "eV")
  {
    std::cout<< "Invalid input. Please choose either 'J' or 'eV': " << std::endl;
    std::cin.clear();  // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard all characters of invalid input
  }  

  return std::make_tuple(atomic_number_local, initial_principle_quantum_number_local, final_principle_quantum_number_local, output_units_local); 
}

int main()
{
  // Declare variables here
  int initial_principle_quantum_number;
  int final_principle_quantum_number;
  int atomic_number;
  float energy;
  std::string output_units;
  char repeat{'n'};

  do
  {
    // Call function to ask for for input variables from user
    std::tie(atomic_number, initial_principle_quantum_number, final_principle_quantum_number, output_units) = ask_for_input(initial_principle_quantum_number, final_principle_quantum_number, atomic_number, output_units);

    // Call function to compute energy
    energy = energy_calculation(atomic_number, initial_principle_quantum_number, final_principle_quantum_number, output_units);
    // Output answer
    if(output_units == "eV")
    {
      std::cout<<"The energy is: "<<std::setprecision(3)<<energy<<" eV"<<std::endl;
    }
    else if(output_units == "J")
    {
      std::cout<<"The energy is: "<<std::setprecision(3)<<energy<<" J"<<std::endl;
    }

    //Ask to repeat the code
    std::cout<<"Do you want to repeat the calculation for different values? (y/n): "<<std::endl;
    while(!(std::cin>>repeat) || repeat != 'y' && repeat != 'n')
    {
      std::cout<< "Invalid input. Please choose either 'y' or 'n': " << std::endl;
      std::cin.clear();  // Clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
    }
  } while(repeat == 'y');
  
  return 0;
}