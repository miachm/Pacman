#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.hpp"
#include "Pacman.hpp"
#include "FantasmaRojo.hpp"
#include "FantasmaRosa.hpp"
#include "FantasmaAmarillo.hpp"
#include "FantasmaAzul.hpp"
#include "Estado.hpp"
#include "AlmacenDeSonido.hpp"
#include "AlmacenDeFuentes.hpp"
#include "Puntuacion.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

const int RESOLUCIONX = 560;
const int RESOLUCIONY = 680;
const int POS_INICIAL_PACMANX = 13;
const int POS_INICIAL_PACMANY = 23;

int main()
{
    std::srand(std::time(0));
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(560, 680), "Comecocos");
    app.setFramerateLimit(60);

    /**
    *   Bucle principal del juego:
    *
    *   - Eventos, llamadas a las set Dirrecion
    *   - moverPersonaje()
    *   - moverFantasmas()
    *   - Dibujado
    */

    int vidas = 3;
    int nivel = 1;

    sf::Text vidas_y_nivel;
    vidas_y_nivel.setFont(AlmacenDeFuentes::getInstancia().getArial());
    vidas_y_nivel.setCharacterSize(24);
    vidas_y_nivel.setPosition(50,RESOLUCIONY-40);

    sf::Sound introduccion;
    introduccion.setBuffer(AlmacenDeSonido::getInstancia().getPacman_beginning());

    Puntuacion puntuacion;

    std::unique_ptr<Tablero> tablero(new Tablero(RESOLUCIONX,RESOLUCIONY,puntuacion));

    while (vidas && app.isOpen())
    {
        std::cout<<"Vidas: "<<vidas<<std::endl<<"Nivel: "<<nivel<<std::endl<<std::endl;

        vidas_y_nivel.setString("Vidas: "+std::to_string(vidas) + "       Nivel: " + std::to_string(nivel));

        //Tablero tablero(RESOLUCIONX,RESOLUCIONY);
        Pacman pacman(*tablero,POS_INICIAL_PACMANX,POS_INICIAL_PACMANY);
        FantasmaRojo fantasma_rojo(*tablero,pacman,puntuacion,13,13);
        FantasmaRosa fantasma_rosa(*tablero,pacman,puntuacion,13,14,fantasma_rojo);
        FantasmaAmarillo fantasma_amarillo(*tablero,pacman,puntuacion,14,13);
        FantasmaAzul fantasma_azul(*tablero,pacman,puntuacion,14,14);

        pacman.disableMov();
        fantasma_rojo.disableMov();
        fantasma_rosa.disableMov();
        fantasma_amarillo.disableMov();
        fantasma_azul.disableMov();


         //   sf::Event event;
        sf::Clock reloj;
        reloj.restart();

        introduccion.play();

        //Fantasmas fantasmas;

        // Start the game loop
        while (app.isOpen() && tablero->getComida() > 0 && !pacman.terminado())
        {
            // Process events
            sf::Event event;
            while (app.pollEvent(event))
            {
                // Close window : exit
                if (event.type == sf::Event::Closed)
                    app.close();
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
                    {
                        pacman.setIzquierdaDireccion();
                    }
                    else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
                    {
                        pacman.setDerechaDireccion();
                    }
                    else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
                    {
                        pacman.setArribaDireccion();
                    }
                    else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
                    {
                        pacman.setAbajoDireccion();
                    }
                    else if (event.key.code == sf::Keyboard::K)
                    {
                        pacman.matar();
                    }
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        app.close();
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                pacman.setIzquierdaDireccion();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                pacman.setDerechaDireccion();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                pacman.setAbajoDireccion();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                pacman.setArribaDireccion();
            }

            if (reloj.getElapsedTime() >= sf::seconds(4))
            {
                // Ya ha terminado la animación. Ya se puede correr

                pacman.enableMov();
                fantasma_rojo.enableMov();
                fantasma_rosa.enableMov();
                fantasma_amarillo.enableMov();
                fantasma_azul.enableMov();
            }

            Estado::getInstancia().refresh();

            pacman.mover();

            fantasma_rojo.mover();
            fantasma_rosa.mover();
            fantasma_amarillo.mover();
            fantasma_azul.mover();
            /*if (fantasmas.mover())
            {
                app.close();
            }*/

            app.clear();
            app.draw(tablero->getRepresentacion());
            app.draw(fantasma_rojo.getSprite());
            app.draw(fantasma_rosa.getSprite());
            app.draw(fantasma_amarillo.getSprite());
            app.draw(fantasma_azul.getSprite());
            app.draw(pacman.getSprite());
            app.draw(puntuacion.getText());
            app.draw(puntuacion.getPuntuacionEmergente());
            app.draw(vidas_y_nivel);

            //app.draw(sf::Sprite(AlmacenDeGraficos::getInstancia().getFantasma(0,0,1)));
            app.display();
        }

        vidas -= pacman.terminado();

        if (tablero->getComida() == 0)
        {
            tablero.reset(new Tablero(RESOLUCIONX,RESOLUCIONY,puntuacion));
            nivel++;
        }

        Estado::getInstancia().desactivarRampage();

    }

    return EXIT_SUCCESS;
}
