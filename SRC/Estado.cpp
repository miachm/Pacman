#include "Estado.hpp"
#include "AlmacenDeSonido.hpp"
#include "Callback_rampage.hpp"

Estado::Estado()
{
    pacman_rampage.setBuffer(AlmacenDeSonido::getInstancia().getPacman_rampage());
    pacman_rampage.setLoop(true);
}

void Estado::refresh()
{
    if (rampage)
    {
        if (warning && reloj_rampage.getElapsedTime() >= sf::seconds(warning_rampage))
        {
            warning = false;
            for (unsigned int i = 0;i<callbacks.size();i++)
            {
                callbacks[i]->warningRampage();
            }
        }
        else if (reloj_rampage.getElapsedTime() >= sf::seconds(duracion_rampage))
        {
            desactivarRampage();
        }
    }
}

void Estado::activarRampage()
{
    rampage = true;
    warning = true;

    for (unsigned int i = 0;i<callbacks.size();i++)
    {
        callbacks[i]->setRampage();
    }
    pacman_rampage.play();
    reloj_rampage.restart();
}

void Estado::desactivarRampage()
{
    rampage = false;

    for (unsigned int i = 0;i<callbacks.size();i++)
    {
        callbacks[i]->disableRampage();
    }


    pacman_rampage.stop();
}

void Estado::anyadirCallback(callback_rampage* c)
{
    callbacks.push_back(c);
}

void Estado::eliminarCallback(callback_rampage* c)
{
    auto it = find(callbacks.begin(),callbacks.end(),c);

    if (it != callbacks.end())
        callbacks.erase(it);
}
