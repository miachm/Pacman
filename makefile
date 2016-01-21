WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = 
CFLAGS = -std=c++11 -Wall
RESINC = 
LIBDIR = 
LIB = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = 

INC_DEBUG = $(INC) -Iinclude -ISRC -ISRC/
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = RemakeComecocos-Debug

INC_RELEASE = $(INC) -Iinclude -ISRC -ISRC/
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = RemakeComecocos

OBJ_DEBUG = $(OBJDIR_DEBUG)/SRC/Tablero.o $(OBJDIR_DEBUG)/SRC/FantasmaRosa.o $(OBJDIR_DEBUG)/SRC/Pacman.o $(OBJDIR_DEBUG)/SRC/Personaje.o $(OBJDIR_DEBUG)/SRC/Puntuacion.o $(OBJDIR_DEBUG)/SRC/main.o $(OBJDIR_DEBUG)/SRC/Estado.o $(OBJDIR_DEBUG)/SRC/AlmacenDeFuentes.o $(OBJDIR_DEBUG)/SRC/AlmacenDeGraficos.o $(OBJDIR_DEBUG)/SRC/AlmacenDeSonido.o $(OBJDIR_DEBUG)/SRC/Fantasma.o $(OBJDIR_DEBUG)/SRC/FantasmaAmarillo.o $(OBJDIR_DEBUG)/SRC/FantasmaAzul.o $(OBJDIR_DEBUG)/SRC/FantasmaRojo.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/SRC/Tablero.o $(OBJDIR_RELEASE)/SRC/FantasmaRosa.o $(OBJDIR_RELEASE)/SRC/Pacman.o $(OBJDIR_RELEASE)/SRC/Personaje.o $(OBJDIR_RELEASE)/SRC/Puntuacion.o $(OBJDIR_RELEASE)/SRC/main.o $(OBJDIR_RELEASE)/SRC/Estado.o $(OBJDIR_RELEASE)/SRC/AlmacenDeFuentes.o $(OBJDIR_RELEASE)/SRC/AlmacenDeGraficos.o $(OBJDIR_RELEASE)/SRC/AlmacenDeSonido.o $(OBJDIR_RELEASE)/SRC/Fantasma.o $(OBJDIR_RELEASE)/SRC/FantasmaAmarillo.o $(OBJDIR_RELEASE)/SRC/FantasmaAzul.o $(OBJDIR_RELEASE)/SRC/FantasmaRojo.o

all: release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/SRC || mkdir -p $(OBJDIR_DEBUG)/SRC

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/SRC/Tablero.o: SRC/Tablero.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Tablero.cpp -o $(OBJDIR_DEBUG)/SRC/Tablero.o

$(OBJDIR_DEBUG)/SRC/FantasmaRosa.o: SRC/FantasmaRosa.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/FantasmaRosa.cpp -o $(OBJDIR_DEBUG)/SRC/FantasmaRosa.o

$(OBJDIR_DEBUG)/SRC/Pacman.o: SRC/Pacman.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Pacman.cpp -o $(OBJDIR_DEBUG)/SRC/Pacman.o

$(OBJDIR_DEBUG)/SRC/Personaje.o: SRC/Personaje.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Personaje.cpp -o $(OBJDIR_DEBUG)/SRC/Personaje.o

$(OBJDIR_DEBUG)/SRC/Puntuacion.o: SRC/Puntuacion.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Puntuacion.cpp -o $(OBJDIR_DEBUG)/SRC/Puntuacion.o

$(OBJDIR_DEBUG)/SRC/main.o: SRC/main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/main.cpp -o $(OBJDIR_DEBUG)/SRC/main.o

$(OBJDIR_DEBUG)/SRC/Estado.o: SRC/Estado.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Estado.cpp -o $(OBJDIR_DEBUG)/SRC/Estado.o

$(OBJDIR_DEBUG)/SRC/AlmacenDeFuentes.o: SRC/AlmacenDeFuentes.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/AlmacenDeFuentes.cpp -o $(OBJDIR_DEBUG)/SRC/AlmacenDeFuentes.o

$(OBJDIR_DEBUG)/SRC/AlmacenDeGraficos.o: SRC/AlmacenDeGraficos.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/AlmacenDeGraficos.cpp -o $(OBJDIR_DEBUG)/SRC/AlmacenDeGraficos.o

