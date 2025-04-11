#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Mercenario: public Guerrero{
    private:
        float comision; //de cada daño que recibe, se guarda una comision del 30%
                        //cuando esta comisión alcanza 30, se la devuelve en el ataque

    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Mercenario(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;    
        recibirDano(float, shared_ptr<ItemMagico>) override; 

        //destructor
        ~Mercenario();

};
