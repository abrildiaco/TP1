#include <iostream>
#include "armas.h"
#include "libro_hechizos.h"
#include "pocion.h"
#include "baston.h"
using namespace std;


int main(){

    cout<<"inicio prueba de armas"<<endl;

    cout<<"\n== Pocion prueba =="<<endl;
    Pocion p("Pocion", 3);
    p.getInfo();
    p.Usar();
    
    p.getInfo();
    p.Usar();
    
    p.getInfo();
    p.Usar();
    
    p.Usar();

    // cout<<"\n== Libro prueba=="<<endl;
    // LibroHechizos l("Libro de Hechizos", 3);

    // l.getInfo();
    // l.Usar();
    
    // l.getInfo();
    // l.Usar();
    
    // l.getInfo();
    // l.Usar();
    
    // l.Usar();

    // cout<<"\n== Baston prueba =="<<endl;

    // Baston b("Baston", 7);

    // b.getInfo();
    // b.Usar();
    
    // b.getInfo();
    // b.Usar();
    
    // b.getInfo();
    // b.Usar();
    
    // b.getInfo();
    // b.Usar();

    // b.getInfo();
    // b.Usar();

    // b.getInfo();
    // b.Usar();

    return 0;
}