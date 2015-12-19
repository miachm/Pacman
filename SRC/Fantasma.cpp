#include "Fantasma.hpp"
#include "Pacman.hpp"
#include "Puntuacion.hpp"
#include <queue>
#include <iostream>
#include <climits>
#include "AlmacenDeGraficos.hpp"
#include <algorithm>
#include "Estado.hpp"
/*

    Fantasma[0].Position = sf::Vector2f(13*ESCALA,13*ESCALA);
    Fantasma[1].Position = sf::Vector2f(14*ESCALA,13*ESCALA);
    Fantasma[2].Position = sf::Vector2f(13*ESCALA,14*ESCALA);
    Fantasma[3].Position = sf::Vector2f(14*ESCALA,14*ESCALA);
*/

Fantasma::Fantasma(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y,int id) :

    Personaje(mitablero,x,y),
    tablero(mitablero),
    jugador(j),
    puntuacion(p),
    id_fantasma(id),
    inicial(x,y)
{
    for (int j = 0; j < 4; j++) // 4 dirreciones
    {
        for (int k = 0; k < 2; k++) // 2 fotogramas
        {
            textura[(j+2)%4][k] = &(AlmacenDeGraficos::getInstancia().getFantasma(id_fantasma,j,k));
        }
    }


    setArribaDireccion();
    setVelocidad(180);

    direcciones[DERECHA].x = 1;
    direcciones[DERECHA].y = 0;

    direcciones[IZQUIERDA].x = -1;
    direcciones[IZQUIERDA].y = 0;

    direcciones[ABAJO].x = 0;
    direcciones[ABAJO].y = 1;

    direcciones[ARRIBA].x = 0;
    direcciones[ARRIBA].y = -1;

    Estado::getInstancia().anyadirCallback(this);
}

void Fantasma::mover()
{
    if (!jugador.estaVivo()) return;

    if (listoParaNuevoMovimiento()) // SI no estamos en transicion a nuevo movimiento...
    {
        if (!muerto)
        {
            if (!Estado::getInstancia().esRampage())
            {
                moverNormal();
            }
            else moverAsustado();
        }
        else moverMuerto();
    }

    if (!muerto && getPosition() == jugador.getPosition())
    {
        if (!Estado::getInstancia().esRampage())
            jugador.matar();
        else
            this->matar();
    }

    Personaje::mover();
}


void Fantasma::moverAsustado()
{
    sf::Vector2i pos = getPosition();
    sf::Vector2i dest = jugador.getPosition();

    auto posibilidades = contarDireccionesLibres();

    if (posibilidades.size() > 1 || tablero.getColision(pos+getOrientacion()))
    {
        int max = getRutaMasCorta(dest,pos+direcciones[0]).size();
        int index = 0;
        int cnt;

        for (int i = 1; i<4; i++)
        {
            cnt = getRutaMasCorta(dest,pos+direcciones[i]).size();
            if (cnt > max)
            {
                index = i;
                max = cnt;
            }
        }

        setDireccion(index);
    }
    else   setDireccion(posibilidades[0]);
}

std::vector<int> Fantasma::contarDireccionesLibres()
{
    sf::Vector2i pos = getPosition();

    std::vector<int> devolver;

    for (int i = 0; i<4; i++)
    {
        if (direcciones[i] == -getOrientacion()) continue;
        if (!tablero.getColision(pos+direcciones[i]))
        {
            devolver.push_back(i);
        }
    }

    return devolver;
}


