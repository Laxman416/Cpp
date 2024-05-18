// PHYS 30762 Programming in C++
// Assignment 5- four momentum class

#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<string>
#include<cmath>
#include<vector>

#define light_speed 2.99792458e8

// Beginning of four_momentum class
class FourMomentum
{
private:
  double E;
  double px;
  double py;
  double pz;
  double rest_mass; // Need to verify E input
  bool m_is_particle; // a boolean to use to be able to only change rest_mass if false, otherwise it is tied to the particle object.

public:
  // Constructors
  FourMomentum() = default;  // default constructor
  FourMomentum(const FourMomentum &four_momentum_called); // Copy Constructor
  FourMomentum(FourMomentum &&four_momentum_called); // Move Constructor
  //Parameterised constructor
  FourMomentum(double particle_energy, double particle_px, double particle_py, double particle_pz, double particle_mass, bool is_particle ) :
    E{particle_energy}, 
    px{particle_px},
    py{particle_py},
    pz{particle_pz},
    rest_mass{particle_mass},
    m_is_particle{is_particle}
  { 
    verify_energy(particle_energy, particle_px, particle_py, particle_pz, particle_mass);
  }
  
  // Destructor 
  ~FourMomentum()
  {
    std::cout<<"Destroying FourMomentum Object"<<std::endl;
  }

  // Function to validate input of parameterised constructor
  void verify_energy(double particle_energy, double particle_px, double particle_py, double particle_pz, double particle_name);

  // Getter functions read only (accessors) to the data members
  double get_E() const {return E;}
  double get_px() const {return px;}
  double get_py() const {return py;}
  double get_pz() const {return pz;}
  double get_rest_mass() const {return rest_mass;}

  // Setter functions, to change value of data members and validate the input
  // Avaliable in case you want to use FourMomentum without other objects as it doesn't require the mass of the particle.
  void set_E(double particle_energy);
  void set_px(double particle_px);
  void set_py(double particle_py);
  void set_pz(double particle_pz);
  void set_rest_mass(double particle_mass);

  // Function to print info about a particle
  void print_data() const;
  
  // overload +operator to sum four momentums
  std::vector<double> operator+(const FourMomentum& four_momentum_called) const;
  std::vector<double> operator+(const std::vector<double>& std_vector_called) const;

  double dotProduct(const FourMomentum& four_momentum_called) const;

  // overload +operator to subtract four momentums
  std::vector<double> operator-(const FourMomentum& four_momentum_called) const;
  
  // Assignment operator made to do deep copy assigning.
  FourMomentum& operator=(const FourMomentum &four_momentum_called);

  // Move assignment operator using function overloading
  FourMomentum& operator=(FourMomentum&& four_momentum_to_move);

  // Calculate Invariant Mass
  double get_invariant_mass_from_four_momentum() const {return sqrt(E * E - px * px - py * py - pz * pz);}
};

#endif