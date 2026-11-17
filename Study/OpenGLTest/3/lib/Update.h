#pragma once
#ifndef UPDATE_H
#define UPDATE_H

#include "../lib/ext/glfw-src/deps/glad/gl.h"
#include "../lib/ext/glfw-src/include/GLFW/glfw3.h"

class Updater
{
	public:
		bool Update();
		bool ProcessInput(GLFWwindow *window);
};

#endif
