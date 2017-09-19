#ifndef SOKU_HPP
#define SOKU_HPP

#include "game.hpp"
#include "input.hpp"

class Soku
	: public Game
{
	std::unique_ptr<Input> input;
public:
	Soku();

	virtual void initialize(int argc, char *argv[]) override;
	virtual void update() override;
	virtual void draw() override;
	virtual void deinitialize() override;
};

#endif /* SOKU_HPP */