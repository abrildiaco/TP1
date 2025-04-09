#pragma once

#include <string>
#include <vector>
#include <memory>
#include "armas.h"

/*
el libro contiene tres hechizos: "congelamiento", "daño por daño", "curacion"
"Congelamiento" : el oponente no puede atacar y ademas sufre daño por el frío
"daño por daño" : el daño que te genera el oponente, se lo genera a el mismo tambien
"Curacion" : no hago daño, y me curo

segun el turno, el hechizo a usar se elige de manera aleatoria
*/

class LibroHechizos: public ItemMagico{
    private:
        std::vector<std::string> hechizos;
        std::string hechizo_actual;
        bool maldito; //si el libro esta maldito, el efecto de los hechizos es menor

    public:
        //constructor
        LibroHechizos(std::string, int); //nombre, durabilidad

        //metodos
        // std::string getNombre()const override;
        // int getDurabilidad()const override;
        // float getDano() const override;
        // virtual std::string getTipo() override;
        void getInfo()const override; 
        void Usar() override;
        float getAutoDano()const override;

        std::vector<std::string> getHechizos()const;
        std::string getHechizoActual()const;
        bool isMaldito();

        //destructor
        ~LibroHechizos();
    
};
