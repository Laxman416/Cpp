#ifndef PARTICLE_H
#define PARTICLE_H

#include<string>
#include<memory>
#include "FourMomentum.h"

// Abstract base class (use as interface only)
class Particle
{
protected:
  double spin; // boolean: true if antiparticle
  double rest_mass; // in MeV
  std::string name;
  bool m_is_antiparticle; // boolean: true if antiparticle
  std::unique_ptr<FourMomentum> four_momentum_ptr; // special unique pointer for the FourMomentum object
  double charge;

public:
// Parameterised Constructor for Lepton
 Particle(double particle_charge, bool is_antiparticle, double particle_mass, std::string particle_name, double particle_energy, double particle_px, double particle_py, double particle_pz, double particle_spin) : 
    spin{particle_spin},
    rest_mass{particle_mass},
    name{particle_name},
    m_is_antiparticle{is_antiparticle},
    charge{particle_charge},
    four_momentum_ptr(std::make_unique<FourMomentum>(particle_energy, particle_px, particle_py, particle_pz))
  {
    verify_input(is_antiparticle);
  }
  // Verify Input
  void verify_input(bool is_antiparticle);

  virtual ~Particle(){};
  virtual void print_data() const =0; // pure virtual function   

  void set_four_momentum_ptr(std::unique_ptr<FourMomentum> momentum_ptr){four_momentum_ptr = std::move(momentum_ptr);}
  // Setter Fn that should be overidden in derived classes
  virtual void set_rest_mass(double particle_mass);
  virtual void set_name(std::string particle_name){name = particle_name;}

  // Getter Fn
  double get_spin() const {return spin;}
  double get_rest_mass() const {return rest_mass;}
  double get_charge() const {return charge;}
  double get_is_antiparticle() const {return m_is_antiparticle;}
  std::string get_name() const {return name;}
  const std::unique_ptr<FourMomentum>& get_four_momentum_ptr() const { return four_momentum_ptr; }

  friend std::vector<double> operator+(const Particle& particle_called_1, const Particle& particle_called_2);

  friend double dotProduct(const Particle& particle_called_1, const Particle& particle_called_2);

  Particle(const Particle &particle_called); // Copy Constructor
  Particle(Particle &&particle_called); // Move Constructor

  // Assignment operator made to do deep copy assigning.
  Particle& operator=(const Particle &particle_called);

  // Move assignment operator using function overloading
  Particle& operator=(Particle&& particle_called_to_move);
};

#endif