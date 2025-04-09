#pragma once
#include "armas.h"

class HachaSimple: public HachaSimple{
    protected:
        int filo; //inician con filo de 10, en cada golpe baja el filo y daña menos

    public:
        bool uso; //determina si mi arma fue usada

        //constructor
        HachaSimple(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        // virtual std::string getNombre()const override;
        // virtual int getDurabilidad()const override;
        // virtual float getDano() const override;
        //virtual std::string getTipo() override;
        virtual void getInfo()const override; 
        virtual void Usar() override;

        virtual float getPeso()const override;
        virtual void Afilar()override;

        //destructor
        virtual ~HachaSimple() = default;

};