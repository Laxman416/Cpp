#include<iostream>
#include<string>
#include "Quark.h"

std::string Quark::get_type() const
{
  std::string particle_type;
  if(m_is_up_type)
  {
    particle_type = "Up-type Quark";
  }
  else
  {
    particle_type = "Down-type Quark";
  }
  return particle_type;
}

std::string Quark::verify_input_color_charge(const std::string& particle_colour_charge) const
{
  if(this->m_is_antiparticle)
  {
    if(particle_colour_charge != "antired" && particle_colour_charge != "antigreen" && particle_colour_charge != "antiblue")
    {
      std::cerr<<"\033[1;31mError\033[0m: Invalid value for 'particle_colour_charge'. Defaulting to 'antired'."<<std::endl;
      return "antired";
    }
    else
    {
      return particle_colour_charge;
    }
  }
  else
  {
    if(particle_colour_charge != "red" && particle_colour_charge != "green" && particle_colour_charge != "blue")
    {
      std::cerr<<"\033[1;31mError\033[0m: Invalid value for 'particle_colour_charge'. Defaulting to 'red'."<<std::endl;
      return "red";
    }
    else
    {
      return particle_colour_charge;
    }
  }
}

double Quark::verify_input(bool is_antiparticle)
{
  if(is_antiparticle != true && is_antiparticle != false)
  {
    std::cout<<"\033[1;31mWarning\033[0m:: Invalid value for 'is_antiparticle' parameter. Defaulting to false."<<std::endl;
    is_antiparticle = false;
  }
  m_is_antiparticle = is_antiparticle;
  // initialise baryon number depending on is_antiparticle
  double particle_baryon_number;
  if(m_is_antiparticle)
  {
    particle_baryon_number = (-1.0/3);
  }  
  else
  {
    particle_baryon_number = (1.0/3);
  }
  return particle_baryon_number;
}

void Quark::print_data() const
{
  // // need to use getters from Quark and Paritcle
  std::cout<<"Print Data for "<<this->get_name()<<": "<<std::endl;
  std::cout<<"\tRest Mass is: "<<this->get_rest_mass()<<" MeV"<<std::endl;
  std::cout<<"\tCharge is: "<<this->get_charge()<<std::endl;
  std::cout<<"\tSpin is: "<<this->get_spin()<<std::endl;
  std::cout<<"\tIs it an antiparticle: "<<(this->get_is_antiparticle() ? "true" : "false")<<std::endl;
  std::cout<<"\tBaryon Number: "<<(this->get_baryon_number())<<std::endl;
  std::cout<<"\tColour Charge: "<<(this->get_colour_charge())<<std::endl;
  std::cout<<"\tIs it an up-type quark: "<<(this->get_is_up_type() ? "true" : "false")<<std::endl;

  // Call print_data() function on the four_momentum_ptr object
  if(four_momentum_ptr != nullptr) 
  {
    four_momentum_ptr->print_data();
  } 
  else 
  {
    std::cout<<"Four Momentum Data not available"<<std::endl;
  }
};

