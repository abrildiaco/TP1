#pragma once

#include <string>

//Declaracion de la interfaz Armas

class Armas{
    public:
        virtual void getInfo()const = 0; //me muestre una descripcion e informacion del arma
        virtual std::string getNombre()const = 0; //me devuelve el nombre del arma
        virtual std::string getTipo() = 0; //si el arma es magica ode combate
        virtual int getDurabilidad()const = 0; //me devuelve la vida del arma en golpes
        virtual float getDano() const = 0; //me devuelve cuanto daño hace el arma
        virtual void Usar() = 0;

        virtual ~Armas() = default; 
};

//Declaracion de clases abstractas

class ItemMagico: public Armas{

    protected:
        std::string tipo_arma; //si es item magico o de combate
        std::string nombre;
        int durabilidad;//esta medida en usos
        float daño;
        float auto_daño; //como son mágicas, me hacen daño al usarlas si no soy un personaje magico.    
    
    public:
        bool uso; //determina si mi arma fue usada

        //constructor
        ItemMagico(std::string, int); //nombre, durabilidad
        //el daño y el auto daño pueden depender del tipo. los instancio despues

        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo() override;
        virtual int getDurabilidad()const override;
        virtual float getDano() const override;
        virtual void getInfo()const override = 0; 
        virtual void Usar() override = 0;
        
        virtual float getAutoDano()const = 0; 

        //destructor
        virtual ~ItemMagico() = default;
        
};

class ArmaCombate: public Armas{
    protected:
        std::string tipo_arma; //si es item magico o de combate
        std::string nombre;
        int durabilidad;//esta medida en usos
        float daño;
        float peso; //valor entre [1, 5] 1 es el mas liviano
    
    public:
        bool uso; //determina si mi arma fue usada

        //constructor
        ArmaCombate(std::string, int, float);//nombre, durabilidad, peso
    
        //metodos
        virtual std::string getNombre()const override;
        virtual std::string getTipo() override;
        virtual int getDurabilidad()const override;
        virtual float getDano() const override;
        virtual void getInfo()const override = 0;
        virtual void Usar() override = 0;

        virtual float getPeso()const = 0;

        //destructor
        virtual ~ArmaCombate() = default;

};