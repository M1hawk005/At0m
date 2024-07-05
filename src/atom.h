#ifndef ATOM_H
#define ATOM_H
#include<iostream>
#include <array>
#include <cmath>

class Atom{
    public:
        //Atom(int proton, int neutrons, int electron, const std::array<float,3>& position, const std::array<float,3>& velocity);

        Atom(const std::array<float,3>& position, const std::array<float,3>& color);

        const std::array<float, 3>& getPosition() const; 
        const std::array<float, 3>& getColor() const; 


    private:
        int m_protons;
        int m_neutrons;
        int m_electrons;
        float m_mass;
        std::array<float,3> m_position;
        std::array<float,3> m_velocity;
        std::array<float,3> m_color;


};

#endif //ATOM_H