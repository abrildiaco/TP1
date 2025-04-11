#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Barbaro: public Guerrero{
    private:
        std::string afinidad; //tiene afinidad con el hacha simple
                                //si le toca hace mas daño
        bool ira; //se activa la ira cuando le hacen mucho daño
                //en un mismo ataque --> devielve con el dombre de fuerza

    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Barbaro(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;
        bool recibirDano(float, std::shared_ptr<ItemMagico>) override;
        void activarIra();
        
        //destructor
        ~Barbaro();

};
