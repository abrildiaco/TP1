#pragma once
#include "armas.hpp"
#include <string>

class Garrote: public ArmaCombate{
    protected:
        bool clavos; //asignado aleatoriamente y define si el garrote
                        //contiene clavos
    public:
        //constructor
        Garrote(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        void getInfo()const override; 
        void Usar() override;

        float getPeso()const override;
        bool hasClavos()const;

        //destructor
        ~Garrote();

};