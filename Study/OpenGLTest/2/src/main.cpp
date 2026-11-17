#include "../lib/ext/glfw-src/deps/glad/gl.h"

#include "../lib/initInfo.h"
#include "../lib/Update.h"
#include "../lib/Render.h"

#include <iostream>

struct Pipeline
{
	Updater* updater;
	Renderer* renderer;
	Pipeline()
	{
		updater = new Updater();
		renderer = new Renderer();
	}
};

struct InitInfo Init();
bool GameplayLoop(Pipeline* pipeline, GLFWwindow* window);
Pipeline* SpawnPipeline();
unsigned int CreateBuffer();
struct InitInfo Init(Pipeline* pipeline);
int ERROR_CODE;

int main()
{
	Pipeline* pipeline = SpawnPipeline();
	InitInfo initInfo = Init(pipeline);
	if (initInfo.initStatus == false) { 
		return initInfo.errorCode; }

	while(!glfwWindowShouldClose(pipeline->renderer->window))
	{
		if (!GameplayLoop(pipeline, pipeline->renderer->window)) { break; }
	}

	delete pipeline->updater;
	delete pipeline->renderer;
	delete pipeline;
	
	return 0;
}

bool GameplayLoop(Pipeline* pipeline, GLFWwindow* window)
{
	//input
	if (!pipeline->updater->ProcessInput(pipeline->renderer->window)) { return true; }

	if (glfwGetKey(pipeline->renderer->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		return false;
	}
	//logic
	if (!pipeline->updater->Update()) { return false; }
	//render
	if (!pipeline->renderer->Render(pipeline->renderer->window)) { return true; }


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

unsigned int CreateBuffer()
{
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	return VBO;
}


InitInfo MainInit(InitInfo initInfo)
{
	initInfo.initStatus = false;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return initInfo;
}

Pipeline* SpawnPipeline()
{
	Pipeline* pipeline = new Pipeline();
	return pipeline;
}

struct InitInfo Init(Pipeline* pipeline)
{
	InitInfo initInfo;

	initInfo = MainInit(initInfo);

	initInfo = pipeline->updater->Init(initInfo);
	initInfo = pipeline->renderer->Init(initInfo);

	return initInfo;
}
