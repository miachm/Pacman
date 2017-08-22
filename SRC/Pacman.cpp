#include "Pacman.hpp"
#include "Estado.hpp"
#include "AlmacenDeGraficos.hpp"
#include "AlmacenDeSonido.hpp"

Pacman::Pacman(Tablero &mitablero,const int x,const int y) : Personaje(mitablero,x,y)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++) //  dos animaciones por fotograma
        {
            Personaje::textura[i][j] = & (AlmacenDeGraficos::getInstancia().getJugador(i,j));
        }
    }

    setIzquierdaDireccion();//sprite.setTexture(textura[direccion::IZQUIERDA][0]);

    pacman_eatfruit.setBuffer(AlmacenDeSonido::getInstancia().getPacman_eatfruit());
    pacman_death.setBuffer(AlmacenDeSonido::getInstancia().getPacman_death());
    Estado::getInstancia().anyadirCallback(this);
}

void Pacman::mover()
{
    if (!vivo)
    {
        if (reloj_animacion.getElapsedTime() >= sf::milliseconds(tiempo_de_animacion_muerte))
        {
            animarMuerte();
        }
    }
    else
    {
        Personaje::mover();
    }
}


void Pacman::animarMuerte()
{
    anim_muerte = (anim_muerte+1);
    if (anim_muerte >= 11)
        setTexture(&AlmacenDeGraficos::getInstancia().getMuertoJugador(10));
    else
    setTexture(&AlmacenDeGraficos::getInstancia().getMuertoJugador(anim_muerte));

    reloj_animacion.restart();
}

void Pacman::comer(int x,int y)
{
    int comida = tablero.comer(x,y);

    if (comida != 0)
    {
        if (pacman_eatfruit.getStatus() != sf::Sound::Playing && !Estado::getInstancia().esRampage())
            pacman_eatfruit.play();
    }
    if (comida < 0)
    {
        Estado::getInstancia().activarRampage();
    }
}

Pacman::~Pacman()
{
    Estado::getInstancia().eliminarCallback(this);
}
