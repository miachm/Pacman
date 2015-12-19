#include "FantasmaAmarillo.hpp"
#include "Pacman.hpp"

FantasmaAmarillo::FantasmaAmarillo(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y) : Fantasma(mitablero,j,p,x,y,id_fantasma)
{
    //ctor
}

void FantasmaAmarillo::moverNormal()
{
    //

    auto ruta = getRutaMasCorta(getPosition(),jugador.getPosition());

    if (ruta.size() > 20)
    {
        escogerRutaMasCorta(ruta,getPosition(),jugador.getPosition());
    }
    else
    {
        auto posibilidades = contarDireccionesLibres();

        setDireccion(posibilidades[rand()%posibilidades.size()]);
    }

}
