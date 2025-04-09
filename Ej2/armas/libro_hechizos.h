#pragma once

#include <string>
#include <memory>
#include "armas.h"

class LibroHechizos: public ItemMagico{
    private:
    public:
        //constructor
        LibroHechizos(std::string, int); //nombre,durabilidad

        //metodos
        void getInfo()const override; 
        std::string getNombre()const override;
        int getDurabilidad()const override;
        float getDano() const override;
        void Usar() override;
        float getAutoDano()const override;

        //destructor
        ~LibroHechizos();
    
};
