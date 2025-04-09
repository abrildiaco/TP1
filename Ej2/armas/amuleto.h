#pragma once

#include <string>
#include "armas.h"

//material
class Amuleto: public ItemMagico{
    private:
        bool suerte; //si te toca con suerte haces mucho daño, sino poco
    public:
        //constructor
        Amuleto(std::string,  int, bool); //nombre, durabilidad, suerte

        //metodos
        // std::string getNombre()const override;
        // int getDurabilidad()const override;
        // float getDano() const override;
        // virtual std::string getTipo() override;
        void Usar() override;
        void getInfo()const override; 
        float getAutoDano()const override;

        bool hasSuerte()const;

        //destructor
        ~Amuleto();
};