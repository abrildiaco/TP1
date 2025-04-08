#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <string>
#include "personal.h"
#include "entidades.h"
#include "departamento.h"

using namespace std;

//contador de empleados de todos dept
int Departamento::cantEmpleadosDepts = 0;

int main(){
    cout<<"=== Generando empleados ==="<<endl;

    //empleados
    Empleado e1("pablo", "administrador", 3, 125);
    Empleado e2("carlos ", "consultor", 5, 200);
    Empleado e3("abril", "marketing", 1, 100);

    //managers
    Manager m1("camila", "psicologa", 5, 300, 200);
    Manager m2("fernando", "ingeniero", 8, 500, 300);

    //gerentes alto
    GerenteAlto ga1("octavio", "ingenierp", 6, 500, 400);
    GerenteAlto ga2("maria", "abogada", 3, 450, 300);

    //gerentes medio
    GerenteMedio gm1("mateo", "ingenierp", 6, 500, 400);
    GerenteMedio gm2("agus", "ingenierp", 6, 500, 400);

    //gerente bajo y lider
    GerenteBajo gb1("nico", "ingenierp", 6, 500, 400);
    LiderEquipo le1("mili", "ingenierp", 6, 500, 400);

    Departamento dep1("dep de tecnologia", "san andres");
    Departamento dep2("dep de nutricion", "san andres");

    bool a = dep1.contratarEmpleado(m1);
    bool b = dep1.contratarEmpleado(gb1);
    bool c = dep1.contratarEmpleado(le1);
    bool d = dep1.despedirEmpleado(gb1);

    bool e = dep2.contratarEmpleado(m1);

    return 0;
}