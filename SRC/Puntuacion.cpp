#include "Puntuacion.hpp"
#include "AlmacenDeFuentes.hpp"
#include "AlmacenDeGraficos.hpp"
#include "Puntuacion.hpp"
#include <sstream>
#include "Estado.hpp"

Puntuacion::Puntuacion()
{
    //ctor
    marcador.setFont(AlmacenDeFuentes::getInstancia().getArial());
    marcador.setPosition(300,640);
    marcador.setCharacterSize(24);
    marcador.setColor(sf::Color::White);
    actualizarMarcador();

    Estado::getInstancia().anyadirCallback(this);
}

void Puntuacion::comerComida()
{
    puntos += 20;
    actualizarMarcador();
}

void Puntuacion::comerPildora()
{
    puntos += 30;
    actualizarMarcador();
}

void Puntuacion::comerFantasma(sf::Vector2f pos)
{
    puntos += 200*incr;
    incr *= 2;

    sprite.setPosition(pos);
    sprite.setTexture(AlmacenDeGraficos::getInstancia().getPuntos(consecutivos));

    consecutivos++;
    actualizarMarcador();
}

void Puntuacion::actualizarMarcador()
{
    std::stringstream stream;
    stream<<"Puntos: "<<puntos;
    marcador.setString(stream.str());
}

void Puntuacion::disableRampage()
{
    consecutivos = 0;
    incr = 1;
    sprite.setPosition(-20,-20);
}

Puntuacion::~Puntuacion()
{
    Estado::getInstancia().eliminarCallback(this);
}
