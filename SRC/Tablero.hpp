#ifndef TABLERO_H
#define TABLERO_H
#include <SFML/Graphics.hpp>

class Puntuacion;

class Tablero
{
    public:

        static const int ESCALA = 20;
        static const int Tamanyo_Mapa_X =  29;
        static const int Tamanyo_Mapa_Y =  31;

        Tablero(const int resolucionx,const int resoluciony,Puntuacion& p);

        int comer(sf::Vector2f pos){return comer(pos.x,pos.y);}
        int comer(int x,int y);

        //int getPuntos() const {return puntos;}
        int getComida() const {return comida;}
        bool getColision(sf::Vector2f pos) const{ return getColision(pos.x,pos.y);}
        bool getColision(sf::Vector2i pos) const {return getColision(pos.x,pos.y);}
        bool getColision(int x,int y) const{ return esPared(x,y);}
        const sf::Sprite& getRepresentacion() const {return sprite;;}

        void setColision(sf::Vector2i pos){buffer = mapa[pos.y][pos.x];  mapa[pos.y][pos.x]= 'x';}
        void deleteColision(sf::Vector2i pos){mapa[pos.y][pos.x] = buffer;}
    protected:
    private:
        const sf::Vector2f RESOLUCION;
        int comida;

        bool esPared(int x,int y) const {return mapa[y][x] == 'x';} // Puede desbordar en los bordes, en ese caso adcederá a la fila anterior/posterior, leerá un caracter nulo y por tanto devolverá false
        bool comible(int x,int y) const;
        bool esComida(int x,int y) const;
        bool esPildora(int x,int y) const;
        void borrarComida(int x,int y);
        void generarRepresentacion();

        char buffer;

        sf::Texture campo;
        sf::RenderTexture campo_con_la_comida;
        sf::CircleShape comida_representacion;
        sf::CircleShape pildora_representacion;

        sf::Sprite sprite;

        Puntuacion &puntuacion;

        char mapa[Tamanyo_Mapa_Y][Tamanyo_Mapa_X];
};

#endif // TABLERO_H
