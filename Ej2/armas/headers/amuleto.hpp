#pragma once

#include <string>
#include "../armas.hpp"

//material
class Amuleto: public ItemMagico{
    private:
        bool suerte; //si te toca con suerte haces mucho daño, sino poco (aleatorio)
    public:
        //constructor
        Amuleto(std::string,  int); //nombre, durabilidad

        //metodos
        void Usar() override;
        void getInfo()const override; 
        float getAutoDano()const override;

        bool hasSuerte()const;

        //destructor
        ~Amuleto();
};