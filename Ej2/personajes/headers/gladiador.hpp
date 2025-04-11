#pragma once

#include <string>
#include <memory>
#include "../../armas/armas.hpp"
#include "../personajes.hpp"

class Gladiador: public Guerrero{
    private:
        int nivelIntimidante; //se le genera un nivel de intimidacion al gladiador
                            //de manera aleatoria [1, 10]. segun el nivel, recibira menos daño
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Gladiador(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, poder, fuerza, arma1, arma2

        //metodos
        void getInfo()const override; 
        void Curar() override;
        float Atacar(std::shared_ptr<Arma>) override;    
        bool recibirDano(float, std::shared_ptr<ItemMagico>) override; 

        //destructor
        ~Gladiador();

};
