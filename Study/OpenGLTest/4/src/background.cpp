#include "../lib/background.h"

bool Background::IUpdate()
{
  glfwPollEvents();
	if (glfwGetKey(focusedWindow->GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		currColor.x -= CHANGE_AMT;
	}
	if (glfwGetKey(focusedWindow->GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		currColor.x += CHANGE_AMT;
	}
	if (glfwGetKey(focusedWindow->GetWindow(), GLFW_KEY_E) == GLFW_PRESS)
	{
    if (button_pressed == false)
      {
        previousColor = currColor.y;
        currColor.y = colorModifier;
        button_pressed = true;
      }
    else
      {
        currColor.y = previousColor;
        button_pressed = false;
      }
	}
	return true;
}

bool Background::IRender()
{
	glClearColor(currColor.x, currColor.y, currColor.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return true;
}

bool Background::IInit()
{
	return true;
}
