#pragma once

#include <string>
#include <memory>
#include "armas.h"

/*
dos tipos de pociones: veneno, inmunidad
si es de inmunidad y la uso, no puedo recibir daño (ni me hago auto daño)
todas las pociones le hacen daño al oponente, tanto las de veneno como las de inmunidad.
*/

class Pocion: public ItemMagico{
    private:
        std::string tipo; //veneno, inmunidad
        int duracion_efecto; //cuanto dura su efecto en turnos

    public:
        //constructor
        Pocion(std::string, int, std::string); //nombre,durabilidad, tipo

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
