#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Nigromante: public Mago{
    private:
        bool revivir; //puede resucitar de la muerte en una ocasion
        
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Nigromante(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;
        void Revivir(); //resucita al nigromante si no lo ha hecho antes
        
        //destructor
        ~Nigromante();

};
