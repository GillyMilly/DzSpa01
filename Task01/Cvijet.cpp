#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace sf;

CircleShape Cvijet::drawShape(float size,int points, Vector2f position, float rotation, Vector2f scale, Color colorFill, float outline, Color colorOutline)
{
	CircleShape shape(size, points);

	shape.setPosition(position);
	shape.setRotation(degrees(rotation));
	shape.setScale(scale);
	shape.setFillColor(colorFill);
	shape.setOutlineThickness(outline);
	shape.setOutlineColor(colorOutline);

	return shape;
}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	//pokret
	Time time = clock.getElapsedTime();

	//ponovno pokretanje
	if (time.asSeconds() > 10)
	{
		clock.restart();
	}

	//Suceve zrake
	for (size_t i = 0; i < 20; i++)
	{
		CircleShape ray = drawShape
		(
			4.f, 3, { 580.f, 100.f }, 10.f * (2 * i), { 13.f, 3.f }, { 255, 204, 51 }
		);
		//animirana rotacija
		ray.rotate(degrees(20 * time.asSeconds()));
		window->draw(ray);
	}

	//Sunce
	window->draw(drawShape(
		50.f, 80, { 540.f, 50.f }, 5.f, { 1.f, 1.f }, { 255,204,51 }));
	
	//Petiljka
	window->draw(drawShape(
		8.f, 100, { 210.f, 350.f }, 1.f, { 1.f, 20.f }, { 250,205,50 }));


	//latice
	for (size_t i = 0; i < 30; i++)
	{
		window->draw(drawShape(
			14.f, 3, { 218.f, 316.f }, 8.f * (8 * i), { 1.f, 4.f }, { 0, 156, 128 }
		));
	}

	//latice 2
	for (size_t i = 0; i < 15; i++)
	{
		window->draw(drawShape(
			4.f, 10, { 218.f, 316.f }, 5.f * (5 * i), { 4.f, 8.f }, { 240, 250, 200 }
		));
	}

	
	//Tucak
	window->draw(drawShape(
		40.f, 10.f, { 181.f, 279.f }, 4.f, { 1.f, 1.f }, { 250,205,50 }));
}