void Quark::set_baryon_number(double particle_baryon_number)
{
  // Particle mass can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Baryon Number is fixed for the type of quark (up/down) and antiparticle status."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Baryon Number of particle not updated."<<std::endl; }

void Quark::set_rest_mass(double particle_mass)
{
  // Particle mass can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Quark has a fixed mass and cannot be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Rest mass of particle not updated."<<std::endl;    
}

void Quark::set_name(std::string particle_name)
{
  // Particle name can't be changed in Electron
  std::cerr<<"\033[1;31mError\033[0m: Quark particle can not be changed."<<std::endl;
  std::cerr<<"\033[1;31mError\033[0m: Name of particle not updated."<<std::endl;    
}

void Quark::set_is_antiparticle(bool is_antiparticle)
{
  if(this->m_is_antiparticle == is_antiparticle)
  {
    std::cerr<<"\033[1;31mError\033[0m: Quark is already in desired state."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Particle not updated."<<std::endl;    
  }
  else
  {
    this->m_is_antiparticle = is_antiparticle;
    this->charge = get_particle_charge_from_up_type(m_is_antiparticle, m_is_up_type);
    this->name = get_particle_name_from_flavour(m_is_antiparticle, flavour, m_is_up_type);
    this->baryon_number = m_is_antiparticle ? (-1.0/3): (1.0/3);
    std::cerr<<"Particle updated. The name, charge, boolean and baryon number data members are modified."<<std::endl;    
  }
}

void Quark::set_is_up_type(bool is_up_type)
{
  if(m_is_up_type == is_up_type)
  {
    std::cerr<<"\033[1;31mError\033[0m: Quark is already in desired state."<<std::endl;
    std::cerr<<"\033[1;31mError\033[0m: Particle not updated."<<std::endl;    
  }
  else
  {
    m_is_up_type = is_up_type;
    this->charge = get_particle_charge_from_up_type(m_is_antiparticle, is_up_type);
    this->name = get_particle_name_from_flavour(m_is_antiparticle, flavour, is_up_type);
    this->rest_mass = get_particle_mass_from_flavour(m_is_antiparticle, is_up_type);

    std::cerr<<"Particle updated. The mass, name, charge, boolean data members are modified."<<std::endl;    
  }
}



std::string Quark::get_particle_name_from_flavour(bool is_antiparticle, int particle_flavour, bool is_up_type) const 
{
  std::string particle_name;
  if(is_up_type)
  {
    switch (particle_flavour) 
    {
      case 1:  // Up quark
        particle_name = is_antiparticle ? "Antiup" : "Up";
        break;
      case 2:  // Charm quark
        particle_name = is_antiparticle ? "Anticharm" : "Charm";
        break;
      case 3:  // Top quark
        particle_name = is_antiparticle ? "Antitop" : "Top";
        break;
      default:
        particle_name = "Unknown quark";
        break;
    }
  }
  else
  {
    switch (particle_flavour) 
    {
      case 1:  // Down quark
        particle_name = is_antiparticle ? "Antidown" : "Down";
        break;
      case 2:  // Strange quark
        particle_name = is_antiparticle ? "Antistrange" : "Strange";
        break;
      case 3:  // Bottom quark
        particle_name = is_antiparticle ? "Antibottom" : "Bottom";
        break;
      default:
        particle_name = "Unknown quark";
        break;
    }
  }
  return particle_name;
}

double Quark::get_particle_mass_from_flavour(bool is_up_type, int particle_flavour) const 
{
  double particle_mass;
  if(is_up_type)
  {
    switch (particle_flavour) 
    {
      case 1:  // Up quark
        particle_mass = 2.16;
        break;
      case 2:  // Charm quark
        particle_mass = 1027.0;
        break;
      case 3:  // Top quark
        particle_mass = 172000.0;
        break;
      default:
        particle_mass = 0.0;
        break;
    }
  }
  else
  {
    switch (particle_flavour) 
    {
      case 1:  // Down quark
        particle_mass = 4.67;
        break;
      case 2:  // Strange quark
        particle_mass = 93.4;
        break;
      case 3:  // Bottom quark
        particle_mass = 4180.0;
        break;
      default:
        particle_mass = 0.0;
        break;
    }
  }
  return particle_mass;
}

double Quark::get_particle_charge_from_up_type(bool is_antiparticle, bool is_up_type) const 
{
  double particle_charge;
  if(is_up_type)
  {
    if(is_antiparticle) 
    {
      // anti-type quark
      particle_charge = -2.0/3.0;
    }
    else
    {
      // uptype quark
      particle_charge = 2.0/3.0;
    }
  }
  else
  {
    if(is_antiparticle) 
    {
      // anti-down quark
      particle_charge = 1.0/3.0;
    }
    else
    {
      // downtype quark
      particle_charge = -1.0/3.0;
    }
  }
  return particle_charge;
}


// Assignment Constructor to do Deep Copying
Quark& Quark::operator=(const Quark &quark_called)
{
  std::cout<<"Calling Assignment Constructor"<<std::endl;
  // Assignment Constructor replaces existing object with another existing object.
  // Deep Copying Assignment implemented
  // RHS assigned to LHS
  // Need to delete dynamically allocated memory otherwise will cause memory leak

  // no self-assignment
  if(&quark_called == this)
  {
    return *this;
  } 
  // Assigns all data members from lepton_called to current particle
  // Deep Copying implemented
  Particle::operator=(quark_called);
  this->baryon_number = quark_called.baryon_number;
  this->colour_charge = quark_called.colour_charge;
  this->m_is_up_type = quark_called.m_is_up_type;
  this->flavour = quark_called.flavour;

  return *this;
}

Quark::Quark(const Quark &quark_called) : Particle(quark_called)
{
  std::cout<<"Calling Copy Constructor"<<std::endl;

  // Copies all data members from lepton_called to current particle
  this->baryon_number = quark_called.baryon_number;
  this->colour_charge = quark_called.colour_charge;
  this->m_is_up_type = quark_called.m_is_up_type;
  this->flavour = quark_called.flavour;
}

Quark& Quark::operator=(Quark &&quark_called_to_move)
{
  std::cout<<"Calling Move Assignment operator"<<std::endl;

  // Check for self-moving
  if(this == &quark_called_to_move)
  {
    std::cout<<"Self-moving detected in move assignment operator. Skipping move."<<std::endl;
    return *this;
  }
  else
  {
    // Move the data members
    Particle::operator=(std::move(quark_called_to_move));
    baryon_number = std::move(quark_called_to_move.baryon_number);
    colour_charge = std::move(quark_called_to_move.colour_charge);
    m_is_up_type = std::move(quark_called_to_move.m_is_up_type);
    flavour = std::move(quark_called_to_move.flavour);


  }
    
  return *this;
}

Quark::Quark(Quark &&quark_called_to_move) : Particle(std::move(quark_called_to_move))
{
  std::cout<<"Calling Move Constructor"<<std::endl;

  baryon_number = std::move(quark_called_to_move.baryon_number);
  colour_charge = std::move(quark_called_to_move.colour_charge);
  m_is_up_type = std::move(quark_called_to_move.m_is_up_type);
  flavour = std::move(quark_called_to_move.flavour);

}





