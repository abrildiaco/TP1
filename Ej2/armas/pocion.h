#pragma once

#include <string>
#include <memory>
#include "armas.h"

/*
dos tipos de pociones: veneno, inmunidad
si es de inmunidad y la uso, no puedo recibir daño (ni me hago auto daño)
solo la pocion de veneno le hace daño al oponente.
los efectos de la poción duran dos rondas.
*/

class Pocion: public ItemMagico{
    private:
        std::string tipo; //veneno, inmunidad
        int duracion_efecto; //cuanto dura su efecto en turnos

    public:
        //constructor
        Pocion(int, std::string, std::string); //nombre, durabilidad, tipo

        //metodos
        void getInfo()const override; 
        std::string getNombre()const override;
        int getDurabilidad()const override;
        float getDano() const override;
        void Usar() override;
        float getAutoDano()const override;

        std::string getTipo() const;
        int getDuracionEfecto()const;


        //destructor
        ~Pocion();
    
};
