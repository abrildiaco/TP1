#include <iostream>
#include "armas.h"
#include "libro_hechizos.h"
#include "pocion.h"
using namespace std;


int main(){

    cout<<"inicio prueba de armas"<<endl;

    cout<<"\n== Pocion prueba =="<<endl;
    Pocion p("Pocion", 3, "veneno");
    p.getInfo();
    p.Usar();
    p.getInfo();
    p.Usar();
    p.getInfo();
    p.Usar();

    return 0;
}