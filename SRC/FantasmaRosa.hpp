#ifndef FANTASMAROSA_HPP
#define FANTASMAROSA_HPP

#include "Fantasma.hpp"

class FantasmaRojo;

class FantasmaRosa : public Fantasma
{
    public:
        static const int id_fantasma = 1;

        FantasmaRosa(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y,FantasmaRojo &compa);
    protected:


         void moverNormal() override;
    private:

        FantasmaRojo& companyero;
};

#endif // FANTASMAROSA_HPP
