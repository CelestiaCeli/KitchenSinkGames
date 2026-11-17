#include "../lib/Update.h"
#include "../lib/initInfo.h"

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

struct InitInfo Updater::Init(InitInfo initInfo)
{
	return initInfo;
}


bool Updater::Update()
{
	glfwPollEvents();


	return true;
}
