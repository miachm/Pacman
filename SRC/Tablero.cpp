#include "Tablero.hpp"
#include "Puntuacion.hpp"

const char mapa_orig[Tablero::Tamanyo_Mapa_Y][Tablero::Tamanyo_Mapa_X]={
                 {"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"},
                 {"xccccccccccccxxccccccccccccx"},
                 {"xcxxxxcxxxxxcxxcxxxxxcxxxxcx"},
                 {"xCx  xcx   xcxxcx   xcx  xCx"},
/* Fxla 5 */     {"xcxxxxcxxxxxcxxcxxxxxcxxxxcx"},
                 {"xccccccccccccccccccccccccccx"},
                 {"xcxxxxcxxcxxxxxxxxcxxcxxxxcx"},
                 {"xcxxxxcxxcxxxxxxxxcxxcxxxxcx"},
                 {"xccccccxxccccxxccccxxccccccx"},
/* Fxla 10 */    {"xxxxxxcxxxxxcxxcxxxxxcxxxxxx"},
                 {"     xcxxxxxcxxcxxxxxcx     "},
                 {"     xcxx          xxcx     "},
                 {"     xcxx xxx  xxx xxcx     "},
                 {"xxxxxxcxx x      x xxcxxxxxx"},
/* Fxla 15 */    {"      c   x      x   c      "},
                 {"xxxxxxcxx x      x xxcxxxxxx"},
                 {"     xcxx xxxxxxxx xxcx     "},
                 {"     xcxx          xxcx     "},
                 {"     xcxx xxxxxxxx xxcx     "},
/* Fxla 20 */    {"xxxxxxcxx xxxxxxxx xxcxxxxxx"},
                 {"xccccccccccccxxccccccccccccx"},
                 {"xcxxxxcxxxxxcxxcxxxxxcxxxxcx"},
                 {"xcxxxxcxxxxxcxxcxxxxxcxxxxcx"},
                 {"xCccxxccccccc ccccccccxxccCx"},
/* Fxla 25 */    {"xxxcxxcxxcxxxxxxxxcxxcxxcxxx"},
                 {"xxxcxxcxxcxxxxxxxxcxxcxxcxxx"},
                 {"xccccccxxccccxxccccxxccccccx"},
                 {"xcxxxxxxxxxxcxxcxxxxxxxxxxcx"},
                 {"xcxxxxxxxxxxcxxcxxxxxxxxxxcx"},
/* Fxla 30 */    {"xccccccccccccccccccccccccccx"},
                 {"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"}
                };


Tablero::Tablero(const int resolucionx,const int resoluciony,Puntuacion& p)
: RESOLUCION(resolucionx,resoluciony),puntuacion(p)
{
    //ctor
    for (int i = 0;i<Tamanyo_Mapa_Y;i++)
    {
        for (int j = 0;j<Tamanyo_Mapa_X;j++)
        {
            mapa[i][j] = mapa_orig[i][j];
        }
    }

    campo.loadFromFile("./Image/Nivel.png");
    campo_con_la_comida.create(resolucionx,resoluciony);

    comida_representacion.setRadius(ESCALA/4);
    comida_representacion.setFillColor(sf::Color::Yellow);

    pildora_representacion.setRadius(ESCALA/4+2);
    pildora_representacion.setFillColor(sf::Color::Red);

    generarRepresentacion();
}

void Tablero::generarRepresentacion()
{
    campo_con_la_comida.clear();
    campo_con_la_comida.draw(sf::Sprite(campo));
    comida = 0;

    for (int i = 0;i<Tamanyo_Mapa_X;i++)
    {
        for (int j = 0;j<Tamanyo_Mapa_Y;j++)
        {
            if (esComida(i,j))
            {
                comida++;
                comida_representacion.setPosition(i*ESCALA+ESCALA/4,j*ESCALA+ESCALA/4);
                campo_con_la_comida.draw(comida_representacion);
            }
            else if (esPildora(i,j))
            {
                comida++;
                pildora_representacion.setPosition(i*ESCALA+ESCALA/4-2,j*ESCALA+ESCALA/4-2);
                campo_con_la_comida.draw(pildora_representacion);
            }
        }
    }

    campo_con_la_comida.display();
    sprite.setTexture(campo_con_la_comida.getTexture());
}

bool Tablero::esComida(int x,int y) const
{
    return mapa[y][x] == 'c';
}

bool Tablero::esPildora(int x,int y) const
{
    return mapa[y][x] == 'C';
}

bool Tablero::comible(int x,int y) const
{
    return esComida(x,y) || esPildora(x,y);
}

int Tablero::comer(int x,int y)
{
    if (esPared(x,y)) return 0;
    else
    {
        if (comible(x,y))
        {
            //puntos++;
            comida--;

            if (esPildora(x,y))
            {
                puntuacion.comerPildora();
                borrarComida(x,y);
                return -1;
            }
            else
            {
                puntuacion.comerComida();
                borrarComida(x,y);
            }
            return 1;

        }
        return 0;
    }
}

void Tablero::borrarComida(int x,int y)
{
    mapa[y][x] = ' ';
    generarRepresentacion();
}
