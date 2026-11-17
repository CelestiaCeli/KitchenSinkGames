#pragma once
#ifndef __LOG_H__
#define __LOG_H__

//This has no reason to be a class imo
#include <ostream>
#include <string>

namespace LogType
{
	const std::string
		INFO = "[LOG] Info:",
		WARNING = "[LOG] Warning:",
		ERROR = "[LOG] ERROR:",
		NUM_LOGTYPE = "null";
	
};

namespace LogContent
{
	const std::string
		WindowRenderNULL = "Window Rendering did not work!",
		WindowUpdateNULL = "Window update did not work!",
		ShaderCompiledFail = "Shaders failed to compile!",
		SHADER_FRAGMENT = "SHADER FRAGMENT COMPILATION ERROR",
		SHADER_GEOMETRY = "SHADER GEOMETRY COMPILATION ERROR",
		SHADER_VERTEX = "SHADER FRAGMENT COMPILATION ERROR",
		SHADER_TESSELATOR = "SHADER FRAGMENT COMPILATION ERROR",
		SHADER_LINK = "SHADER LINKING DID NOT WORK",
		SHADER_COMPILE = "SHADER FAILED TO COMPILE",
		FILE_INVALID = "Couldn't read file input!",
		WINDOW_INIT_FAILED = "Couldn't intialize Window!",
		GLAD_INIT_FAILED = "Couldn't intialize GLAD.",
		NUM_LOGCONTENT = "null";
};

class Logger
{
	private:
		Logger() {}
	public:
		void Log(std::string type, std::string content);
		static Logger& GetInstance()
		{
			static Logger logger;
			return logger;
		}
};

#endif
