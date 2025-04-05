#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	Clock clock;
	Time time;
	CircleShape shape, ray;

	CircleShape drawShape(float size, int points, Vector2f position, float rotation = 0.f, Vector2f scale = { 0.f,0.f }, Color colorFill = { 255,255,255 }, float outline = 0.f, Color colorOutline = { 0,0,0 });

public:
	Cvijet(RenderWindow* window);
	void draw();
};