std::vector<sf::Vector2i> Fantasma::getRutaMasCorta(sf::Vector2i pos,sf::Vector2i dest)
{
    struct Nodo
    {
        Nodo* padre;

        sf::Vector2i pos;

        Nodo(Nodo* p = nullptr) : padre(p),pos(0,0) {}
    };

    if (pos.x < 0 || pos.x > 27 || dest.x < 0 || dest.x > 27 ||
            tablero.getColision(pos) || tablero.getColision(dest) || pos == dest)
    {
        return std::vector<sf::Vector2i>();

    }

    std::swap(pos,dest);

    Nodo mapa[Tablero::Tamanyo_Mapa_Y][Tablero::Tamanyo_Mapa_X];

    std::queue<Nodo*> cola;
    std::vector<sf::Vector2i> devolver;
    Nodo* actual = &mapa[pos.x][pos.y];
    actual->padre = actual;
    actual->pos = pos;
    cola.push(actual);

    while (!cola.empty())
    {
        actual = cola.front();
        // std::cout<<actual->pos.x<<' '<<actual->pos.y<<std::endl;
        if (actual->pos == dest) break;

        cola.pop();

        for (int i = 0; i<4; i++)
        {
            sf::Vector2i aux = actual->pos+direcciones[i];

            if (aux.x < 0)
            {
                aux.x = 0;
            }
            else if (aux.x>27)
                aux.x = 27;

            Nodo* n = &mapa[aux.x][aux.y];
            if (n->padre == nullptr && !tablero.getColision(aux))
            {
                n->padre = actual;
                n->pos = aux;
                cola.push(n);
            }
        }
    }
    actual = &mapa[dest.x][dest.y];

    while (actual != nullptr && actual->padre != actual)
    {
        devolver.push_back(actual->pos);
        actual = actual->padre;
    };

    return devolver;
}


void Fantasma::moverMuerto()
{
    if (!escogerRutaMasCorta(getPosition(),inicial) && !Estado::getInstancia().esRampage())
    {
        muerto = false;
        disableRampage();
    }
}

void Fantasma::elegirDireccion(sf::Vector2i pos,sf::Vector2i dest)
{
    if (dest.x-pos.x > 0)
    {
        setDerechaDireccion();
    }
    else if (dest.x-pos.x < 0)
    {
        setIzquierdaDireccion();
    }
    else if (dest.y-pos.y > 0)
    {
        setAbajoDireccion();
    }
    else
    {
        setArribaDireccion();
    }
}

void Fantasma::matar()
{
    muerto = true;
    for (int j = 0; j<4; j++)
    {
        for (int k = 0; k<2; k++)
        {
            textura[(j+2)%4][k] = &(AlmacenDeGraficos::getInstancia().getMuertoFantasma(j));
        }
    }

    puntuacion.comerFantasma(getSprite().getPosition());
}

void Fantasma::setRampage()
{
    if (muerto) return;
    for (int j = 0; j<4; j++)
    {
        for (int k = 0; k<2; k++)
        {
            textura[j][k] = &(AlmacenDeGraficos::getInstancia().getPanicoFantasma(j%2));
        }
    }
}

void Fantasma::warningRampage()
{
    if (muerto) return;
    for (int j = 0; j<4; j++)
    {
        for (int k = 0; k<2; k++)
        {
            textura[j][k] = &(AlmacenDeGraficos::getInstancia().getPanicoFantasma(j%2+k*2));
        }
    }
}

void Fantasma::disableRampage()
{
    if (muerto) return;
    //std::cout<<"Rampage desactivado"<<std::endl;
    for (int j = 0; j<4; j++)
    {
        for (int k = 0; k<2; k++)
        {
            textura[(j+2)%4][k] = &(AlmacenDeGraficos::getInstancia().getFantasma(id_fantasma,j,k));
        }
    }
}

bool Fantasma::escogerRutaMasCorta(sf::Vector2i pos,sf::Vector2i dest)
{
    //sf::Vector2i(jugador->getPosition().x/Tablero::ESCALA,jugador->getPosition().y/Tablero::ESCALA);

    std::vector<sf::Vector2i> ruta = getRutaMasCorta(pos,dest);

    return escogerRutaMasCorta(ruta,pos,dest);
}

bool Fantasma::escogerRutaMasCorta(std::vector<sf::Vector2i>& ruta,sf::Vector2i pos,sf::Vector2i dest)
{
    if (ruta.empty()) return false;

    sf::Vector2i destino = ruta.size() > 1? ruta[1] : dest;

    elegirDireccion(pos,destino);

    return true;
}

Fantasma::~Fantasma()
{
    Estado::getInstancia().eliminarCallback(this);
}
