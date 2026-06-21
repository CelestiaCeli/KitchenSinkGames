#include <iostream>
#include "Build/_deps/glfw-src/deps/glad/gl.h"
#include "Build/_deps/glfw-src/include/GLFW/glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	else 
	{
		std::cout << "Created GLFW window" << std::endl;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);

	glViewport(0, 0, 800, 600);
	std::cout << "Viewport Established" << std::endl; 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}
