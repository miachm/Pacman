#include "FantasmaRojo.hpp"
#include "Pacman.hpp"

FantasmaRojo::FantasmaRojo(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y) : Fantasma(mitablero,j,p,x,y,id_fantasma)
{
    //ctor
}


void FantasmaRojo::moverNormal()
{
    auto ruta = getRutaMasCorta(getPosition(),jugador.getPosition());
	if (ruta.size() >= 1) {
		ultimaPosicion = ruta[ruta.size() - 1];
		escogerRutaMasCorta(ruta, getPosition(), jugador.getPosition());
	}
}
