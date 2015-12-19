#include "FantasmaAzul.hpp"
#include "Pacman.hpp"

FantasmaAzul::FantasmaAzul(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y) : Fantasma(mitablero,j,p,x,y,id_fantasma)
{
    //ctor

    puntos_control[0] = sf::Vector2i(21,26);
    puntos_control[1] = sf::Vector2i(21,4);
    puntos_control[2] = sf::Vector2i(6,4);
    puntos_control[3] = sf::Vector2i(6,26);

}

void FantasmaAzul::moverNormal()
{
    auto ruta = getRutaMasCorta(getPosition(),jugador.getPosition());

    if (ruta.size() < 9)
    {
        escogerRutaMasCorta(ruta,getPosition(),jugador.getPosition());
    }
    else
    {
        if (getPosition() == puntos_control[punto_actual])
        {
            punto_actual = (punto_actual+1) % 4;
        }
        escogerRutaMasCorta(getPosition(),puntos_control[punto_actual]);
    }
}
