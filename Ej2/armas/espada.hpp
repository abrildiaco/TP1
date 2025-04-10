#pragma once
#include "armas.hpp"
#include <string>

class Espada: public ArmaCombate{
    protected:
        int filo; //inician con filo de 10, en cada golpe baja el filo y daña menos
        bool diamante; //por un factor aleatorio te puede tocar una espada de diamante
                        //hace mas daño y no pierde filo

    public:
        //constructor
        Espada(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        void getInfo()const override; 
        void Usar() override;

        float getPeso()const override;
        void Afilar();
        bool hasDiamante()const;

        //destructor
        ~Espada();

};