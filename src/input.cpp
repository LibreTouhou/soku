#include <iostream>
#include <algorithm>

#include "input.hpp"

bool Input::key_pressed_buffer[GLFW_KEY_LAST];
bool Input::key_down_buffer[GLFW_KEY_LAST];
int Input::combo_buffer[10];

int Input::combo_index = 0;
float Input::last_update = 0;

void Input::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
		key_down_buffer[key] = key_pressed_buffer[key] = true;

	if (action == GLFW_RELEASE)
		key_down_buffer[key] = key_pressed_buffer[key] = false;
}

void Input::reset_combo_buffer()
{
	combo_index = 0;
	last_update = 0;
	for (size_t i = 0; i < 10; i++)
		combo_buffer[i] = GLFW_KEY_UNKNOWN;
}

void Input::initialize(GLFWwindow * window)
{
	window = window;
	glfwSetKeyCallback(window, key_callback);
	
	reset_combo_buffer();
	for (size_t i = 0; i < GLFW_KEY_LAST; i++)
	{
		key_down_buffer[i] = false;
		key_pressed_buffer[i] = false;
	}
}

void Input::update(float dt)
{
	if (last_update > 0.5f)
		reset_combo_buffer();

	if (key_pressed_buffer[GLFW_KEY_W])
	{
		combo_buffer[combo_index] = GLFW_KEY_W;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_A])
	{
		combo_buffer[combo_index] = GLFW_KEY_A;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_S])
	{
		combo_buffer[combo_index] = GLFW_KEY_S;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_D])
	{
		combo_buffer[combo_index] = GLFW_KEY_D;
		combo_index++;
	}

	if (key_pressed_buffer[GLFW_KEY_J])
	{
		combo_buffer[combo_index] = GLFW_KEY_J;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_K])
	{
		combo_buffer[combo_index] = GLFW_KEY_K;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_L])
	{
		combo_buffer[combo_index] = GLFW_KEY_L;
		combo_index++;
	}
	if (key_pressed_buffer[GLFW_KEY_SPACE])
	{
		combo_buffer[combo_index] = GLFW_KEY_SPACE;
		combo_index++;
	}

	if (combo_index > 1)
		last_update += dt;

	for (size_t i = 0; i < GLFW_KEY_LAST; i++)
		key_pressed_buffer[i] = false;

	std::cout << combo_index << '\n';
}

bool Input::is_236B()
{
	if (combo_buffer[0] != GLFW_KEY_S)
		return false;

	if (combo_buffer[1] != GLFW_KEY_D)
		return false;

	if (combo_buffer[2] != GLFW_KEY_K)
		return false;

	reset_combo_buffer();

	return true;
}

bool Input::is_623B()
{
	if (combo_buffer[0] != GLFW_KEY_D)
		return false;

	if (combo_buffer[1] != GLFW_KEY_S)
		return false;

	if (combo_buffer[2] != GLFW_KEY_D)
		return false;

	if (combo_buffer[3] != GLFW_KEY_K)
		return false;

	reset_combo_buffer();

	return true;
}
