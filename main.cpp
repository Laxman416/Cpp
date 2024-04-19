#include<iostream>
#include<string>
#include "Lepton.h" 
#include "ChargedLepton.h" 
#include "Electron.h" 

class particle
{
public:
  virtual ~particle(){} // Need this!
  virtual void info()=0; // pure virtual function   
};

// Main program
int main()
{
  std::vector<std::unique_ptr<particle>> particles;

  Electron electron(true);
  electron.print_data();
  return 0;
}