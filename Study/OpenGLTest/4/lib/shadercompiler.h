#pragma once
#ifndef __SHADERCOMPILER_H__
#define __SHADERCOMPILER_H__
#include <string>
#include <vector>

#include "log.h"
#include "object.h"
#include "shader.h"

class ShaderCompiler : public Object
{
	
	//All shaders available for use in project

	protected:
		bool IInit() override;
		std::vector<Shader> shaders;

	public:
		bool RecompileShaders();
};

#endif

