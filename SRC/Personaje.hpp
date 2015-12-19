#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include <SFML/Graphics.hpp>
#include "Tablero.hpp"

/** Idea para pacman:
*
*   Crear una estructura personaje, que simbolize a alguien que se mueve. Pacman hereda de esa estructura y añade los métodos (enableRampage() y disableRampage()).
*
*   Problemas:
*
*   - La forma de cargar las texturas, en el caso de Pacman se podría sobreescribir el constructor. Si pacman
*/

class Personaje
{
    public:
        enum direccion
        {
            IZQUIERDA,
            DERECHA,
            ARRIBA,
            ABAJO
        };

        Personaje(Tablero &mitablero,const int x,const int y);

        sf::Vector2i getPosition() const {return sf::Vector2i(sprite.getPosition().x/Tablero::ESCALA,sprite.getPosition().y/Tablero::ESCALA);}
        void mover();
        bool listoParaNuevoMovimiento() const {return !en_movimiento;}

        void setArribaDireccion();
        void setAbajoDireccion();
        void setIzquierdaDireccion();
        void setDerechaDireccion();

        void disableMov(){mover_flag= false;}
        void enableMov(){mover_flag =true;}

        void setDireccion(int index);

        int getDireccion() const {return orientacion;}
        sf::Vector2i getOrientacion() const {return sf::Vector2i(velocidad.x,velocidad.y);}

        const sf::Sprite& getSprite() const {return sprite;}


    protected:
        Tablero &tablero;
        sf::Texture const*  textura[4][2];

        void setVelocidad(int tiempo_fotograma)
        {
            tiempo_entre_pixeles = tiempo_fotograma/Tablero::ESCALA;
        }

        void setTexture(sf::Texture const* textura)
        {
            sprite.setTexture(*textura);
        }

        virtual void comer(int x,int y){}
    private:


        sf::Sprite sprite;

        sf::Vector2f velocidad;
        sf::Vector2f velocidad_aux;

        sf::Vector2i vPulsada;
        int tPulsada;
        int oriPulsada;

        static const int tEspPulsada =3;


        int orientacion; // Hacia donde mira el personaje
        int anim = 0;   // Que fotograma de la animación lleva actualmente
        bool en_movimiento;
        int tiempo_de_animacion = 300;
        sf::Vector2f destino;
        int acum;

        bool mover_flag =true;

        //sf::Time tiempo_entre_mov;
        sf::Clock reloj;
        sf::Clock reloj_animacion;

        int tiempo_entre_pixeles;

        void animar();
        void iniciarMovimiento();
        void transicion_movimiento();
        bool tratar_bordes();
};

#endif // PERSONAJE_HPP
