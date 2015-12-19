#ifndef ALMACENDESONIDO_H
#define ALMACENDESONIDO_H
#include <SFML/Audio.hpp>

class AlmacenDeSonido
{
    public:
        static const AlmacenDeSonido& getInstancia()
        {
            static AlmacenDeSonido instancia;
            return instancia;
        }

        const sf::SoundBuffer& getPacman_beginning() const {return pacman_beginning;}
        const sf::SoundBuffer& getPacman_death() const {return pacman_death;}
        const sf::SoundBuffer& getPacman_eatfruit() const {return pacman_eatfruit;}
        const sf::SoundBuffer& getPacman_rampage() const {return pacman_rampage;}
    protected:
    private:

        AlmacenDeSonido();

        sf::SoundBuffer pacman_beginning;
        sf::SoundBuffer pacman_death;
        sf::SoundBuffer pacman_eatfruit;
        sf::SoundBuffer pacman_rampage;
};

#endif // ALMACENDESONIDO_H
