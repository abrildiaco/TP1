#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Paladin: public Guerrero{
    private:
       bool juicio_solar; //le herela más daños a aquellos oponentes oscuros
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Paladin(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;
        void activarJuicioSolar(); //se llama cuando el contrincante es
                                    //un nigromante o un brujo    
        
        //destructor
        ~Paladin();

};
