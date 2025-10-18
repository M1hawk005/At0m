#include "atom.h"

const float PROTON_MASS = 1.6726219e-27;  // in kilograms
const float NEUTRON_MASS = 1.674929e-27;  // in kilograms
const float ELECTRON_MASS = 9.10938356e-31;  // in kilograms
const float G = 6.67430e-11;  // gravitational constant

 Atom::Atom(int protons, int neutrons, int electrons, const std::array<float, 3>& position, const std::array<float, 3>& velocity)
     : m_protons(protons), m_neutrons(neutrons), m_electrons(electrons), m_position(position), m_velocity(velocity), 
       m_mass(protons * PROTON_MASS + neutrons * NEUTRON_MASS + electrons * ELECTRON_MASS){
    
 };

//Atom::Atom(const std::array<float,3>& position, const std::array<float,3>& color):m_position(position), m_color(color){
    
//}
  

const int& Atom::getMult const{ return protons; }

const std::array<float, 3>& Atom::getPosition() const { return m_position; }

const std::array<float, 3>& Atom::getColor() const { return m_color; }
