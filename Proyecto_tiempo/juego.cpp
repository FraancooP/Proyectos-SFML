#include "juego.h"
juego::juego(int alto, int ancho, std::string titulo) {
	fps = 60;
	ventana = new RenderWindow(VideoMode(ancho, alto), titulo);
	ventana->setFramerateLimit(fps);
    textura1 = new Texture;
    textura2 = new Texture;
    sprite1 = new Sprite;
    sprite2 = new Sprite;
    textura1->loadFromFile("imagen1.png");
    textura2->loadFromFile("personaje.png");
    sprite1->setTexture(*textura1);
    sprite2->setTexture(*textura2);
    sprite2->setPosition(400, 300);
    sprite1->setPosition(400, 300);
    //Posicionar imagen en centro:
    sprite1->setOrigin(sprite1->getTexture()->getSize().x / 2.f, sprite1->getTexture()->getSize().y / 2.f);
    sprite2->setOrigin(sprite2->getTexture()->getSize().x / 2.f, sprite2->getTexture()->getSize().y / 2.f);
	gameLoop();
}
void juego::gameLoop() {
	while (ventana->isOpen())
	{




        sprite1->setRotation(sprite1->getRotation());
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
    ventana->draw(*sprite2);
    ventana->display();
}