#ifndef INPUT_HPP
#define INPUT_HPP

#include "time.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Input
{
private:
	static GLFWwindow* window;

	static bool key_pressed_buffer[GLFW_KEY_LAST];
	static bool key_down_buffer[GLFW_KEY_LAST];
	static int combo_buffer[10];

	static int combo_index;
	static float last_update;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
public:
	static void initialize(GLFWwindow* window);
	static void update(float dt);

	static bool is_236B();
	static bool is_623B();
};

#endif /* end of include guard: INPUT_HPP */
