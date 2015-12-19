#ifndef ESTADO_H
#define ESTADO_H
#include <SFML/Audio.hpp>
//sas

class callback_rampage;

class Estado
{
    public:
        static const int duracion_rampage = 6;
        static const int warning_rampage = 4;

        static Estado& getInstancia()
        {
            static Estado estado;
            return estado;
        }

        void refresh();
        void activarRampage();
        void desactivarRampage();

        void anyadirCallback(callback_rampage* c);
        void eliminarCallback(callback_rampage* c);

        bool esRampage() const {return rampage;}
    protected:
    private:

        Estado();

        sf::Clock reloj_rampage;
        bool rampage = false;
        bool warning = false;

        sf::Sound pacman_rampage;

        std::vector<callback_rampage*> callbacks;
};

#endif // ESTADO_H
