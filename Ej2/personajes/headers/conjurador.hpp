#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Hechicero: public Mago{
    private:
        std::string afinidad; //tienen afinidad con el amuleto
                            //en caso de que es sea su arma, se vuelve mas poderoso
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Hechicero(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;
        
        //destructor
        ~Hechicero();

};
