#pragma once
#ifndef __INITINFO_H__
#define __INITINFO_H__
#include "../lib/ext/glfw-src/include/GLFW/glfw3.h"
struct InitInfo
{
	public: 
		bool initStatus;
		GLFWwindow* window;
		int errorCode;
};

#endif
