#ifndef FANTASMAROJO_H
#define FANTASMAROJO_H
#include "Fantasma.hpp"

class FantasmaRojo : public Fantasma
{
    public:
        static const int id_fantasma = 0;

        FantasmaRojo(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y);
    protected:

         void moverNormal() override;
    private:
        friend class FantasmaRosa;

        sf::Vector2i ultimaPosicion;
};

#endif // FANTASMAROJO_H