$(OBJDIR_DEBUG)/SRC/AlmacenDeSonido.o: SRC/AlmacenDeSonido.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/AlmacenDeSonido.cpp -o $(OBJDIR_DEBUG)/SRC/AlmacenDeSonido.o

$(OBJDIR_DEBUG)/SRC/Fantasma.o: SRC/Fantasma.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/Fantasma.cpp -o $(OBJDIR_DEBUG)/SRC/Fantasma.o

$(OBJDIR_DEBUG)/SRC/FantasmaAmarillo.o: SRC/FantasmaAmarillo.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/FantasmaAmarillo.cpp -o $(OBJDIR_DEBUG)/SRC/FantasmaAmarillo.o

$(OBJDIR_DEBUG)/SRC/FantasmaAzul.o: SRC/FantasmaAzul.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/FantasmaAzul.cpp -o $(OBJDIR_DEBUG)/SRC/FantasmaAzul.o

$(OBJDIR_DEBUG)/SRC/FantasmaRojo.o: SRC/FantasmaRojo.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SRC/FantasmaRojo.cpp -o $(OBJDIR_DEBUG)/SRC/FantasmaRojo.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/SRC

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/SRC || mkdir -p $(OBJDIR_RELEASE)/SRC

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/SRC/Tablero.o: SRC/Tablero.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Tablero.cpp -o $(OBJDIR_RELEASE)/SRC/Tablero.o

$(OBJDIR_RELEASE)/SRC/FantasmaRosa.o: SRC/FantasmaRosa.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/FantasmaRosa.cpp -o $(OBJDIR_RELEASE)/SRC/FantasmaRosa.o

$(OBJDIR_RELEASE)/SRC/Pacman.o: SRC/Pacman.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Pacman.cpp -o $(OBJDIR_RELEASE)/SRC/Pacman.o

$(OBJDIR_RELEASE)/SRC/Personaje.o: SRC/Personaje.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Personaje.cpp -o $(OBJDIR_RELEASE)/SRC/Personaje.o

$(OBJDIR_RELEASE)/SRC/Puntuacion.o: SRC/Puntuacion.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Puntuacion.cpp -o $(OBJDIR_RELEASE)/SRC/Puntuacion.o

$(OBJDIR_RELEASE)/SRC/main.o: SRC/main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/main.cpp -o $(OBJDIR_RELEASE)/SRC/main.o

$(OBJDIR_RELEASE)/SRC/Estado.o: SRC/Estado.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Estado.cpp -o $(OBJDIR_RELEASE)/SRC/Estado.o

$(OBJDIR_RELEASE)/SRC/AlmacenDeFuentes.o: SRC/AlmacenDeFuentes.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/AlmacenDeFuentes.cpp -o $(OBJDIR_RELEASE)/SRC/AlmacenDeFuentes.o

$(OBJDIR_RELEASE)/SRC/AlmacenDeGraficos.o: SRC/AlmacenDeGraficos.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/AlmacenDeGraficos.cpp -o $(OBJDIR_RELEASE)/SRC/AlmacenDeGraficos.o

$(OBJDIR_RELEASE)/SRC/AlmacenDeSonido.o: SRC/AlmacenDeSonido.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/AlmacenDeSonido.cpp -o $(OBJDIR_RELEASE)/SRC/AlmacenDeSonido.o

$(OBJDIR_RELEASE)/SRC/Fantasma.o: SRC/Fantasma.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/Fantasma.cpp -o $(OBJDIR_RELEASE)/SRC/Fantasma.o

$(OBJDIR_RELEASE)/SRC/FantasmaAmarillo.o: SRC/FantasmaAmarillo.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/FantasmaAmarillo.cpp -o $(OBJDIR_RELEASE)/SRC/FantasmaAmarillo.o

$(OBJDIR_RELEASE)/SRC/FantasmaAzul.o: SRC/FantasmaAzul.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/FantasmaAzul.cpp -o $(OBJDIR_RELEASE)/SRC/FantasmaAzul.o

$(OBJDIR_RELEASE)/SRC/FantasmaRojo.o: SRC/FantasmaRojo.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SRC/FantasmaRojo.cpp -o $(OBJDIR_RELEASE)/SRC/FantasmaRojo.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/SRC

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

