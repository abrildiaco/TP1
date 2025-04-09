#pragma once

#include <string>

//Declaracion de la interfaz Armas

class Armas{
    public:
        virtual void getInfo()const = 0; //me muestre una descripcion e informacion del arma
        virtual std::string getNombre()const = 0; //me devuelve el nombre del arma
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
        virtual void getInfo()const override; 
        virtual std::string getNombre()const override;
        virtual int getDurabilidad()const override;
        virtual float getDano() const override;
        virtual void Usar() override;
        
        virtual float getAutoDano()const = 0; 

        //destructor
        virtual ~ItemMagico() = default;
};

class ArmaCombate: public Armas{
    protected:
        std::string tipo_arma; //si es item magico o de combate
        std::string nombre;
        std::string material; //diamante, hierro, acero....
        int durabilidad;//esta medida en usos
        float peso; //si el arma es muy pesada, la controlo peor
        float daño;
    
    public:
        bool uso; //determina si mi arma fue usada

        //constructor
        ArmaCombate(std::string, std::string, int, float, float);//nombre, material, durabilidad, peso, daño
    
        //metodos
        virtual void getInfo()const override; 
        virtual std::string getNombre()const override;
        virtual int getDurabilidad()const override;
        virtual float getDano() const override;
        virtual void Usar() override;

        virtual std::string getMaterial()const = 0;
        virtual float getPeso()const = 0;
        virtual void Reparar() = 0; //la puedo reparar si no esta muy dañada

        //destructor
        ~ArmaCombate() = default;

};