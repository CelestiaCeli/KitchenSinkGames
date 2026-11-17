#include "../lib/window.h"

bool Window::IRender()
{
	try
	{
		glfwSwapBuffers(window);
		return true;
	}
	catch(const char* error)
	{
		Logger::GetInstance().Log(LogType::ERROR, LogContent::WindowRenderNULL);
		std::cout << error << std::endl;
		return false;
	}
}

GLFWwindow* Window::GetWindow()
{
	return window;
}

bool Window::IUpdate()
{
  glfwPollEvents();
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		return false;
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
	}
	return true;
}

Window::Window(int _WINDOW_HEIGHT, int _WINDOW_WIDTH)
{
	WINDOW_HEIGHT = _WINDOW_HEIGHT;
	WINDOW_WIDTH = _WINDOW_WIDTH;
	if (!IInit())
	{
		std::cout << "Startup failed" << std::endl;
	}
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}

bool Window::IInit()
{
	if (!glfwInit())
	{
		std::cout << "GLFW Init Failed";
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

	if(window == NULL)
	{
		Logger::GetInstance().Log(LogType::ERROR, LogContent::WINDOW_INIT_FAILED);
		glfwTerminate();
		std::cout << "Test1" << std::endl;
		return false;
	}
	else
	{
		/*
		if (!CreateGLFWWindow(window))	
		{ 
			Logger::GetInstance().Log(LogType::ERROR, LogContent::WINDOW_INIT_FAILED);

			return false; 

		}
		*/
/*
		glfwMakeContextCurrent(window);
		if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) 
		{
			Logger::GetInstance().Log(LogType::ERROR, LogContent::GLAD_INIT_FAILED);
			return false;
		}
		*/
		glfwMakeContextCurrent(window);

		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) 
		{
			Logger::GetInstance().Log(LogType::ERROR, LogContent::GLAD_INIT_FAILED);
			return false;
		}
	}
	return true;
}
