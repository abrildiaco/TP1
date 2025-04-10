#pragma once
#include <string>

class Personaje{
    public:
        virtual void getInfo()const = 0; //me muestre una descripcion e informacion del personaje
        virtual std::string getNombre()const = 0; //me devuelve el nombre del perdonaje
        virtual std::string getTipo()const = 0; //si es personaje mago o guerrero
        virtual float getFuerza()const = 0; //me devuelve la fuerza del personaje
        virtual float getDano() const = 0; //me devuelve cuanto daño hace el personaje con su propia fuerza/poderes
        virtual void Atacar() = 0;

        virtual ~Personaje() = default; 

};

class Mago: public Personaje{
    protected:
        std::string tipo_personaje;//si es mago o guerrero
        std::string nombre;
        std::string poder; //que tipo de poder tiene
        float fuerza; //va de [0, 5]
        float daño;
    
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Mago(std::string, std::string, float, float); //nombre, poder, fuerza, daño

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo()const override
        virtual float getFuerza()const override;
        virtual float getDano() const override;
        virtual void getInfo()const = 0; 
        virtual void Atacar() = 0;

        virtual std::string getPoder()const = 0;

};