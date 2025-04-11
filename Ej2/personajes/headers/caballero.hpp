#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Caballero: public Guerrero{
    private:
        std::string afinidad; //tiene afinidad con la espada
        int armadura; //tiene una armadura que inicia en 10 y baja
                    //cada vez que recibe daño, pero lo protege
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Caballero(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;
        bool recibirDano(float, std::shared_ptr<ItemMagico>);
        
        //destructor
        ~Caballero();

};
