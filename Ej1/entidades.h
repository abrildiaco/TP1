#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "personal.h"
#include "departamento.h"

/*
Voy a trabajar con unique pointers. De esta manera, puedo cumplir con las reglas de composición,
evitar instanciaciones de la clase EntidadOrganizativa y hacer dynamic cast. De otra manera,
no podria cumplir con lo pedido
*/ //PREGUNTAAAAAAAAAR

//CLASE ABSTRACTA
class EntidadOrganizativa{
    protected:
        std::string nombre;
        //cambiar este puntero
        std::vector<EntidadOrganizativa> subentidades; //[inf]
    
    public:
        //condtructor    
        EntidadOrganizativa(std::string);
        
        //metodos virtuales puros
        virtual std::string getNombre() const = 0;
        virtual void agregarSubentidad(EntidadOrganizativa&);
        virtual int contarSubentidades()const;
        
        //destructor
        virtual ~EntidadOrganizativa() = default;    
};       

//CLASES DERIVADAS

class CentralRegional;

class Empresa: public EntidadOrganizativa{
    private:
    //ABGREGAR EL DELETE ACA DEL VECTOR???????????????????????
        std::vector<Departamento> departamentos; //[1, inf]
    
    public:
        //atributos
        bool ocupada; //atributo para cumplir con la composicion
        std::string direccion;
        
        //constructor
        Empresa(std::string, std::string, Departamento);//falta algo

        //métodos a sobreescribir
        std::string getNombre() const override;
        
        //estas dos funciones no se usan
        // void agregarSubentidad(std::shared_ptr<EntidadOrganizativa>)override = delete; 
        // int contarSubentidades() const override = delete;

        //metodos propios
        void cambiarOcupada(bool);
        void agregarDep(Departamento&);
        Departamento getDepByName(std::string) const;
        std::vector<std::string> getDepNames() const;

        //sobrecarga de operador < para poder usar set
        bool operator<(const Empresa&)const;
        
        //destructor
        ~Empresa() = default;
};


class CentralRegional: public EntidadOrganizativa{
    private:
        int cantEmpleados;
        std::vector<GerenteAlto> gerentesAlto; //[1, 5]
        std::vector<GerenteMedio> gerentesMedio; //[1, 20]
        std::set<Empresa> empresas; //unique y ordenado [1, inf]
        
    public:
        //atrubutos
        std::set<std::string> pais; //unique y ordenado
        
        //constructor
        CentralRegional(std::string, GerenteAlto&, GerenteMedio&);
        
        //métodos a sobreescribir
        std::string getNombre() const override;
        void agregarSubentidad(EntidadOrganizativa& ) override; //FIJARME SI ANDA SIN PUNTEROS DESABILITANDO LO OTRO
        int contarSubentidades() const override;
        
        //metodos propios
        void contratarGerenteAlto(GerenteAlto&);
        void contratarGerenteMedio(GerenteMedio&);
        int getCantEmpleados() const;
        std::vector<std::string> getEmpNames() const; //[1, inf]
        std::vector<GerenteAlto> getGerenteAlto() const;
        std::vector<GerenteMedio> getGerenteMedio() const;
        
        ~CentralRegional() = default;
};
    
//RELACION DE COMPOSICION ENTRE EMPRESA Y CENTRAL REGIONAL
/*
La central regional puede tener de una a infinitas empresas, pero una empresa
puede estar en una sola entidad regional
*/

    
    