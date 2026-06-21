#include <iostream>
#include "Build/_deps/glfw-src/deps/glad/gl.h"
#include "Build/_deps/glfw-src/include/GLFW/glfw3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
struct InitInfo Init();
bool CreateGLFWWindow(GLFWwindow* window);
bool GameplayLoop(GLFWwindow* window);
int ERROR_CODE;

struct InitInfo
{
	public: 
		bool initStatus;
		GLFWwindow* window;
		int errorCode;
};

int main()
{
	InitInfo initInfo = Init();

	if (initInfo.initStatus == false) { return initInfo.errorCode; }
	
	GLFWwindow* window = initInfo.window;

	while(!glfwWindowShouldClose(window))
	{
		if (!GameplayLoop(window)) { break; }
	}
	
	glfwTerminate();
	return 0;
}

bool Update()
{
	glfwPollEvents();

	return true;
}

bool Render(GLFWwindow* window)
{
	glfwSwapBuffers(window);

	return true;
}

bool GameplayLoop(GLFWwindow* window)
{
	if (!Update()) { return false; }
	if (!Render(window)) { return false; }

	return true;
}

bool CreateGLFWWindow(GLFWwindow* window)
{
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	else 
	{
		std::cout << "Created GLFW window" << std::endl;
		return true;
	}

}

struct InitInfo Init()
{
	InitInfo initInfo;

	initInfo.initStatus = false;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (!CreateGLFWWindow(window))	{ return initInfo; }
	initInfo.window = window;

	glfwMakeContextCurrent(window);
	if (!gladLoadGL(glfwGetProcAddress)) { return initInfo; }

	glViewport(0, 0, 800, 600);
	std::cout << "Viewport Established" << std::endl; 
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	initInfo.initStatus = true;
	return initInfo;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}

