#include <iostream>
#include "armas.h"
#include "libro_hechizos.h"
#include "pocion.h"
#include "baston.h"
#include "amuleto.h"
#include "hacha_simple.h"
using namespace std;


int main(){

    cout<<"inicio prueba de armas"<<endl;

    // cout<<"\n== Pocion prueba =="<<endl;
    // Pocion p("Pocion", 3);
    // p.getInfo();
    // p.Usar();
    
    // p.getInfo();
    // p.Usar();
    
    // p.getInfo();
    // p.Usar();
    
    // p.Usar();

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

    
    // cout<<"\n== Amuleto prueba =="<<endl;
    // Amuleto a("Amuleto", 3);
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.Usar();

    cout<<"\n== Hacha simple prueba =="<<endl;
    HachaSimple a("Hacha Simple", 3, 1);
    a.getInfo();
    a.Usar();
    
    a.getInfo();
    a.Usar();
    
    a.Afilar();
    a.getInfo();
    a.Usar();
    
    a.Usar();


    return 0;
}