#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class juego {
public:
	juego(int ancho, int alto,std::string titulo);
	void gameLoop();
	void dibujar();
private:
	RenderWindow * ventana;
	int fps;
	Texture * textura1;
	Sprite * sprite1;
};