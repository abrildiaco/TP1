#pragma once

#include <string>
#include "../armas.hpp"

//material
class Baston: public ItemMagico{
    private:
        float contador_daño;
        bool tiene_gema; //la gema le otorga mas poder al baston
        bool ulti; //cuando llegas a 50 puntos de daños causados, el baston dispara un poder que causa 50 de daño
    
    public:
        //constructor
        Baston(std::string,  int); //nombre, durabilidad

        //metodos
        void getInfo()const override; 
        void Usar() override;
        float getAutoDano()const override;

        bool hasGema() const;


        //destructor
        ~Baston();
};