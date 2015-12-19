#include "AlmacenDeFuentes.hpp"
#include <iostream>

AlmacenDeFuentes::AlmacenDeFuentes()
{
    if (!arial.loadFromFile("./Fonts/arial.ttf"))
        std::cout<<"fallo al leer la fuente "<<std::endl;
}
