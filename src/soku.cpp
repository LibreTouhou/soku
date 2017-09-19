#include "soku.hpp"

Soku::Soku()
{
}

void Soku::initialize(int argc, char * argv[])
{
	Game::initialize(argc, argv);

	Input::initialize(window);
}

void Soku::update()
{
	Game::update();

	Input::update(t.delta);

	if (Input::is_236B())
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	if (Input::is_623B())
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}

void Soku::draw()
{
	Game::draw();
}

void Soku::deinitialize()
{
	Game::deinitialize();
}
