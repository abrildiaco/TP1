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
        virtual std::shared_ptr<Arma> getArma1() = 0; //devuelve el arma que esta usando el personaje
        virtual std::shared_ptr<Arma> getArma2() = 0;
        virtual void Curar() = 0; //los personajes pueden curarse
        virtual float Atacar(std::shared_ptr<Arma>) = 0; //el personaje ataca y devuelve el daño hacho al oponente

        virtual ~Personaje() = default; 

};

class Mago: public Personaje{
    protected:
        std::string tipo_personaje;//si es mago o guerrero
        std::string nombre;
        float hp; //vida del personaje
        float fuerza; //va de [0, 5]
        
        //armas del personaje
        std::shared_ptr<Arma> arma1;
        std::shared_ptr<Arma> arma2;

    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Mago(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, fuerza, arma1, arma2

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo()const override;
        virtual float getHp() const override;
        virtual std::shared_ptr<Arma> getArma1() override;
        virtual std::shared_ptr<Arma> getArma2() override;
        virtual void getInfo()const = 0; 
        virtual void Curar() = 0;
        virtual float Atacar(std::shared_ptr<Arma>) = 0;
        
        virtual bool recibirDano(float); //recibe cuanto daño le hicieron
        
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
        
        //armas del personaje
        std::shared_ptr<Arma> arma1;
        std::shared_ptr<Arma> arma2;

    public:
        bool ataco; //determina si el personaje ataco

        //constructor
        Guerrero(std::string, float, std::shared_ptr<Arma>, std::shared_ptr<Arma>); //nombre, fuerza, arma1, arma2

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo()const override;
        virtual float getHp() const override;
        virtual std::shared_ptr<Arma> getArma1() override;
        virtual std::shared_ptr<Arma> getArma2() override;
        virtual void getInfo()const = 0; 
        virtual void Curar() = 0;
        virtual float Atacar(std::shared_ptr<Arma>) = 0;

        virtual bool recibirDano(float, std::shared_ptr<ItemMagico>); //recibe cuanto daño le hicieron y con que arma
        virtual bool getProteccion()const;
        
        //destructor
        virtual ~Guerrero() = default;


};