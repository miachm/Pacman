#include "Personaje.hpp"
#include "Tablero.hpp"
#include <iostream>

Personaje::Personaje(Tablero &mitablero,const int x,const int y) : tablero(mitablero),velocidad(-1,0),vPulsada(0,0),tPulsada(0),
            orientacion(direccion::IZQUIERDA)
{

    sprite.setPosition(x*Tablero::ESCALA,y*Tablero::ESCALA);
    tiempo_entre_pixeles = 160/Tablero::ESCALA;
    en_movimiento = false;
    anim = 0;
    reloj.restart();
}

void Personaje::mover()
{

    if (reloj_animacion.getElapsedTime() >= sf::milliseconds(tiempo_de_animacion))
    {
        animar();
    }

    if(tPulsada>0)
    {
        auto aux = getPosition()+vPulsada;
        sf::Vector2i pos(aux.x,aux.y);

        if(!tablero.getColision(aux))
        {
            velocidad = sf::Vector2f(vPulsada.x, vPulsada.y);
            tPulsada=0;
            orientacion=oriPulsada;
            sprite.setTexture(*textura[oriPulsada][anim]);
        }
        tPulsada--;
    }

    if (!en_movimiento)
    {

        if (mover_flag)
            iniciarMovimiento();
    }
    else
    {
        transicion_movimiento();
    }
}

void Personaje::animar()
{

    anim = (anim+1)%2;
    sprite.setTexture(*textura[orientacion][anim]);

    reloj_animacion.restart();
}

void Personaje::iniciarMovimiento()
{
    int x = sprite.getPosition().x/Tablero::ESCALA+velocidad.x;
    int y = sprite.getPosition().y/Tablero::ESCALA+velocidad.y;

    if (!tablero.getColision(x,y))//comer(x,y))
    {
        destino = sf::Vector2f(sprite.getPosition())+sf::Vector2f(velocidad.x*Tablero::ESCALA,velocidad.y*Tablero::ESCALA);
        en_movimiento = true;
        acum = Tablero::ESCALA;
        velocidad_aux = velocidad;
    }
    reloj.restart();
}

void Personaje::transicion_movimiento()
{
    int incr = ((reloj.getElapsedTime().asMilliseconds())/tiempo_entre_pixeles);

    if (incr >= acum)
    {
        incr = acum;
        en_movimiento = false;

        if (tratar_bordes()) return;
    }

    acum -= incr;
    sprite.move(velocidad_aux.x*incr,velocidad_aux.y*incr);

    if (acum <= Tablero::ESCALA/2)
    {
        comer(destino.x/Tablero::ESCALA,destino.y/Tablero::ESCALA);
    }
    reloj.restart();
}

bool Personaje::tratar_bordes()
{
    if (destino == sf::Vector2f(-Tablero::ESCALA,sprite.getPosition().y))
    {
        sprite.setPosition(28*Tablero::ESCALA,sprite.getPosition().y);
        return true;
    }
    else if (destino == sf::Vector2f(28*Tablero::ESCALA,sprite.getPosition().y))
    {
        sprite.setPosition(-Tablero::ESCALA,sprite.getPosition().y);
        return true;
    }
    return false;
}

void Personaje::setArribaDireccion()
{
    if (!mover_flag) return;

    vPulsada.x = 0;
    vPulsada.y = -1;
    tPulsada=tEspPulsada;
    oriPulsada = direccion::ARRIBA;
}


void Personaje::setAbajoDireccion()
{
    if (!mover_flag) return;
    vPulsada.x = 0;
    vPulsada.y = 1;
    tPulsada=tEspPulsada;
    oriPulsada = direccion::ABAJO;

}

void Personaje::setIzquierdaDireccion()
{
    if (!mover_flag) return;
    vPulsada.x = -1;
    vPulsada.y = 0;
    tPulsada=tEspPulsada;
    oriPulsada = direccion::IZQUIERDA;
}

void Personaje::setDerechaDireccion()
{
    if (!mover_flag) return;
    vPulsada.x = 1;
    vPulsada.y = 0;
    tPulsada=tEspPulsada;
    oriPulsada = direccion::DERECHA;
}

void Personaje::setDireccion(int index)
{
    switch (index)
    {
    case DERECHA:
        setDerechaDireccion();
        break;
    case IZQUIERDA:
        setIzquierdaDireccion();
        break;
    case ABAJO:
        setAbajoDireccion();
        break;
    case ARRIBA:
        setArribaDireccion();
    }
}
