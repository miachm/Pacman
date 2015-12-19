#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Personaje.hpp"
#include "Callback_rampage.hpp"
#include <SFML/Audio.hpp>

class Pacman : public Personaje,callback_rampage
{
    public:
        Pacman(Tablero &mitablero,const int x,const int y);

        void mover();

        void setRampage() override
        {
            setVelocidad(tiempo_rampage);
        }

        void disableRampage() override
        {
            setVelocidad(tiempo_defecto);
        }

        void warningRampage() override {}

        bool terminado() const {return vivo == false && anim_muerte == 15;}

        void matar()
        {
            vivo = false;
            anim_muerte = 0;
            disableMov();
            tiempo_de_animacion = tiempo_de_animacion_muerte;
            pacman_death.play();
        }

        bool estaVivo() const {return vivo;}

        ~Pacman();
    protected:

        void comer(int x,int y) override;
    private:

        static const int tiempo_defecto = 160;
        static const int tiempo_rampage = 80;

        sf::Texture textura[4][2];
        sf::Texture muerto[11];
        bool vivo = true;

        int anim_muerte;
        int tiempo_de_animacion;
        int tiempo_de_animacion_muerte = 100;

        sf::Clock reloj_animacion;
        sf::Sound pacman_eatfruit;
        sf::Sound pacman_death;

        void animarMuerte();
};

#endif // PACMAN_HPP
