#pragma once

#include <string>
#include <memory>
#include "armas.h"

//material
class Baston: public ItemMagico{
    private:
        std::string nivel; //alto, mediano, bajo
        bool tiene_gema; //la gema le otorga mas poder al baston
};