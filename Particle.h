#ifndef PARTICLE_H
#define PARTICLE_H

// Abstract base class (use as interface only)
class Particle
{
public:
  virtual ~Particle(){};
  virtual void print_data() const =0; // pure virtual function   

};

#endif