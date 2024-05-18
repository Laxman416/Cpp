#include "ParticleCatalogue.h"
#include<iostream>

void ParticleCatalogue::add_particle(const SafeSharedPtr<Particle>& particle) 
{
  std::string particle_type;
  std::string key;
  if(particle->get_name() == "null")
  {
    particle_type = "null";
    key = "null";
  }
  else
  {
    // Generate a unique key for the particle
    std::ostringstream key_stream;
    key_stream << particle->get_name() << "_" << particle_count[particle->get_name()] + 1;
    key = key_stream.str();
    particle_type = particle->get_type();
  }
  
  // Insert the particle into the multimap with the generated key
  particle_container.insert({key, {particle, particle_type}});

  // Increment the count for this particle type
  particle_count[particle->get_name()]++;
}

SafeSharedPtr<Particle> ParticleCatalogue::operator[](const std::string& key) 
  {
    auto it = particle_container.find(key);
    if (it == particle_container.end()) 
    {
      // Key not found, return a default value (nullptr)
      std::cerr << "Key not found: " << key << std::endl;
      return nullptr;
    }
    else
    {
      // Key found, return the associated particle
      return it->second.first;
    }
  }

std::string ParticleCatalogue::get_label(const std::pair<SafeSharedPtr<Particle>, std::string>& particle_entry) const 
{
  return particle_entry.second;
}

void ParticleCatalogue::print_particles_with_key() const 
{
  std::cout<<"------------------------------------------"<<std::endl;
  for (const auto& particle_entry : particle_container) 
  {
    std::cout << "Key: " << particle_entry.first << ", Particle Type: " << particle_entry.second.second << std::endl;
  }
  std::cout<<"------------------------------------------"<<std::endl;

}

void ParticleCatalogue::print_particles_count_by_type() const 
{
  std::map<std::string, int> particle_type_counts;
  for (const auto& particle_entry : particle_container) 
  {
    const std::string& particle_type = particle_entry.second.second;
    particle_type_counts[particle_type]++;  }

  std::cout<<"Particle count by type:"<<std::endl;
  for (const auto& type_count_pair : particle_type_counts) 
  {
    const std::string& particle_type = type_count_pair.first;
    int count = type_count_pair.second;
    std::cout<<"\tType: "<<particle_type <<" has "<<count<<" counts."<<std::endl;
  }
}

int ParticleCatalogue::get_total_count_of_a_type(const std::string& particle_type) const {
  int count = 0;
  for (const auto& particle_entry : particle_container) {
    if(particle_entry.second.second == particle_type) 
    {
      count = count + 1;
    }
  }
  return count;
}

  void ParticleCatalogue::print_all_particles() const
  {
    std::cout<<"------------------------------------------"<<std::endl;
    for (const auto& particle_entry : particle_container) 
    {
      std::cout<<"Key: "<<particle_entry.first<<std::endl;
      particle_entry.second.first->print_data();
      std::cout<<"------------------------------------------"<<std::endl;

    }
  }

std::vector<double> ParticleCatalogue::sum_four_momentum() const 
{
  std::vector<double> total_momentum(4,0.0);
  // Iterate over all particles in the container
  if(particle_container.size() >= 2)
  { 
    for (const auto& particle_entry : particle_container) 
    {
      // Get the particle
      const auto& particle = particle_entry.second.first;
      // Add the four-momentum of the particle to the total
      total_momentum = total_momentum + *particle;
    }
  }
  else 
  {
    std::cout<<"Insufficient particles to calculate momentum."<<std::endl;
  }
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<"Sum of all Four Momentums in Container."<<std::endl;
  std::cout<<"\tE: "<<total_momentum[0]<<" MeV/c"<<std::endl;
  std::cout<<"\tpx: "<<total_momentum[1]<<" MeV/c"<<std::endl;
  std::cout<<"\tpy: "<<total_momentum[2]<<" MeV/c"<<std::endl;
  std::cout<<"\tpz: "<<total_momentum[3]<<" MeV/c"<<std::endl;
  std::cout<<"------------------------------------------"<<std::endl;
  std::cout<<""<<std::endl;
  return total_momentum;
}

ParticleCatalogue ParticleCatalogue::get_container_of_a_type(const std::string& particle_type) const 
{
  ParticleCatalogue new_catalogue;

  for (const auto& particle_entry : particle_container) {
    const auto& particle = particle_entry.second.first;
    const std::string& label = particle_entry.second.second;

    if (label == particle_type) {
        new_catalogue.add_particle(particle);
    }
  }
  return new_catalogue;
}

// Assignment Constructor to do Deep Copying
ParticleCatalogue& ParticleCatalogue::operator=(const ParticleCatalogue &particle_catalogue_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&particle_catalogue_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
 
  this->particle_container = particle_catalogue_called.particle_container;
  this->particle_count = particle_catalogue_called.particle_count;
  return *this;
}

ParticleCatalogue::ParticleCatalogue(const ParticleCatalogue &particle_catalogue_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  {
    // Copies all data members from particle_called to current catalogue
    
  this->particle_container = particle_catalogue_called.particle_container;
  this->particle_count = particle_catalogue_called.particle_count;
  }
}

ParticleCatalogue& ParticleCatalogue::operator=(ParticleCatalogue &&particle_catalogue_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &particle_catalogue_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  // Move the data members
  particle_container = std::move(particle_catalogue_called_to_move.particle_container);
  particle_count = std::move(particle_catalogue_called_to_move.particle_count);

  return *this;
}

ParticleCatalogue::ParticleCatalogue(ParticleCatalogue &&particle_catalogue_called_to_move)
{
  std::cout<<"Calling Move Constructor"<<std::endl;
  {
    // Move the data members
    particle_container = std::move(particle_catalogue_called_to_move.particle_container);
    particle_count = std::move(particle_catalogue_called_to_move.particle_count);
  }
}


