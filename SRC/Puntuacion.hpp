#ifndef PUNTUACION_H
#define PUNTUACION_H
#include <SFML/Graphics.hpp>
#include "Callback_rampage.hpp"

class Puntuacion : public callback_rampage
{
    public:
        Puntuacion();

        void comerComida();
        void comerPildora();
        void comerFantasma(sf::Vector2f pos);

        int getPuntos() const {return puntos;};

        const sf::Text& getText() const {return marcador;}
        const sf::Sprite getPuntuacionEmergente() const {return sprite;}

        void setRampage() override{};
        void warningRampage() override {}
        void disableRampage() override;

        ~Puntuacion();
    protected:
    private:

        void actualizarMarcador();

        sf::Text marcador;
        sf::Sprite sprite;
        int puntos = 0;

        int consecutivos = 0;
        int incr = 1;
};

#endif // PUNTUACION_H
