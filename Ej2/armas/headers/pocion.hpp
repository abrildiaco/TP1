#pragma once

#include <string>
#include <memory>
#include <vector>
#include "../armas.hpp"

/*
Existen dos tipos de pociones: veneno, inmunidad
-en cada ataque se asigna de manera aleatoria un tipo de pocion
-Inmunidad: si la uso, no puedo recibir daño cuando el oponente ataque (ni me hago auto daño)
-Veneno: la pocion de veneno le hacele genero daño al oponente.
los efectos de la poción duran una ronda.
*/

class Pocion: public ItemMagico{
    private:
        std::vector<std::string> tipo; //veneno, inmunidad
        std::string tipo_actual;
        //int duracion_efecto; //cuanto dura su efecto en turnos

    public:
        //constructor
        Pocion(std::string,  int); //nombre, durabilidad

        //metodos
        void getInfo()const override; 
        void Usar() override;
        float getAutoDano()const override;

        std::string getTipo() const;
        //int getDuracionEfecto()const;


        //destructor
        ~Pocion();
    
};
