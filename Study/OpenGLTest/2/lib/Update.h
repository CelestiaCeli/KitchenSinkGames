#pragma once
#ifndef __UPDATE_H__
#define __UPDATE_H__

#include "../lib/ext/glfw-src/deps/glad/gl.h"
#include "../lib/ext/glfw-src/include/GLFW/glfw3.h"
#include "initInfo.h"

class Updater
{
	public:
		bool Update();
		bool ProcessInput(GLFWwindow *window);
		struct InitInfo Init(InitInfo initInfo);
};
#endif
