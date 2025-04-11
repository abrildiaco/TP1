#pragma once

#include <string>
#include <memory>
#include "../armas/armas.hpp"

class Personaje{
    public:
        virtual void getInfo()const = 0; //me muestre una descripcion e informacion del personaje
        virtual std::string getNombre()const = 0; //me devuelve el nombre del perdonaje
        virtual std::string getTipo()const = 0; //si es personaje mago o guerrero
        virtual float getHp()const = 0;
        virtual Arma& getArma()const = 0; //devuelve el arma que esta usando el personaje
        virtual void Curar() = 0; //los personajes oueden curarse
        virtual void Atacar() = 0; //el personaje ataca

        virtual ~Personaje() = default; 

};

class Mago: public Personaje{
    protected:
        std::string tipo_personaje;//si es mago o guerrero
        std::string nombre;
        float hp; //vida del personaje
        float fuerza; //va de [0, 5]
        
        //arma del personaje
        std::unique_ptr<Arma> arma;

    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Mago(std::string, float, std::unique_ptr<Arma>); //nombre, fuerza, arma

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo()const override;
        virtual float getHp() const override;
        virtual Arma& getArma()const override;
        virtual void getInfo()const = 0; 
        virtual void Curar() = 0;
        virtual void Atacar() = 0;
        
        //destructor
        virtual ~Mago() = default;

};

class Guerrero: public Personaje{
    protected:
        std::string tipo_personaje;//si es mago o guerrero
        std::string nombre;
        float hp; //vida del personaje
        float fuerza; //va de [0, 5]
        bool proteccion; //aleatoriamente se les asignara una proteccion en el caso
        //que usen un arma máguca para evitar el auto_daño
        
        //arma del personaje
        std::unique_ptr<Arma> arma;
    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Guerrero(std::string, float, std::unique_ptr<Arma>); //nombre, fuerza, arma

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo()const override;
        virtual float getHp() const override;
        virtual Arma& getArma()const override;
        virtual void getInfo()const = 0; 
        virtual void Curar() = 0;
        virtual void Atacar() = 0;

        virtual bool getProteccion()const;
        
        //destructor
        virtual ~Guerrero() = default;


};