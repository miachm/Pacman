#ifndef FANTASMAAMARILLO_HPP
#define FANTASMAAMARILLO_HPP

#include "Fantasma.hpp"


class FantasmaAmarillo : public Fantasma
{
    public:
        static const int id_fantasma = 3;

        FantasmaAmarillo(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y);
    protected:

         void moverNormal() override;
    private:
};

#endif // FANTASMAAMARILLO_HPP
