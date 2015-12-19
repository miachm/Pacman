#ifndef ALMACENDEGRAFICOS_H
#define ALMACENDEGRAFICOS_H
#include <SFML/Graphics.hpp>
//sa
class AlmacenDeGraficos
{
    public:

        static const AlmacenDeGraficos& getInstancia()
        {
            static AlmacenDeGraficos instancia;
            return instancia;
        }

        const sf::Texture& getJugador(int i,int j) const {return jugador[i][j];}
        const sf::Texture& getMuertoJugador(int i) const {return muerto_jugador[i];}
        const sf::Texture& getFantasma(int i,int j,int k) const {return fantasma[i][j][k];}
        const sf::Texture& getPanicoFantasma(int i) const {return panico_fantasma[i];}
        const sf::Texture& getMuertoFantasma(int i) const {return muerto_fantasma[i];}
        const sf::Texture& getPuntos(int i) const {return puntos[i];}
    protected:
    private:

        sf::Texture jugador[4][2];
        sf::Texture muerto_jugador[11];
        sf::Texture fantasma[4][4][2];
        sf::Texture panico_fantasma[4];
        sf::Texture muerto_fantasma[4];

        sf::Texture puntos[4];

        AlmacenDeGraficos();

        void cargarSpritesPacman();
        void cargarSpritesFantasma();
        void cargarPuntos();
};

#endif // ALMACENDEGRAFICOS_H
