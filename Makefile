#=================================================================
# Makefile para chessito con soporte para winmm y recursos Windows

# Compilador (usar g++ de MinGW en Windows)
CXX = g++
RC  = windres
AR  = ar

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I. -Imisc -Imotor

# Bibliotecas a enlazar (-lwinmm es clave aquí)
LIBS = -lwinmm -lgdi32 -luser32 -lkernel32

# Archivo de salida
TARGET = chessito.exe  # .exe en Windows

# Fuentes principales
SOURCES := main.cpp \
           casilla.cpp convierte.cpp input.cpp movidasposibles.cpp \
           presentacion.cpp rey.cpp tablero.cpp tc.cpp turno.cpp valida.cpp \
           misc/adornos.cpp misc/elo.cpp misc/reloj.cpp \
           motor/bitboard.cpp motor/ia.cpp

# Objetos
OBJECTS := $(SOURCES:.cpp=.o)

# Recurso de Windows (Menú, iconos, etc.)
RC_OBJECT = Menuses.o

# Encabezados
HEADERS := $(wildcard *.h) $(wildcard misc/*.h) $(wildcard motor/*.h) decs.h

# --- Reglas ---

all: $(TARGET)

# Enlazar todo + winmm + recurso
$(TARGET): $(OBJECTS) $(RC_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compilar .cpp a .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar recurso .rc a .o
$(RC_OBJECT): Menuses.rc
	$(RC) $< $@

# Limpiar
clean:
	rm -f $(OBJECTS) $(RC_OBJECT) $(TARGET)
	# Limpieza adicional por si hay objetos sueltos
	find . -name "*.o" -delete 2>/dev/null || true

rebuild: clean all

.PHONY: all clean rebuild
