#pragma once
#ifndef __RENDER_H__
#define __RENDER_H__

#include "ext/glfw-src/deps/glad/gl.h"
#include "ext/glfw-src/include/GLFW/glfw3.h"
#include <iostream>
#include "initInfo.h"

class Renderer
{
	const int WINDOW_HEIGHT = 800;
	const int WINDOW_WIDTH = 600;

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	unsigned int shaderProgram;
	bool CreateGLFWWindow(GLFWwindow* window);
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	unsigned int VertexShader();
	unsigned int Tesselator();
	GLfloat InputAssembler();
	unsigned int GeometryShader();
	unsigned int FragmentShader();
	unsigned int RenderConstructor(unsigned int vertexOutput, unsigned int tesselatorOutput, unsigned int geometryOutput, unsigned int fragmentOutput, GLfloat vertices);

	bool CompileShaders();

	public:
	Renderer() {}
	InitInfo Init(InitInfo initInfo);
	~Renderer() 
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteProgram(shaderProgram);
		glfwTerminate();
		delete window;
	}

	GLFWwindow* window;
	bool Render(GLFWwindow* window);
};

#endif
