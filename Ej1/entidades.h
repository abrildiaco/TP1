#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "personal.h"
#include "departamento.h"

//CLASE ABSTRACTA
class EntidadOrganizativa{
    protected:
        std::string nombre;
        std::vector<std::shared_ptr<EntidadOrganizativa>> subentidades; //[inf] uso con punteros para evitar instancias de clase
    
    public:
        //condtructor    
        EntidadOrganizativa(std::string);
        
        //metodos virtuales puros
        virtual std::string getNombre() const = 0;
        virtual void agregarSubentidad(std::shared_ptr<EntidadOrganizativa>) = 0;
        virtual int contarSubentidades()const = 0;
        
        //destructor
        virtual ~EntidadOrganizativa() = default;    
};       

//CLASES DERIVADAS

class CentralRegional;

class Empresa: public EntidadOrganizativa{
    private:
        std::vector<Departamento> departamentos; //[1, inf]
    
    public:
        //constructor
        Empresa(std::string, std::string, Departamento);//falta algo

        //métodos a sobreescribir
        std::string getNombre() const override;
        void agregarSubentidad(std::shared_ptr<EntidadOrganizativa>) override;
        int contarSubentidades() const override;

        //métodos/atributos propios
        bool ocupada; //atributo para cumplir con la composicion
        std::string direccion;

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
        //constructor
        CentralRegional(std::string, GerenteAlto&, GerenteMedio&);
        
        //métodos a sobreescribir
        std::string getNombre() const override;
        void agregarSubentidad(std::shared_ptr<EntidadOrganizativa> ) override;
        int contarSubentidades() const override;
        
        //métodos/atributos propios
        std::set<std::string> pais; //unique y ordenado
        
        int getCantEmpleados() const;
        std::vector<std::string> getEmpNames() const; //[1, inf]
        void contratarGerenteAlto(GerenteAlto&);
        void contratarGerenteMedio(GerenteMedio&);
        std::vector<GerenteAlto> getGerenteAlto() const;
        std::vector<GerenteMedio> getGerenteMedio() const;
        
        ~CentralRegional() = default;
};
    
//RELACION DE COMPOSICION ENTRE EMPRESA Y CENTRAL REGIONAL
/*
La central regional puede tener de una a infinitas empresas, pero una empresa
puede estar en una sola entidad regional
*/

    
    