#ifndef PARTICLE_H
#define PARTICLE_H

// Abstract base class (use as interface only)
class Particle
{
public:
  virtual ~Particle(){};
  virtual void print_data() const =0; // pure virtual function   

  friend std::vector<double> operator+(const Particle& particle_called_1, const Particle& particle_called_2);

  friend double dotProduct(const Particle& particle_called_1, const Particle& particle_called_2);

};

#endif