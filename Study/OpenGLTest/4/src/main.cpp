
#include "../lib/ext/glfw-src/deps/glad/gl.h"
#include "../lib/ext/glfw-src/include/GLFW/glfw3.h"

#include "../lib/object.h"
#include "../lib/shadercompiler.h"
#include "../lib/triangle.h"
#include "../lib/background.h"
#include "../lib/window.h"

#include <vector>
#include <list>
#include <iostream>

bool Init();
bool Update(std::vector<Object*> list);
bool Render(std::vector<Object*> list);
bool GameplayLoop();

std::vector<Window*> windows;
std::vector<Object*> objects;

int main()
{
	if (Init())
	{
		try
		{
			while(!glfwWindowShouldClose(windows[0]->GetWindow()))
			{
				if (!GameplayLoop()) 
				{ 
					break;
				}
			}
		}
		catch(std::string error)
		{
			return 1;
		}
	}

	return 0;
}

bool Init()
{
	try
	{
		//List of all classes in the game
		windows.push_back(new Window(800, 600));
		Shape* testShape = new Shape({ 
					  Vector3(-0.5, -0.5, 0.0f),
					  Vector3(0.5f, -0.5f, 0.0f),
					  Vector3(0.0f, 0.5f, 0.0f)
				});
		
		testShape->shader.vertexPath = "../src/shaders/RGB.vs";
		testShape->shader.fragmentPath = "../src/shaders/RGB.fs";
    testShape->IInit();

		objects.push_back(testShape);
		objects.push_back(new Background(windows.back()));

		glfwSwapBuffers(windows.back()->GetWindow());
		return true;
	}
	catch(std::string error)
	{
		return false;
	}
}

bool Update(std::vector<Object*> list)
{
	//glfwPollEvents();
	//Window logic
	for(int i = 0; i < windows.size(); i++)
	{
		if (!windows[i]->IUpdate()) { return false; }
	}


	for(int i = 0; i < list.size(); i++)
	{
		list[i]->IUpdate();
	}
	return true;
}

bool Render(std::vector<Object*> list)
{
	for(int i = 0; i < list.size(); i++)
	{
		list[i]->IRender();
	}
	//Render Window !! MUST BE LAST.
	for(int i = 0; i < windows.size(); i++)
	{
		if (!windows[i]->IRender()) { return false; }
	}
	return true;
}

bool GameplayLoop()
{
	//Logic
	if (!Update(objects)) { return false; }
	//Render Objects
	if (!Render(objects)) { return false; }

	return true;
}
