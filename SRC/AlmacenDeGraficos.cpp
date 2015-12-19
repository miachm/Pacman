#include "AlmacenDeGraficos.hpp"
#include "Tablero.hpp"

AlmacenDeGraficos::AlmacenDeGraficos()
{
    cargarSpritesPacman();
    cargarSpritesFantasma();
    cargarPuntos();
}

void AlmacenDeGraficos::cargarSpritesPacman()
{
    sf::Image imagen;
    imagen.loadFromFile("./Sprites/pacman.png");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++) //  dos animaciones por fotograma
        {
            jugador[i][j].loadFromImage(imagen,sf::IntRect(j*Tablero::ESCALA+i*Tablero::ESCALA*2,0,Tablero::ESCALA,Tablero::ESCALA));
           // Personaje::textura[i][j] = &textura[i][j];
        }
    }

    for (int i = 0;i<11;i++)
    {
        muerto_jugador[i].loadFromImage(imagen,sf::IntRect(i*Tablero::ESCALA,Tablero::ESCALA,Tablero::ESCALA,Tablero::ESCALA));
    }
}

void AlmacenDeGraficos::cargarSpritesFantasma()
{
    sf::Image imagen;

    imagen.loadFromFile("./Sprites/Fantasma.png");

    for (int i = 0; i < 4; i++) // 4 fantasmas
    {
        for (int j = 0; j < 4; j++) // 4 dirreciones
        {
            for (int k = 0; k < 2; k++) // 2 fotogramas
            {
                fantasma[i][j][k].loadFromImage(imagen,sf::IntRect(j*40+k*Tablero::ESCALA,i*Tablero::ESCALA,Tablero::ESCALA,Tablero::ESCALA));
            }
        }

        muerto_fantasma[i].loadFromImage(imagen,sf::IntRect(80+Tablero::ESCALA*i,80,Tablero::ESCALA,Tablero::ESCALA));
        //Muerto[i].setTexture(Muerto_Texture[i]);

        panico_fantasma[i].loadFromImage(imagen,sf::IntRect(i*Tablero::ESCALA,80,Tablero::ESCALA,Tablero::ESCALA));
        //Panico_Final[i].setTexture(Panico_Texture[i]);
    }
}

void AlmacenDeGraficos::cargarPuntos()
{
    sf::Image imagen;
    imagen.loadFromFile("./Image/Puntuacion.png");

    for (int i = 0;i<4;i++)
    {
        puntos[i].loadFromImage(imagen,sf::IntRect(i*20,0,20,20));
    }
}
