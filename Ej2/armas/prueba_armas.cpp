#include <iostream>
#include "armas.hpp"
#include "libro_hechizos.hpp"
#include "pocion.hpp"
#include "baston.hpp"
#include "amuleto.hpp"
#include "hacha_simple.hpp"
#include "hacha_doble.hpp"
#include "espada.hpp"
#include "lanza.hpp"
#include "garrote.hpp"

using namespace std;


int main(){

    cout<<"inicio prueba de armas"<<endl;

    srand(time(0)); // Inicializa la semilla


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

    // cout<<"\n== Hacha simple prueba =="<<endl;
    // HachaSimple a("Hacha Simple", 3, 1);
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.Afilar();
    // a.getInfo();
    // a.Usar();
    
    // a.Usar();

    // cout<<"\n== Hacha doble prueba =="<<endl;
    // HachaDoble a("Hacha Doble", 3, 5);
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.Afilar();
    // a.getInfo();
    // a.Usar();
    
    // a.Usar();

    // cout<<"\n== espada prueba =="<<endl;
    // Espada a("Espada", 3, 2);
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.Afilar();
    // a.getInfo();
    // a.Usar();
    
    // a.Usar();

    // return 0;

    // cout<<"\n== lanza prueba =="<<endl;
    // Lanza a("Lanza", 3, 2);
    // a.getInfo();
    // a.Usar();
    
    // a.getInfo();
    // a.Usar();
    
    // a.Afilar();
    // a.getInfo();
    // a.Usar();

    // a.getInfo();
    // a.Usar();

    // return 0;
    
    
    cout<<"\n== garrote prueba =="<<endl;
    Garrote a("Garrote", 3, 5);
    a.getInfo();
    a.Usar();
    
    a.getInfo();
    a.Usar();
    
    a.getInfo();
    a.Usar();

    a.getInfo();
    a.Usar();

    return 0;
    
}