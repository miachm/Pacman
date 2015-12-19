#ifndef ALMACENDEFUENTES_H
#define ALMACENDEFUENTES_H
#include <SFML/Graphics.hpp>

class AlmacenDeFuentes
{
    private:
        AlmacenDeFuentes();

        sf::Font arial;
public:

    static const AlmacenDeFuentes& getInstancia()
    {
        static AlmacenDeFuentes instancia;
        return instancia;
    }

    const sf::Font& getArial() const {return arial;}
};

#endif // ALMACENDEFUENTES_H
