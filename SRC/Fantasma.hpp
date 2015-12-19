#ifndef FANTASMAS_H
#define FANTASMAS_H
#include <vector>
#include "Callback_rampage.hpp"
#include "Personaje.hpp"

class Pacman;

class Fantasma : public callback_rampage , protected Personaje
{
    public:
        Fantasma(Tablero &mitablero,Pacman& j,Puntuacion& p,int x,int y,int id);

        void mover();
        const sf::Sprite& getSprite(){return Personaje::getSprite();}

        void setRampage() override;
        void warningRampage() override;
        void disableRampage() override;

        void disableMov(){Personaje::disableMov();}
        void enableMov(){Personaje::enableMov();}

        ~Fantasma();
    protected:
        Tablero &tablero;
        Pacman& jugador;

        void elegirDireccion(sf::Vector2i pos,sf::Vector2i dest);

         virtual void moverNormal() = 0;

        std::vector<sf::Vector2i> getRutaMasCorta(sf::Vector2i pos,sf::Vector2i dest); // Obtiene la ruta más corta de A hacia B.
        bool escogerRutaMasCorta(sf::Vector2i pos,sf::Vector2i dest); // Selecciona ruta mas corta de A hacia B, False si no hay ruta (posiblemente porque pos == dest)
        bool escogerRutaMasCorta(std::vector<sf::Vector2i>&,sf::Vector2i,sf::Vector2i);

        std::vector<int> contarDireccionesLibres();
    private:
        Puntuacion& puntuacion;
        int id_fantasma;


        void moverAsustado();
        void moverMuerto();
        void matar();

        bool muerto = false;

        sf::Vector2i inicial;
        sf::Vector2i direcciones[4];

};
#endif // FANTASMAS_H
