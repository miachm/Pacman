#ifndef FANTASMAAZUL_H
#define FANTASMAAZUL_H

#include "Fantasma.hpp"


class FantasmaAzul : public Fantasma
{
    public:
        static const int id_fantasma = 2;

        FantasmaAzul(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y);
    protected:
         void moverNormal() override;

         sf::Vector2i puntos_control[4];
         int punto_actual = 0;
};

#endif // FANTASMAAZUL_H
