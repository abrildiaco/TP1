#pragma once
#include "../armas.hpp"
#include <string>

class HachaSimple: public ArmaCombate{
    protected:
        int filo; //inician con filo de 10, en cada golpe baja el filo y daña menos

    public:
        //constructor
        HachaSimple(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        void getInfo()const override; 
        void Usar() override;

        float getPeso()const override;
        void Afilar();

        //destructor
        ~HachaSimple();

};