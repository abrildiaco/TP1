#pragma once
#include "armas.hpp"
#include <string>

class Lanza: public ArmaCombate{
    protected:
        int filo; //inician con filo de 10, en cada golpe baja el filo y daña menos
        int punteria; //en cada uso, se genera una variable random entre [0, 5]
                    //que determina el daño extra que hace la lanza segun la punteria
    public:
        //constructor
        Lanza(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        void getInfo()const override; 
        void Usar() override;

        float getPeso()const override;
        void Afilar();
        int getPunteriaActual()const;

        //destructor
        ~Lanza();

};