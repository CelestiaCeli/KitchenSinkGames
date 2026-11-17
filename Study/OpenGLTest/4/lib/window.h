#pragma once
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "ext/glfw-src/deps/glad/gl.h"
#include "ext/glfw-src/include/GLFW/glfw3.h"

#include "log.h"
#include "object.h"

#include <iostream>
#include <string>

class Window : public Object
{
	private:
    GLFWwindow* window;
		Window();
	protected:

		int WINDOW_HEIGHT = 800;
		int WINDOW_WIDTH = 600;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		bool CreateGLFWWindow(GLFWwindow* window);
	public:
		GLFWwindow* GetWindow();
		int viewport;
		Window(int _WINDOW_HEIGHT, int _WINDOW_WIDTH);
		~Window();
		bool IInit() override;
		bool IUpdate() override;
		bool IRender() override;

};

#endif
