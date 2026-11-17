#include "../lib/shadercompiler.h"

bool ShaderCompiler::IInit()
{
	RecompileShaders();
	return true;
}

bool ShaderCompiler::RecompileShaders()
{
	try
	{
		for(int i = 0; i < shaders.size(); i++)
		{
			if (!shaders[i].Recompile()) { return false; }
		}
		return true;
	}
	catch(std::ifstream::failure e)
	{
		Logger::GetInstance().Log(LogType::WARNING, LogContent::ShaderCompiledFail);
		return false;
	}
}
