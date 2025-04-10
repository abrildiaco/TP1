#pragma once
#include "armas.hpp"
#include <string>

class HachaDoble: public ArmaCombate{
    protected:
        int filo; //inician con filo de 10, en cada golpe baja el filo y daña menos

    public:
        //constructor
        HachaDoble(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        void getInfo()const override; 
        void Usar() override;

        float getPeso()const override;
        void Afilar();

        //destructor
        ~HachaDoble();

};