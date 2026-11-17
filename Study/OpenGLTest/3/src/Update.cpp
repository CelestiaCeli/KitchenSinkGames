#include "../lib/Update.h"

bool Updater::ProcessInput(GLFWwindow *window)
{
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

bool Updater::Update()
{
	glfwPollEvents();


	return true;
}
