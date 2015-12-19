#include "AlmacenDeSonido.hpp"

AlmacenDeSonido::AlmacenDeSonido()
{
    //ctor

    pacman_beginning.loadFromFile("./Sound/pacman_beginning.wav");
    pacman_death.loadFromFile("./Sound/pacman_death.wav");
    pacman_eatfruit.loadFromFile("./Sound/pacman_eatfruit.wav");
    pacman_rampage.loadFromFile("./Sound/pacman_rampage.wav");
}
