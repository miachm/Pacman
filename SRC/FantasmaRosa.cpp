#include "FantasmaRosa.hpp"
#include "Pacman.hpp"
#include <iostream>
#include "FantasmaRojo.hpp"

FantasmaRosa::FantasmaRosa(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y,FantasmaRojo &compa) :
Fantasma(mitablero,j,p,x,y,id_fantasma),companyero(compa)
{
    //ctor
}

void FantasmaRosa::moverNormal()
{

    //if (rand()%2 == 0)
    tablero.setColision(companyero.ultimaPosicion);

    auto ruta = getRutaMasCorta(getPosition(),jugador.getPosition());

    if (ruta.empty())
    {
        tablero.deleteColision(companyero.ultimaPosicion);

        escogerRutaMasCorta(getPosition(),jugador.getPosition());
    }
    else
    {

        escogerRutaMasCorta(ruta,getPosition(),jugador.getPosition());
        tablero.deleteColision(companyero.ultimaPosicion);

    }
   // else setDireccion(rand()%4);
}
