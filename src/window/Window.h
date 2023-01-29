#pragma once
#include <window/include.h>

#define CLEAR_COLOR ImVec4(0.15f, 0.15f, 0.15f, 1.00f)

class Window
{
private:
	const unsigned int WIDTH = 1920;
	const unsigned int HEIGHT = 1080;
	const std::string TITLE = "Softy";

    sf::RenderWindow window;

	ComponentHandler componentHandler;

public:
	Window();
	int init();
	void render();
   ~Window();
};

