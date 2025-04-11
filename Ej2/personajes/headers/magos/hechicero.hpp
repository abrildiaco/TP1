#pragma once

#include <string>
#include <memory>
#include "../armas/armas.hpp"
#include "../personajes/personajes.hpp"

class Hechicero: public Mago{
    private:
        std::string afinidad; //tienen afinidad con el libro e hechizos
                            //en caso de que es sea su arma, se vuelve mas poderoso
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Hechicero(std::string, float, std::unique_ptr<Arma>); //nombre, poder, fuerza, arma

        //metodos
        void getInfo()const override; 
        void Curar() override;
        void Atacar() override;
        

        //destructor
        ~Hechicero();

};
