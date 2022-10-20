#include "juego.h"
juego::juego(int alto, int ancho, std::string titulo) {
	fps = 60;
	ventana = new RenderWindow(VideoMode(ancho, alto), titulo);
	ventana->setFramerateLimit(fps);
    textura1 = new Texture;
    sprite1 = new Sprite;
    textura1->loadFromFile("imagen1.png");
    sprite1->setTexture(*textura1);
    sprite1->setPosition(400, 300);
    sprite1->setOrigin(sprite1->getTexture()->getSize().x / 2.f, sprite1->getTexture()->getSize().y / 2.f);
	gameLoop();
}
void juego::gameLoop() {
	while (ventana->isOpen())
	{
        sprite1->setRotation(sprite1->getRotation() + 3);
		dibujar();
	}
}
void juego::dibujar() {
    sf::Event event;
    while (ventana->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            ventana->close();
    }
    ventana->clear(sf::Color::Black);
    ventana->draw(*sprite1);
    ventana->display();
}