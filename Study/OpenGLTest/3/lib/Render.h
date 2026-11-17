#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "../lib/ext/glfw-src/deps/glad/gl.h"
#include "../lib/ext/glfw-src/include/GLFW/glfw3.h"
#include <iostream>

class Renderer
{
	public:
	unsigned int VBO;
	unsigned int VAO;

	unsigned int VertexShader();
	unsigned int Tesselator();
	unsigned int GeometryShader();
	unsigned int FragmentShader();
	unsigned int CompileShaders();
	unsigned int RenderConstructor(
	unsigned int vertexOutput, 
	unsigned int tesselatorOutput, 
	unsigned int geometryOutput, 
	unsigned int fragmentOutput,
	GLfloat vertices
	);

		GLfloat InputAssembler();
		GLFWwindow* window;
		bool Render(GLFWwindow* window);
};

#endif
